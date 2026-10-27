# Unit 10 — Disk Scheduling

## Why
A disk request costs **seek time** (move the head) + rotational latency + transfer. Scheduling the
queue to reduce total head movement improves throughput.

## Algorithms (queue 98 183 37 122 14 124 65 67, head 53, 200 cylinders)
| Algorithm | Idea | Head movement |
|---|---|---|
| **FCFS** | serve in arrival order | 640 |
| **SSTF** | nearest request first | 236 |
| **SCAN** | sweep to one end, then reverse (elevator) | 331 (up, to 199) |
| **C-SCAN** | sweep up, jump back to 0, sweep up again | 382 |
| **LOOK** | like SCAN but only to the last request, not the disk end | 299 |

SSTF beats FCFS but can starve far requests. SCAN/C-SCAN give more uniform waiting; C-SCAN is more
uniform than SCAN because it always sweeps the same direction.

## Solved
**1. FCFS total for the queue above?** 640 (`fcfs_disk.cpp`).
**2. SCAN vs LOOK?** SCAN goes all the way to the disk end before reversing; LOOK reverses at the last
request, so LOOK moves less (299 vs 331 here).
