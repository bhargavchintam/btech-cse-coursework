# Unit 5 — Threads

## What a thread is
A single flow of execution within a process. Threads of one process **share** the code, data, heap and
open files, but each has its own **stack, registers and program counter**.

## Process vs thread
| | Process | Thread |
|---|---|---|
| Address space | own | shared |
| Creation cost | high (fork) | low |
| Communication | IPC needed | shared memory (direct) |
| A crash | isolated | can take down the whole process |

## User vs kernel threads
- **User-level** — managed by a library, kernel unaware; fast, but one blocking call blocks all.
- **Kernel-level** — the kernel schedules them; a block affects only that thread, but more overhead.

## Multithreading models
Many-to-one, one-to-one (Linux/pthreads), many-to-many.

## pthreads API
| Call | Job |
|---|---|
| `pthread_create(&t, attr, fn, arg)` | start a thread |
| `pthread_join(t, &ret)` | wait for it, collect its return |
| `pthread_exit(ret)` | end the calling thread |
| `pthread_self()` | own thread id |

Compile with `-lpthread`.

## Solved
**1. What do threads of a process share?** Code, global/heap data and open files — not the stack or registers.
**2. Why are threads cheaper than processes?** No new address space is created; only a stack and registers.
