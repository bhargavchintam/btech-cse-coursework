# Unit 7 — Transactions

A **transaction** is a single logical unit of work — a sequence of read/write operations
that takes the database from one consistent state to another. The textbook example is a
bank transfer: debit one account, credit another. Both happen or neither does. Halfway
through is not allowed.

The operations are `read(X)` and `write(X)` (X from disk to buffer / buffer back), plus
`COMMIT` and `ROLLBACK`. A transfer of 10000 from A to B is:

```
read(A); A = A - 10000; write(A);
read(B); B = B + 10000; write(B);
commit;
```

If the system crashes between `write(A)` and `write(B)`, 10000 has vanished. Stopping exactly
this is the whole point of transaction management.

## ACID properties

The four guarantees a DBMS gives every transaction. For each, what breaks if it is missing:

- **Atomicity** — all operations execute or none do. *Without it:* a crash after debiting A
  but before crediting B leaves the money nowhere. Recovery uses the log to UNDO a partial txn.
- **Consistency** — moves the DB from one valid state to another; constraints hold at the end.
  *Without it:* `A + B` is not preserved, a balance goes negative, a foreign key dangles.
- **Isolation** — concurrent transactions do not see each other's uncommitted state; the
  result equals *some* serial order. *Without it:* the anomalies below appear.
- **Durability** — once `COMMIT` returns, the change survives a crash. *Without it:* a committed
  transfer is lost on the next power failure. Ensured by write-ahead logging before commit.

> Sir's line: atomicity and durability are the recovery manager's job, isolation is the
> concurrency manager's job, and consistency follows from those three plus correctly
> written transactions.

## Transaction states

A transaction moves through five states.

```
   begin    +--------+  last op   +-----------+  flush   +-----------+
  --------->| active |----------->| partially |--------->| committed | (end)
            +--------+            | committed |          +-----------+
                |                 +-----------+
     error/fail |
                v
            +--------+  rollback (undo)  +---------+
            | failed |------------------>| aborted | (end: restart or kill)
            +--------+                   +---------+
```

- **Active** — executing operations.
- **Partially committed** — final operation done, changes still in buffers/log, not yet flushed.
- **Committed** — changes made permanent; durability now holds.
- **Failed** — normal execution can no longer proceed (constraint violation, crash, deadlock).
- **Aborted** — rolled back, DB restored to the pre-transaction state; may be restarted or killed.

## Why concurrency control — the anomalies

Serial execution is safe but wastes the CPU while a transaction waits on disk. Interleaving
raises throughput but, done blindly, produces four classic anomalies (each shown below as a
two-transaction schedule).

**Lost update** — two transactions read the same value and both write; one write overwrites
the other. Start `A = 100`.

```
    T1                 T2
  read(A)  -- 100
                     read(A)  -- 100
  A = A-10
  write(A) -- 90
                     A = A+20
                     write(A) -- 120   T1's update is lost; correct answer was 110
```

**Dirty read** (uncommitted read) — a transaction reads data another has written but not yet
committed, and the writer then aborts.

```
    T1                 T2
  write(A) -- 90 (uncommitted)
                     read(A)  -- reads 90
  rollback           ...      -- T2 acted on a value that never officially existed
```

**Unrepeatable read** — a transaction reads the same row twice and gets different values,
because another committed a write in between.

```
    T1                 T2
  read(A)  -- 100
                     write(A) -- 150
                     commit
  read(A)  -- 150    same query, different result inside one transaction
```

**Phantom** — a transaction re-runs a range query and a *new row* matching the condition has
appeared (or vanished) via another transaction's insert/delete. Unrepeatable read is one
existing row changing; a phantom is the *set of rows* changing.

```
    T1                          T2
  SELECT COUNT(*) WHERE deptno=20  -- 5
                             INSERT emp (... deptno=20); commit
  SELECT COUNT(*) WHERE deptno=20  -- 6   a phantom row appeared
```

## Schedules and serializability

A **schedule** is an ordering of the operations of a set of transactions that preserves the
order within each transaction.

- **Serial schedule** — transactions run one after another with no interleaving. Always
  correct, but no concurrency.
- **Concurrent (interleaved) schedule** — operations are interleaved. Acceptable *only if* its
  effect equals that of *some* serial order of the same transactions — then it is
  **serializable**. Serializability is the correctness criterion for concurrent execution.

## Conflict serializability — the precedence-graph method

Two operations **conflict** if they belong to different transactions, act on the same data
item, and at least one is a `write` (so read-write, write-read, write-write conflict; two
reads never do). A schedule is **conflict-serializable** if it can be turned into a serial
schedule by swapping only *non-conflicting* adjacent operations. The test is the
**precedence (serialization) graph**:

1. One node per transaction.
2. Draw an edge Ti → Tj if an operation of Ti conflicts with a *later* operation of Tj and Ti's
   comes first (Ti must precede Tj in any equivalent serial order).
3. The schedule is conflict-serializable **iff the graph has no cycle**. A topological sort of
   the graph gives an equivalent serial order.

### Worked example

Schedule S, three transactions over data items A and B (time flows downward):

```
   T1          T2          T3
              r(A)
   r(B)
              w(A)
                          r(A)
   w(B)
              r(B)
                          w(A)
              w(B)
```

Operation order: r2(A) r1(B) w2(A) r3(A) w1(B) r2(B) w3(A) w2(B)

Find the conflicts, item by item:

- **Item A** (touched only by T2 and T3): w2(A) precedes r3(A) and w3(A); r2(A) precedes
  w3(A). All point the same way → edge **T2 → T3**.
- **Item B** (touched only by T1 and T2): w1(B) precedes r2(B) and w2(B); r1(B) precedes
  w2(B) → edge **T1 → T2**.
- **T1 vs T3**: no common data item, so no edge.

Precedence graph:

```
   T1  --->  T2  --->  T3
```

No cycle, so **S is conflict-serializable**. Topological sort gives the equivalent serial
order **⟨ T1, T2, T3 ⟩** — running T1 fully, then T2, then T3 produces the same final state.

## View serializability

A weaker, more permissive notion. Schedules S and S' are **view-equivalent** if, for every
data item: (1) the same transaction reads the initial value, (2) each read reads the value
written by the same transaction in both, and (3) the same transaction does the final write.
A schedule is **view-serializable** if it is view-equivalent to a serial schedule.

Every conflict-serializable schedule is view-serializable, not the reverse — the extra cases
have **blind writes** (a write not preceded by a read of that item). Testing view-
serializability is NP-hard, so engines enforce conflict-serializability (a cheap graph check).

## Recoverability

Serializability is correctness under concurrency; recoverability is correctness under failure
— whether a rollback can leave committed transactions inconsistent.

- **Recoverable schedule** — if Tj reads a value written by Ti, then Tj commits *only after*
  Ti commits. A non-recoverable schedule can commit a transaction that read dirty data and
  then abort the writer — impossible to undo cleanly.
- **Cascadeless (avoids cascading rollback)** — a transaction reads a value only *after* the
  transaction that wrote it has committed. This prevents one abort from forcing a chain of
  other rollbacks. Every cascadeless schedule is recoverable.
- **Strict** — no transaction may read *or write* an item until the transaction that last
  wrote it has committed or aborted. Strict schedules make UNDO simple (just restore the
  before-image) and are what most systems aim for.

Containment: **strict ⊂ cascadeless ⊂ recoverable**.

## TCL — COMMIT, ROLLBACK, SAVEPOINT

Transaction Control Language in SQL:

- `COMMIT` — make all changes since the transaction began permanent.
- `ROLLBACK` — undo all changes since the transaction began (or since a savepoint).
- `SAVEPOINT name` — mark an intermediate point; `ROLLBACK TO name` undoes back to it while
  keeping the transaction (and everything before the savepoint) alive.

With `autocommit = 0`, `START TRANSACTION` opens a block that ends only at `COMMIT` or
`ROLLBACK`. The SAVEPOINT block from `transactions.sql`, entered with balances Ravi 40000,
Anita 40000, Suresh 20000 (already committed a 10000 Ravi→Anita transfer earlier in the run):

```
START TRANSACTION;
  UPDATE accounts SET balance = balance - 5000 WHERE acc_no = 101;  -- Ravi   -> 35000
  UPDATE accounts SET balance = balance + 5000 WHERE acc_no = 103;  -- Suresh -> 25000
SAVEPOINT sp1;
  UPDATE accounts SET balance = balance - 3000 WHERE acc_no = 101;  -- Ravi   -> 32000
  UPDATE accounts SET balance = balance + 3000 WHERE acc_no = 102;  -- Anita  -> 43000
ROLLBACK TO sp1;   -- discards the 3000 transfer; the 5000 one stays
COMMIT;
```

`ROLLBACK TO sp1` undoes only the two updates after the savepoint, so the final balances are
**Ravi 35000, Anita 40000, Suresh 25000** — total unchanged at 100000.

## Solved problems

**1. Is this schedule conflict-serializable?** `S: r1(A) r2(A) w1(A) w2(A)` (start A=100).

Conflicts on A: r1(A) before w2(A) → T1→T2; r2(A) before w1(A) → T2→T1; w1(A) before w2(A)
→ T1→T2. Graph has edges T1→T2 **and** T2→T1.
**Ans:** the graph has a cycle T1→T2→T1, so S is **not conflict-serializable**. (It is exactly
the lost-update pattern.)

**2. Identify the anomaly.**
`S: w1(A) ; r2(A) ; w2(A) ; commit2 ; abort1`

T2 reads A while T1 has written it but not committed, then T1 aborts.
**Ans:** a **dirty read** (T2 read uncommitted data). Worse, T2 *committed* before T1 aborted,
so the schedule is also **non-recoverable** — there is no way to undo T1 without violating
T2's already-committed result.

**3. Test this schedule and give an equivalent serial order.**

```
   T1        T2        T3
  r(A)
            r(B)
  w(A)
            w(B)
                      r(A)
                      r(B)
                      w(A)
```

Conflicts: on A, T1's w(A) precedes T3's r(A)/w(A) and r1(A) precedes w3(A) → **T1→T3**; on B,
T2's w(B) precedes T3's r(B) → **T2→T3**. T1 and T2 share no item.
Graph: T1→T3, T2→T3 (two sources into T3), no cycle.
**Ans:** **conflict-serializable**; both **⟨T1, T2, T3⟩** and **⟨T2, T1, T3⟩** are valid
equivalent serial orders (T1 and T2 are unordered relative to each other; T3 must be last).
