# Unit 7 — CPU Scheduling

The scheduler picks which ready process runs next. Goal: maximize CPU use and throughput, minimize
waiting/turnaround/response time.

## Terms
- **Burst time (BT)** — CPU time a process needs.
- **Waiting time (WT)** — time spent in the ready queue.
- **Turnaround time (TAT)** — completion − arrival = WT + BT.

## Algorithms
| Algorithm | Idea | Note |
|---|---|---|
| **FCFS** | first come first served | simple; convoy effect |
| **SJF** | shortest job first | optimal avg WT; needs burst estimate; can starve long jobs |
| **Priority** | highest priority first | starvation → fix with aging |
| **Round Robin** | each gets a time quantum | fair, good response; quantum size matters |

Preemptive (SRTF, preemptive priority, RR) vs non-preemptive (FCFS, plain SJF).

## Worked (FCFS, BT = 24, 3, 3, all arrive at 0)
WT: P1=0, P2=24, P3=27 → **avg WT = 17**. TAT: 24, 27, 30 → **avg TAT = 27**.
The same jobs under SJF (`sjf.cpp`, BT 6 8 7 3) give **avg WT = 7**.

## Solved
**1. Which minimizes average waiting time?** SJF (provably optimal for a given set of jobs).
**2. RR quantum very large — behaves like?** FCFS. Very small → too many context switches (overhead).
