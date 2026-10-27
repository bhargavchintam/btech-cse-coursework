# Unit 8 — Concurrency Control

Unit 7 said WHAT a good schedule is: conflict-serializable and recoverable. This unit is the
mechanism that forces the DBMS to actually produce such schedules when many transactions run at
once. The scheduler cannot just hope the interleaving comes out serializable — it has to constrain
the operations. Two families of methods: locking (pessimistic — block first) and timestamp ordering
(order by a stamp, abort if violated). The anomalies we are fighting (from unit 7): lost update,
dirty read, unrepeatable/phantom read.

## Lock-based protocols

A lock is a right to access a data item that a transaction requests from the **lock manager** before
it touches the item. Two modes:

- **Shared (S)** — read lock. Many transactions can hold S on the same item at once (reads don't
  conflict).
- **Exclusive (X)** — write lock. Only one transaction can hold X, and no one else may hold any lock
  on that item at the same time.

Operations: `lock-S(Q)`, `lock-X(Q)`, `unlock(Q)`. If the requested lock conflicts with one already
held, the requester waits in a queue until it is released.

### Lock-compatibility matrix

```
                       a lock is already held in mode
                     none      S         X
   request S(Q)  ->  grant    grant     wait
   request X(Q)  ->  grant    wait      wait
```

Only S with S is compatible. Everything involving X blocks. This is exactly the conflict rule
(read-read ok; read-write, write-read, write-write conflict) enforced with locks.

Locking on its own does **not** guarantee serializability — you can lock, unlock, and re-lock in a
way that still produces a non-serializable schedule. You need a *protocol* on top of it.

## Two-phase locking (2PL)

The rule: every transaction acquires and releases locks in **two phases**.

- **Growing phase** — the transaction may acquire locks but may not release any.
- **Shrinking phase** — the transaction may release locks but may not acquire any new one.

The instant it releases its first lock, it has entered the shrinking phase and can never lock again.
The moment it holds its last (maximum) set of locks is its **lock point**.

```
   locks
   held |           ___________            <- lock point (peak)
        |          /           \
        |         /             \
        |________/               \________  time
             growing phase | shrinking phase
```

**Theorem:** if every transaction follows 2PL, the schedule is conflict-serializable, and the
serialization order is the order of the transactions' lock points. This is the whole reason 2PL
matters — it is a simple local rule (each transaction watches only its own locking) that gives a
global guarantee.

But basic 2PL has two problems:

1. **It can deadlock.** T1 locks A then wants B; T2 locks B then wants A. Both obey 2PL, both wait
   forever. 2PL prevents non-serializability, not deadlock.
2. **Cascading rollback.** A transaction may release a lock while it is still uncommitted; another
   transaction reads that value; then the first aborts, so the second must abort too, and so on.

> Sir hammered this: 2PL guarantees serializability, it does NOT guarantee freedom from deadlock or
> from cascading aborts. Two different questions. Exam trap every year.

### Strict 2PL and rigorous 2PL

- **Strict 2PL** — all **exclusive (write) locks** are held until the transaction commits or aborts.
  S locks may still be released early. Because no one can read or overwrite an item this transaction
  has written until it commits, no other transaction ever reads uncommitted data → **no cascading
  rollback**, and the schedule is recoverable. This is what most real systems use.
- **Rigorous 2PL** — all locks, **both S and X**, are held until commit/abort. Simpler to reason
  about: transactions serialize in the order they commit. Slightly less concurrency than strict.

What strict/rigorous fix over basic 2PL: cascading rollback and recoverability. What they do **not**
fix: deadlock is still possible.

## Cascading rollback (why strict 2PL is worth it)

```
   T1: ... write(A) ..................... abort
   T2:            read(A) ... write(B)          <- read dirty A
   T3:                     read(B)               <- read dirty B
```

Under basic 2PL, T1 could release its X(A) lock before committing; T2 reads the uncommitted A. When
T1 aborts, T2 must be rolled back, and T3 with it. One abort cascades into three. Strict 2PL forbids
releasing X(A) before commit, so T2 could never have read it.

## Timestamp-ordering (TO) protocol

No locks at all. Each transaction Ti gets a unique **timestamp TS(Ti)** when it starts (older
transaction = smaller timestamp). The protocol forces the schedule to be equivalent to the *serial
order of the timestamps*. Each data item Q keeps two values:

- **W-timestamp(Q)** — the largest timestamp of any transaction that successfully wrote Q.
- **R-timestamp(Q)** — the largest timestamp of any transaction that successfully read Q.

**read(Q) by Ti:**
- if `TS(Ti) < W-timestamp(Q)`  → Ti is trying to read a value already overwritten by a *newer*
  transaction. **Reject**, roll back Ti (restart with a new, larger timestamp).
- else → allow the read; set `R-timestamp(Q) = max(R-timestamp(Q), TS(Ti))`.

**write(Q) by Ti:**
- if `TS(Ti) < R-timestamp(Q)`  → a newer transaction already read Q assuming Ti's value would never
  appear. **Reject**, roll back Ti.
- else if `TS(Ti) < W-timestamp(Q)` → Ti is writing an obsolete value. **Reject**, roll back Ti.
- else → allow the write; set `W-timestamp(Q) = TS(Ti)`.

Worked example. TS(T1)=1, TS(T2)=2. Item B starts with R-TS=0, W-TS=0.

```
   step  op            check                              result
   1     T1 read(B)    1 >= W-TS(0)  ok                   R-TS(B)=1
   2     T2 read(B)    2 >= W-TS(0)  ok                   R-TS(B)=2
   3     T2 write(B)   2 >= R-TS(2), 2 >= W-TS(0)  ok      W-TS(B)=2
   4     T1 write(B)   1 <  R-TS(B)=2  -> REJECT           T1 rolled back
```

T1's write at step 4 loses: a newer transaction (T2) already read B, so letting old T1 overwrite it
would break the timestamp order. T1 restarts with a fresh larger timestamp.

TO is **deadlock-free** (nobody ever waits — a conflict causes an abort, not a wait), but it can
**starve** a long transaction that keeps getting rolled back, and basic TO can produce
non-recoverable schedules unless combined with commit-deferral.

### Thomas's write rule

Relax the middle write case: if `TS(Ti) < W-timestamp(Q)` (Ti's write is obsolete) but
`TS(Ti) >= R-timestamp(Q)`, do not abort Ti — simply **ignore** the write. A newer value already
exists and nobody needs Ti's older one. This allows more concurrency and yields view-serializable
schedules that basic TO would have rejected.

## Deadlock

A deadlock is a cycle of transactions each waiting for a lock the next one holds. None can proceed.

### Detection — wait-for graph

Build a graph with one node per active transaction and an edge **Ti → Tj** whenever Ti is waiting
for a lock held by Tj. The system has a deadlock **iff the wait-for graph has a cycle**.

Worked example:

```
   T1 holds X(A), requests B
   T2 holds X(B), requests C
   T3 holds X(C), requests A

   wait-for graph:   T1 --> T2 --> T3 --> T1
```

T1→T2 (T1 wants B held by T2), T2→T3 (wants C held by T3), T3→T1 (wants A held by T1). The cycle
T1→T2→T3→T1 means deadlock. The DBMS picks a **victim** to roll back — usually the one that has done
the least work / holds the fewest locks (say T3) — releases its locks, and the cycle breaks. A
deadlock exists whenever the graph has *any* cycle, not only one through a particular transaction:
if T3 had instead requested a free item D (held by nobody), it would just acquire it, finish and
release C, letting T2 then T1 proceed — no cycle, no deadlock.

### Prevention — wait-die and wound-wait

Both use timestamps and the principle *older transactions have priority, and a restarted
transaction keeps its old timestamp so it eventually becomes oldest and cannot starve.* Suppose Ti
requests an item held by Tj.

- **Wait-die (non-preemptive):**
  - TS(Ti) < TS(Tj)  (Ti older) → Ti **waits**.
  - TS(Ti) > TS(Tj)  (Ti younger) → Ti **dies** (rolls back, restarts later with same TS).
  - Mnemonic: *older waits, younger dies.* Only an older requester is allowed to wait.

- **Wound-wait (preemptive):**
  - TS(Ti) < TS(Tj)  (Ti older) → Ti **wounds** Tj: Tj is rolled back, Ti takes the item.
  - TS(Ti) > TS(Tj)  (Ti younger) → Ti **waits**.
  - Mnemonic: *older wounds younger, younger waits.*

```
                 requester older than holder     requester younger than holder
   wait-die      requester WAITS                 requester DIES (rolls back)
   wound-wait    requester WOUNDS the holder      requester WAITS
```

Both are deadlock-free (waits always run one timestamp direction, so no cycle forms). Wait-die rolls
back more often (a young one may die repeatedly); wound-wait fewer but preempts a running holder.

### Timeouts

Cheapest scheme: a transaction that waits past a set timeout is assumed deadlocked and rolled back —
no graph needed. Too short aborts healthy transactions, too long lets real deadlocks sit.

## SQL isolation levels

SQL lets a transaction trade consistency for concurrency by choosing how isolated it is. Four
standard levels, defined by which anomaly they permit:

```
   isolation level     dirty read   non-repeatable read   phantom read
   READ UNCOMMITTED     possible      possible              possible
   READ COMMITTED       no            possible              possible
   REPEATABLE READ      no            no                    possible
   SERIALIZABLE         no            no                    no
```

- **Dirty read** — reading data another transaction wrote but has not committed.
- **Non-repeatable read** — reading the same row twice and getting different values because another
  transaction updated it in between.
- **Phantom read** — re-running the same `WHERE` and getting extra/fewer *rows* because another
  transaction inserted/deleted matching rows.

Set it per session or per transaction:

```sql
SET SESSION TRANSACTION ISOLATION LEVEL SERIALIZABLE;
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;   -- next txn only
SELECT @@transaction_isolation;
```

> Aside: the table above is the ANSI SQL standard. MySQL/InnoDB is stricter than the standard at
> REPEATABLE READ — its MVCC + next-key locks actually block phantoms too — but for the exam quote
> the standard table. InnoDB's default is REPEATABLE READ.

## Solved problems

**1. Is this locking schedule allowed under 2PL?**

```
   T1: lock-S(A); read(A); unlock(A); lock-X(B); read(B); write(B); unlock(B);
```

**Ans:** No. T1 releases the lock on A (`unlock(A)`) and *then* acquires a new lock `lock-X(B)`.
Acquiring a lock after releasing one violates the two-phase rule — once you unlock, you are in the
shrinking phase and may not lock again. To make it legal, move the acquisition up:
`lock-S(A); lock-X(B); read(A); unlock(A); read(B); write(B); unlock(B);` — now all locks are
acquired before any is released.

**2. Wait-die vs wound-wait outcome.**

Timestamps TS(T1)=10, TS(T2)=20, TS(T3)=25 (smaller = older). T2 currently holds a lock on item Q.
Give the outcome when (i) T1 requests Q, and (ii) T3 requests Q, under each scheme.

**Ans:**
- Wait-die: (i) T1 (older, 10<20) → **T1 waits**. (ii) T3 (younger, 25>20) → **T3 dies**, rolls
  back and restarts later keeping TS=25.
- Wound-wait: (i) T1 (older) → **T1 wounds T2**; T2 is rolled back and T1 takes Q. (ii) T3 (younger)
  → **T3 waits**.

**3. Which isolation level?**

A nightly banking report runs several `SELECT`s and its subtotals must add up to the same grand
total, even though other transactions keep committing new deposit rows while the report runs. No
uncommitted data may be seen. Which isolation level?

**Ans:** **SERIALIZABLE**. The report must see no dirty reads, no changed values on re-read
(non-repeatable), and — the deciding factor — no *new rows* appearing between its queries (phantoms).
REPEATABLE READ would still permit those phantom deposit rows under the standard, so it is not enough;
only SERIALIZABLE forbids all three. (If the report only needed committed data and could tolerate
slightly shifting values, READ COMMITTED would give better concurrency.)
