# Task scheduling in the cloud

A cloud has a pile of tasks (cloudlets, jobs, requests) and a pool of VMs to run them on. Scheduling is
deciding the order tasks run in and which VM each one lands on. Get it wrong and half your VMs sit idle
while a queue builds up on the other half. Get it right and everything finishes sooner for the same
hardware, which is the same as spending less money.

Two flavours show up in this folder:

- queueing on one VM - the classic OS scheduling problem (FCFS, SJF, round robin, priority). Tasks share
  one CPU and we care about waiting/turnaround time. This is exactly the CPU scheduling from an OS course,
  just relabelled - the space-shared VM in 07-cloud-simulation runs its cloudlets this way.
- mapping tasks to many VMs - Min-Min, Max-Min. Now the question is which VM, not what order, and the
  number we chase is makespan.

## Metrics

| metric           | meaning                                                        |
|------------------|----------------------------------------------------------------|
| completion time  | clock time a task finishes                                     |
| turnaround (tat) | completion - arrival. how long the task was in the system      |
| waiting time     | turnaround - burst. time spent waiting, not running            |
| makespan         | completion of the LAST task = max completion time              |
| throughput       | tasks finished per unit time                                   |
| utilisation      | fraction of VM time actually doing work, not idle              |

With every task arriving at time 0 (the assumption in these files) turnaround is just the completion time
and waiting is turnaround minus the burst. Averages are over all tasks. Makespan is the one that matters
once there are several VMs - a good mapping keeps all the VMs finishing at about the same time.

## The single-VM algorithms

Burst times [6, 8, 7, 3] for t0..t3 all through, so the numbers line up across files.

- FCFS - run them in arrival order, no reordering. Simple and fair but a long task at the front makes
  everyone behind it wait (convoy effect). avg waiting 10.25.
- SJF - shortest burst first. Provably the best average waiting time for a fixed batch. Here it drops to
  7.00. Catch: you need to know the burst up front, and long tasks can starve.
- Round robin - each task gets a time quantum q then goes to the back of the queue. Fair, no starvation,
  good for interactive/shared VMs. q=4 here gives avg waiting 13.25 - RR trades a worse average for
  responsiveness. Small q = more context switches, big q = drifts back towards FCFS.
- Priority - lowest priority number goes first. avg waiting 9.00 with the priorities I picked. Low-priority
  tasks can starve; real systems age them to fix that.

The queue in RR is the deque from the DSA repo, and SJF/priority are really just a sort (a heap if tasks
keep arriving). Nothing new, just cloud names on old data structures.

## Min-Min and Max-Min

These map a whole batch of tasks onto several VMs. You start from a completion-time matrix: entry [task][vm]
is how long that task takes on that VM. Each VM has a ready time that grows as you pile work on it.

Both are greedy and both loop the same way:
1. for every unmapped task, find its minimum completion time over the VMs (ready + exec, pick the best VM).
2. Min-Min picks the task with the smallest of those minima; Max-Min picks the one with the largest.
3. assign that task to its best VM, bump that VM's ready time, drop the task, repeat.

- Min-Min schedules the quick tasks first. They finish fast but the big tasks get left till the end and
  land on whatever VM, often stretching the makespan.
- Max-Min schedules the big tasks first so they run alongside the small ones instead of after them. When
  there's one long task in a crowd of short ones this wins.

The matrix in 05/06 has one heavy task t0 and four light ones. Min-Min defers t0 and finishes at makespan
16; Max-Min places t0 first and the small tasks fill in around it for makespan 10, with all three VMs
landing exactly on 10. Neither is always better - Max-Min helps with a skewed workload, Min-Min can win
when tasks are all similar.

> Min-Min for throughput on uniform work, Max-Min when one big job would otherwise wreck the makespan.
> Know which shape of workload you have.  -- lab notes

Mixed the two selection rules up in the internal - wrote "pick the max" for Min-Min. It's Min-Min = min of
the minima, Max-Min = max of the minima. The inner step (each task's best VM) is a min in both.

## Files

- 01_fcfs.py         - first come first served, completion/waiting/turnaround + averages
- 02_sjf.py          - shortest job first, non-preemptive
- 03_round_robin.py  - round robin with a quantum, prints the schedule
- 04_priority.py     - priority scheduling, lower number first
- 05_min_min.py      - Min-Min task-to-VM mapping, makespan 16
- 06_max_min.py      - Max-Min on the same matrix, makespan 10
