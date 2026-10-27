# Unit 9 — Deadlocks

## What a deadlock is
A set of processes each waiting for a resource held by another — none can proceed.

## Coffman conditions (all four must hold)
1. **Mutual exclusion** — a resource is held exclusively.
2. **Hold and wait** — hold one, wait for another.
3. **No preemption** — a resource is released only voluntarily.
4. **Circular wait** — a cycle of processes each waiting on the next.

## Handling deadlocks
- **Prevention** — deny one of the four conditions.
- **Avoidance** — stay in safe states (**Banker's algorithm**).
- **Detection & recovery** — let them happen, detect a cycle, then abort/preempt.
- **Ignore** (the ostrich) — what most OSes actually do.

## Banker's algorithm (avoidance)
Grant a request only if the resulting state is **safe** (there exists a sequence in which every process
can finish). Uses Allocation, Max, Need = Max − Allocation, and Available.
On the textbook example (5 processes, 3 resources) a safe sequence is **P1 P3 P4 P0 P2** (`bankers.cpp`).

## Detection
With single instances, a cycle in the wait-for graph = deadlock. With multiple instances, run a
detection sweep like `deadlock_detection.cpp` (work/finish, using Request instead of Need).

## Solved
**1. What is a safe state?** One where some ordering lets every process obtain its max need and finish;
a safe state is never deadlocked.
**2. Remove which condition to prevent circular wait?** Impose a total ordering on resources and require
requests in increasing order.
