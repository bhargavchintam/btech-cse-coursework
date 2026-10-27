# Unit 2 — Process Management

## Process
A program in execution. More than the code — it has the program counter, registers, stack, data, and
its state. Program = passive (on disk); process = active.

## Process Control Block (PCB)
Per-process kernel structure: pid, process state, program counter, CPU registers, memory limits,
open files, scheduling info. The context switch saves/restores it.

## Process states
```
new -> ready -> running -> terminated
          ^        |
          |        v
        waiting <--+   (on I/O or event)
```
- **ready** — waiting for the CPU
- **running** — on the CPU
- **waiting/blocked** — waiting for I/O or an event

## The system calls
| Call | Job |
|---|---|
| `fork()` | create a child; returns 0 in child, child's pid in parent |
| `exec()` | replace the process image with a new program |
| `wait()` | parent blocks until a child ends, collects its status |
| `exit()` | terminate the process, return a status |
| `getpid()/getppid()` | own / parent pid |

## Zombie and orphan
- **Zombie** — child has exited but the parent hasn't `wait`ed, so its entry lingers (defunct).
- **Orphan** — parent exits first; the child is reparented to `init`/`launchd` (pid 1).

`fork` returns twice; buffered stdout is duplicated to the child, so `fflush` before `fork` avoids
duplicated output (see `process_tree.c`).

## Solved
**1. What does `fork()` return?** 0 to the child, the child's pid to the parent, −1 on failure.
**2. How to avoid a zombie?** The parent must `wait()`/`waitpid()`, or handle `SIGCHLD`.
