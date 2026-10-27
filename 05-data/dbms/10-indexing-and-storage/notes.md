# Unit 10 — Indexing and Storage

Every query eventually comes down to one physical question: how many blocks must we read off
the disk to answer it? This unit is about the layer under SQL — how rows are laid out in files,
and the auxiliary structures (indexes, hash tables) that cut the number of block reads. The whole
subject is a cost game: disk access is thousands of times slower than memory, so a design that
turns 3000 block reads into 4 is the difference between a report finishing in seconds or minutes.

The unit of I/O is the **block** (page). The DBMS reads and writes whole blocks, never single
rows. So "cost" throughout is measured in *block accesses*, not in rows or CPU.

## File organization — how records sit in blocks

A relation is stored as a file of records spread over disk blocks. The **blocking factor**
`bfr = floor(block_size / record_size)` is how many records fit in one block; the file needs
`b = ceil(r / bfr)` blocks for `r` records. Three basic organizations:

- **Heap (unordered) file** — new records appended at the end. Insert is cheap (O(1): read the
  last block, add, write it back). But a search on any column is a **linear scan**: average `b/2`
  blocks for a value that exists, full `b` blocks to confirm one that doesn't or to fetch all
  matches. Delete leaves holes. Good when we mostly append and rarely search by key.
- **Sequential (ordered) file** — records kept sorted on an *ordering field*. A search on that
  field uses **binary search**: `ceil(log2 b)` blocks. Range queries and sorted output are almost
  free. The pain is insertion — keeping order means shifting records, so real systems leave an
  overflow area and merge it back periodically.
- **Hashed file** — a hash function `h(key)` maps a key to a bucket (block). Equality search is
  ~1 block access (compute the hash, read that bucket). But hashing destroys order, so range
  queries (`sal BETWEEN ...`) get no help at all, and overflow chains form when buckets fill.

> Sir's one-liner: ordered file is great for ranges, hashed file is great for equality, heap is
> great for neither but cheapest to load. Match the organization to the dominant query.

## What an index is, and the trade-off

An **index** is a separate, smaller file of `(search-key value, pointer)` entries kept in sorted
order (or in a tree/hash), pointing back to the data records. It works like the index at the back
of a textbook: sorted terms with page numbers, so you don't read the whole book. Because the index
is small and ordered, we binary-search *it* (few blocks), follow the pointer, and read one data
block — far fewer accesses than scanning the data file.

The trade-off, and this is the exam point: an index **speeds up reads but slows down writes**.
Every `INSERT`, `DELETE` and `UPDATE` of an indexed column must also update the index, and each
index costs disk space. So you index the columns you *search / join / order by* a lot, not every
column. An over-indexed table is slow to write and wastes space.

## Primary vs secondary, dense vs sparse

**Primary (clustering) index** — built on the field the data file is *physically ordered* by
(usually the primary key). Because the data is already sorted, the index can be **sparse**: one
entry per *block*, holding the first (anchor) key of that block. There can be only **one** primary
index per table, since a file can be physically sorted only one way.

**Secondary index** — built on a non-ordering field. The data is not sorted by this field, so the
index must be **dense**: one entry per *record* (you can't point at "the block where sal=30000 is"
because such rows are scattered). A table can have many secondary indexes. This is what a normal
`CREATE INDEX` builds.

```
   dense index (secondary)              sparse index (primary, on ordered file)
   key -> row                           block-anchor-key -> block
   7369 -> ......                       7369 -> [block 0: 7369,7499,7521,...]
   7499 -> ......                       7566 -> [block 1: 7566,7654,7698,...]
   7521 -> ......                       7788 -> [block 2: 7788,7839,7844,...]
   (one entry per record)               (one entry per block -> far fewer entries)
```

Sparse is smaller (fewer entries → fewer index blocks); dense can answer "does this key exist?"
without touching the data file, and is the only option when the file isn't ordered on that field.

## Single-level vs multilevel

If the index itself grows large, searching it is no longer cheap. A **multilevel index** treats
the index as just another sorted file and builds a sparse index *on top of it* — and again on top
of that — until the top level fits in one block. Each level shrinks by the index blocking factor,
so the height grows only logarithmically. A multilevel index that keeps itself balanced on inserts
and deletes is exactly a **B+ tree**, which is how real databases implement indexes.

## B-tree vs B+ tree

Both are balanced, multi-way search trees (a node holds many keys, so the tree is wide and shallow
— height ~ `log_p N`, meaning a search touches only a handful of blocks even for millions of rows).

The difference is where the data pointers live:

- **B-tree** — keys *and* their record pointers are stored in **every node**, internal and leaf.
  A search can stop early at an internal node. But internal nodes hold fewer keys (they carry data
  pointers too), so the tree is a little taller, and range scans are awkward — you have to walk up
  and down the tree.
- **B+ tree** — internal nodes hold **only keys** (as separators/guides); **all record pointers
  live in the leaves**. Every search travels the full height to a leaf. Crucially, the **leaves
  are chained in a linked list**, so a range query does one descent then walks the leaf chain
  left-to-right — no bouncing through the tree.

Why databases pick B+ trees: (1) internal nodes carry only keys → higher fan-out → shorter tree →
fewer block accesses; (2) linked leaves make `BETWEEN`, `ORDER BY`, `>` range scans efficient;
(3) every lookup costs the same (all data at leaf level), which is predictable.

```
   B+ tree, order 3 (each leaf up to 2 keys; internal node is a router)

                          [ 30 ]
                        /        \
                 [ 13 | 20 ]      [ 40 ]
                /     |    \       /     \
             (5,13) (13,20)(20,30)(30,40)(40,50)   <- leaves, chained -->
              |------|------|------|------|
              leaf level is one linked list: scan a range by walking right
```

**Search** (find 30): start at root, 30 is not < 30 so go right subtree; at `[40]`, 30 < 40 so go
left leaf `(30,40)`; scan the leaf, find 30. Height-many block reads, here 3.
**Insert** (add 25): route to the leaf that should hold it `(20,30)`; it has room → just insert,
giving `(20,25,30)`... if that overflows the leaf's capacity, **split** it in two, push a copy of
the middle separator key up into the parent. If the parent overflows, it splits too, and a split
can propagate to the root — that is the only way a B+ tree grows taller, which keeps it balanced.

## Hashing — static vs dynamic

**Static hashing** — a fixed number of buckets `M`, address = `h(key) mod M`. Fast equality lookup
(~1 access) but the bucket count is frozen at design time: too few and buckets overflow into chains
(searches degrade); too many and space is wasted. Bad for files that grow.

**Dynamic / extendible hashing** — the bucket count grows and shrinks with the data. It keeps a
**directory** addressed by the first `d` bits (the *global depth*) of `h(key)`. When a bucket
overflows, only that bucket splits and its **local depth** increases; the directory doubles only
when a bucket's local depth would exceed the global depth. So growth is incremental — no full
rehash of the file, unlike static hashing. This is what makes hashing usable for files whose size
isn't known up front.

## When an index helps — and when it hurts

An index is not always a win. The optimizer weighs it against a plain full scan:

- **Low selectivity kills it.** If a query matches a large fraction of the table, a secondary index
  makes it *slower*, not faster: for each match you random-seek from the index to a scattered data
  block, and many random seeks cost more than one sequential scan of the whole file. Rule of thumb:
  below roughly 5–10% selectivity, a **full table scan beats the index**. On our 14-row `emp` this
  is why `EXPLAIN ... WHERE deptno = 30` may still show a full scan — the table is so small the
  index saves nothing.
- **Writes pay for every index** — each one is extra work on insert/update/delete.
- **Leading-column rule** — a composite index on `(a, b)` helps `WHERE a=...` and
  `WHERE a=... AND b=...`, but **not** `WHERE b=...` alone (b isn't the leftmost key).
- **Covering index** — if the index holds *every* column the query needs, the answer comes from the
  index alone and the data file is never touched (`EXPLAIN` shows `Using index`).

> Exam trap: "add an index" is not automatically the fix for a slow query. If the predicate isn't
> selective, the index is dead weight. Index selective columns you filter/join on.

## A note on query processing — join methods

Before running a query the DBMS builds a plan; the interesting cost is usually the **join**. Two
common physical algorithms:

- **Nested-loop join** — for each row of the outer table, scan the inner table for matches. Cost
  ~ `b_outer + (r_outer × b_inner)`. Terrible if both are large, but if the inner join column is
  **indexed**, the inner scan becomes an index lookup (an *index nested-loop join*) and it's cheap.
- **Hash join** — build a hash table on the join key of the smaller table in memory, then scan the
  larger table once, probing the hash for matches. Roughly `b_build + b_probe` — one pass over each
  — and excellent for large equijoins, but it works only for **equality** joins and needs memory
  for the hash table. (A third, sort-merge join, sorts both inputs on the key then merges; good when
  inputs are already sorted or a range join is needed.)

The optimizer estimates the cost of each using table sizes and index statistics and picks the
cheapest — which is why `EXPLAIN` is the tool for seeing what it actually chose.

## Solved problems

**1. Block accesses: heap vs ordered vs primary index.**
A file has `r = 30000` records, record size `R = 100` bytes, block size `B = 1024` bytes.
Find the blocking factor, number of blocks, and the search cost for (a) linear search on a heap
file, (b) binary search on a file ordered by the key, (c) a primary index whose entry is 15 bytes.

**Ans:**
- `bfr = floor(1024/100) = 10` records/block; `b = ceil(30000/10) = 3000` blocks.
- (a) Heap, linear search: average `b/2 = 1500` block accesses (worst case 3000).
- (b) Ordered, binary search: `ceil(log2 3000) = ceil(11.55) = 12` block accesses.
- (c) Primary (sparse) index: one entry per block → 3000 entries. Index blocking factor
  `bfri = floor(1024/15) = 68`; index blocks `bi = ceil(3000/68) = 45`. Binary-search the index
  `ceil(log2 45) = 6`, then 1 read of the data block → **7** accesses. Index turns 1500 into 7.

**2. B+ tree height / why it's shallow.**
A B+ tree indexes `N = 1,000,000` keys; each node (one block) holds up to 100 pointers. Roughly how
many block accesses does an equality search cost?

**Ans:** Fan-out ~100, so height `h ≈ ceil(log_100 1,000,000) = 3`. A search follows root → internal
→ leaf, about **3–4 block accesses** for a million rows. That shallowness — height grows as
`log_(fanout) N` — is the whole reason B+ trees, not binary trees, index databases.

**3. Which column to index?**
On `emp` (14 rows) the app runs `SELECT ... WHERE ename = ?` constantly (ename unique) and, rarely,
`SELECT ... WHERE job = 'CLERK'`. Which column deserves the index?

**Ans:** **ename.** It is queried often and is highly selective — an equality match on a unique
column returns exactly one row, the ideal case for an index (our `EXPLAIN` shows `type=const`,
1 row). `job` is queried rarely and has few distinct values (low selectivity, ~4 CLERKs of 14), so
an index on it earns little and a full scan is fine. Index the frequent, selective predicate.
