# Operating System and Unix Internals Lab

Two halves: Unix system programming in **C**, and the OS algorithm simulations in **C++**.

## Part A — Unix system programming (C)

Build with `cc file.c -o out` (add `-lpthread` for the thread programs).

### Processes (`02-process-management/`)
| Program | Shows |
|---|---|
| fork_basic.c | fork, parent/child pids |
| fork_multiple.c | n children in a loop |
| exec_demo.c | execlp replaces the image |
| wait_demo.c | collect a child's exit status |
| zombie.c | a defunct (zombie) child |
| orphan.c | reparenting to pid 1 |
| process_tree.c | nested fork; flush before fork |

### Signals (`03-signals/`)
signal_handler.c, sigaction_demo.c, alarm_demo.c, kill_demo.c, signal_ignore.c

### IPC (`04-ipc/`)
pipe_demo.c, fifo_writer.c + fifo_reader.c, shm_write.c + shm_read.c, msg_send.c + msg_receive.c
(run the reader/receiver, then the writer/sender).

### Threads (`05-threads/`)
thread_create.c, thread_args.c, thread_multiple.c, thread_sum.c (parallel sum of 1..100 = 5050)

### Synchronization (`06-synchronization/`)
| Program | Result |
|---|---|
| race_condition.c | counter < expected (lost updates) |
| mutex_demo.c | counter exact |
| producer_consumer.c | bounded buffer, mutex + condition variables |
| reader_writer.c | pthread rwlock |
| dining_philosophers.c | all 5 eat, no deadlock |
| semaphore_demo.c | mutual exclusion with a POSIX semaphore |

## Part B — OS algorithms (C++)

Build with `c++ -std=c++11 file.cpp -o out`. Each reads its input (pipe it in for a quick run).

### CPU scheduling (`07-cpu-scheduling/`)
fcfs.cpp (avg WT 17 for 24 3 3), sjf.cpp (avg WT 7 for 6 8 7 3), round_robin.cpp, priority.cpp

### Memory (`08-memory-management/`)
first_fit.cpp, best_fit.cpp, worst_fit.cpp, and page replacement:
fifo_page.cpp (15), lru_page.cpp (12), optimal_page.cpp (9) on the standard 20-reference string, 3 frames.

### Deadlock (`09-deadlock/`)
bankers.cpp (safe sequence P1 P3 P4 P0 P2 on the textbook example), deadlock_detection.cpp

### Disk scheduling (`10-disk-scheduling/`)
For queue 98 183 37 122 14 124 65 67, head 53:
fcfs_disk.cpp (640), sstf.cpp (236), scan.cpp (331), cscan.cpp (382), look.cpp (299)
