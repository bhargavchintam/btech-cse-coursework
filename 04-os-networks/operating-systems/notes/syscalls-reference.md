# Unix system calls — quick reference

## Process
| Call | Purpose |
|---|---|
| `fork()` | create a child process |
| `execlp/execvp/execv` | replace the process image |
| `wait(&st)` / `waitpid(pid,&st,opt)` | wait for a child, get status |
| `exit(n)` / `_exit(n)` | terminate (with / without stdio flush + atexit) |
| `getpid()` / `getppid()` | own / parent pid |

Status macros: `WIFEXITED(st)`, `WEXITSTATUS(st)`, `WIFSIGNALED(st)`.

## Signals
| Call | Purpose |
|---|---|
| `signal(sig, fn)` | set a handler (simple) |
| `sigaction(sig,&act,&old)` | set a handler (reliable) |
| `kill(pid, sig)` / `raise(sig)` | send a signal |
| `alarm(sec)` / `pause()` | timer / wait for a signal |

## Files
`open`, `read`, `write`, `close`, `lseek`, `stat/fstat`, `dup/dup2`, `mkfifo`.

## IPC
| Call | Mechanism |
|---|---|
| `pipe(fd)` | anonymous pipe |
| `mkfifo(path,mode)` | named pipe |
| `shmget/shmat/shmdt/shmctl` | shared memory |
| `msgget/msgsnd/msgrcv/msgctl` | message queue |
| `semget/semop/semctl` | semaphore |
| `sem_open/sem_wait/sem_post/sem_close` | POSIX named semaphore |

## Threads (link -lpthread)
`pthread_create`, `pthread_join`, `pthread_exit`, `pthread_mutex_lock/unlock`,
`pthread_cond_wait/signal`, `pthread_rwlock_rdlock/wrlock`.

> On macOS `sem_init` (unnamed POSIX semaphores) is unsupported — use System V semaphores or `sem_open`.
