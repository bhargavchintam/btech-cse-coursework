# Exam prep — question bank

## Intro & processes
- OS functions and types (batch, time-sharing, real-time) (6)
- System call vs library function; user vs kernel mode (6)
- Process states and the PCB (6)
- fork / exec / wait — explain with a program (8)
- Zombie vs orphan process (5)

## Signals & IPC
- What is a signal; how are signals handled (6)
- signal() vs sigaction() (5)
- Pipes vs FIFO vs shared memory vs message queue (8)
- Write a program: two processes communicating via shared memory / pipe (10)

## Threads & synchronization
- Process vs thread; user vs kernel threads (6)
- Multithreading models (5)
- Critical section problem and its three requirements (6)
- Semaphore, mutex, condition variable (6)
- Producer-consumer / readers-writers / dining philosophers (10)

## Scheduling
- FCFS / SJF / Priority / Round Robin with a Gantt chart, compute WT and TAT (10)
- Preemptive vs non-preemptive; convoy effect; starvation and aging (6)

## Memory
- First / best / worst fit; fragmentation (6)
- Paging and the page table; logical vs physical address (6)
- FIFO / LRU / Optimal page replacement — count faults (10)
- Belady's anomaly (4)

## Deadlock & disk
- Coffman conditions; prevention vs avoidance vs detection (8)
- Banker's algorithm — check a safe state (10)
- FCFS / SSTF / SCAN / C-SCAN / LOOK — head movement (8)
