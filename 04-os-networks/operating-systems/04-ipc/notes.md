# Unit 4 — Inter-Process Communication

Processes have separate address spaces, so they need the kernel's help to communicate.

## Pipes (anonymous)
A one-way byte stream between **related** processes (parent–child). `pipe(fd)` gives `fd[0]` (read)
and `fd[1]` (write). Half-duplex; for two-way you need two pipes.

## FIFO (named pipe)
A pipe with a name in the file system (`mkfifo`), so **unrelated** processes can use it. `open` blocks
until both a reader and a writer are present.

## System V IPC
| Mechanism | Create | Use |
|---|---|---|
| Shared memory | `shmget` | fastest — processes map the same segment (`shmat`) and read/write directly |
| Message queue | `msgget` | send/receive typed messages (`msgsnd`/`msgrcv`) |
| Semaphore | `semget` | synchronization, not data — `semop` for P/V |

Shared memory is the fastest (no copying through the kernel) but needs its own synchronization
(a semaphore). Message queues carry structured messages and are self-synchronizing.

## Comparison
- Pipe/FIFO: simple stream, kernel-buffered.
- Shared memory: fastest, but you must synchronize access yourself.
- Message queue: structured, decoupled sender/receiver.

## Solved
**1. Pipe vs FIFO?** A pipe is anonymous and only between related processes; a FIFO has a filesystem
name so unrelated processes can use it.
**2. Why is shared memory the fastest IPC?** Data isn't copied through the kernel — both processes
access the same physical memory directly.
