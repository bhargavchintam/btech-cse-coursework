# Unit 3 — Signals

## What a signal is
An asynchronous software interrupt delivered to a process to notify it of an event (a key press,
a timer, a fault, a request from another process).

## Common signals
| Signal | Meaning | Default |
|---|---|---|
| SIGINT | interrupt (Ctrl+C) | terminate |
| SIGTERM | polite terminate | terminate |
| SIGKILL | forced kill (can't be caught) | terminate |
| SIGSTOP | stop (can't be caught) | stop |
| SIGSEGV | invalid memory access | terminate + core |
| SIGALRM | timer (`alarm`) expired | terminate |
| SIGCHLD | a child stopped/terminated | ignore |
| SIGUSR1/2 | user-defined | terminate |

## Handling a signal
Three choices: **default** action, **ignore** (`SIG_IGN`), or **catch** with a handler.
`SIGKILL` and `SIGSTOP` can be neither caught nor ignored.

## API
- `signal(sig, handler)` — simple, historically inconsistent.
- `sigaction(sig, &act, &old)` — reliable, preferred; controls the mask and flags.
- `kill(pid, sig)` — send a signal; `raise(sig)` — send to self.
- `alarm(sec)` — schedule a SIGALRM; `pause()` — wait for any signal.

## Solved
**1. Can you catch SIGKILL?** No — it always terminates the process; that's how you kill a runaway.
**2. `signal` vs `sigaction`?** `sigaction` is reliable and portable and lets you set the signal mask;
prefer it.
