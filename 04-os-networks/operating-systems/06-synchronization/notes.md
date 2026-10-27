# Unit 6 — Process Synchronization

## The problem
When concurrent threads/processes access shared data, the result depends on the interleaving — a
**race condition**. The section of code touching shared data is the **critical section**.

## Critical section requirements
1. **Mutual exclusion** — at most one in the critical section.
2. **Progress** — if no one is in it, a waiting process can enter.
3. **Bounded waiting** — no starvation.

## Tools
- **Mutex (lock)** — one holder at a time. `pthread_mutex_lock/unlock`.
- **Semaphore** — an integer with atomic `wait` (P, down) and `signal` (V, up). Binary (0/1) = mutex;
  counting = manage N resources.
- **Condition variable** — wait for a condition while holding a mutex (`pthread_cond_wait/signal`).

## Classic problems
- **Producer–Consumer (bounded buffer)** — a producer fills, a consumer empties a fixed buffer; use a
  mutex plus two conditions (`not_full`, `not_empty`). (`producer_consumer.c`)
- **Readers–Writers** — many readers OR one writer; a read/write lock. (`reader_writer.c`)
- **Dining Philosophers** — five philosophers, five forks; naive "pick left then right" deadlocks, so
  break the cycle (one picks up in the reverse order). (`dining_philosophers.c`)

## Race vs no race
A 4-thread `counter++` loop loses updates without a lock (`race_condition.c` prints < expected); with a
mutex it is exact (`mutex_demo.c`).

## Solved
**1. Binary semaphore vs mutex?** Both give mutual exclusion; a mutex has an owner (only the locker
unlocks), a semaphore doesn't and can also count resources.
**2. Why does the naive dining-philosophers deadlock?** Every philosopher holds one fork and waits for
the other — a circular wait. Breaking the symmetry removes it.
