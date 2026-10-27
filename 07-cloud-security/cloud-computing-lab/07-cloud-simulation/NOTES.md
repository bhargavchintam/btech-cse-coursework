# Cloud simulation

Before you put a scheduling or placement policy on a real cloud you want to know if it's any good,
and you can't keep spinning up EC2 fleets to find out - it costs money and takes ages to set up.
So you simulate. Build a model of the datacenter in memory, feed it a workload, run the policy,
read off the numbers. CloudSim (the Java toolkit) is the standard one; here I built a tiny version
of it in Python to actually understand the pieces instead of just calling a library.

## The model

CloudSim layers the world like this:

- datacenter - the whole facility. Owns a set of hosts and a VM allocation policy.
- host - a physical machine. Has a MIPS rating, some cores (PEs), RAM. Fixed capacity.
- VM - a virtual machine carved out of a host. Asks for mips/cores/ram; the host must have room.
- cloudlet - a task/job. Its size is a length in MI (million instructions). This is the unit of
  work that actually runs. In Hadoop terms it's closer to a map/reduce task (04-mapreduce-hadoop).
- broker - stands in for the user. Decides which cloudlet goes to which VM and submits them.
- VM allocation policy - datacenter side: which host a new VM lands on (first-fit, best-fit...).
- cloudlet scheduler - VM side: how a VM runs the cloudlets assigned to it.

So there are two scheduling questions and they sit at different layers. Placement (VMs -> hosts) is
the allocation policy. Execution (cloudlets -> CPU time on a VM) is the cloudlet scheduler. I mixed
these two up in the internal and lost marks, so writing it down: VM allocation is host packing,
cloudlet scheduling is CPU sharing.

## Cloudlet scheduler: space-shared vs time-shared

- space-shared: a VM runs one cloudlet at a time, to completion, then the next. Basically FCFS on
  the VM (the queueing side is in 05-scheduling). A cloudlet gets the full MIPS while it runs.
- time-shared: the VM splits its MIPS across every cloudlet it's holding, so they all progress
  together. As cloudlets finish, the survivors get a bigger slice.

Execution time of a cloudlet on a VM = length / mips. A 2000 MI cloudlet on a 1000 MIPS VM takes
2 seconds if it has the VM to itself. Under time-shared with one other cloudlet it only gets 500
MIPS, so it's slower until the other one clears. Total work is conserved either way - on a single
VM the makespan comes out the same, only the individual finish times shift around.

> Space-shared gives you clean batch behaviour, time-shared gives you fairness. Neither is "better",
> it depends what the workload cares about.  -- lab notes

## VM allocation policy

Placing VMs on hosts is a bin-packing problem (bins = hosts, items = VM mips demand).

- first-fit: put the VM on the first host with room. Fast, one pass down the list.
- best-fit: put it on the host with the least leftover room that still fits. Packs tighter.

Both are greedy and neither is optimal, but best-fit tends to leave fewer half-empty hosts, which
is exactly what the energy work in 05 wants. 03_vm_allocation_policy.py has an instance where
first-fit spreads the same six VMs over 3 hosts and best-fit fits them in 2 (both full).

## Metrics

| metric      | meaning                                              |
|-------------|------------------------------------------------------|
| makespan    | time the last cloudlet finishes (max finish time)    |
| cost        | usually VM up-time * a per-second rate, summed        |
| utilization | fraction of a host's capacity actually in use         |
| energy      | power (a function of utilization) * time              |

Makespan is the one that shows up most - it's just the max finish time across all cloudlets, so if
04 says the last cloudlet ends at 4.0 s then the makespan is 4.0 s. Cost here is deliberately
simple: a VM up for t seconds at rate r costs t*r, add them up. Utilization drives energy - an idle
host still burns power, which is the whole reason consolidation (05) saves anything.

## The files

- 01_datacenter.py          - hosts + VMs, allocate VMs to hosts, show remaining capacity
- 02_cloudlet_scheduling.py - space-shared vs time-shared finish times on a VM
- 03_vm_allocation_policy.py - first-fit vs best-fit, how many hosts each uses
- 04_cloud_sim.py           - end to end: broker -> VMs -> cloudlets, makespan + cost
- 05_energy_aware.py        - consolidate VMs, switch idle hosts off, energy before/after

All pure Python, standard library, no real CloudSim JAR - this is a from-scratch mini version. The
data structures (the queues, the greedy packing) are the same ones from the DSA repo, just wearing
cloud names.
