# Virtualization

Virtualization is the trick the whole cloud stands on. One physical server pretends to be several
independent machines, each with its own OS, isolated from the others. A layer called the hypervisor
sits between the hardware and those virtual machines, hands each VM a slice of CPU/RAM/disk, and keeps
them from stepping on each other. This is what lets a provider pool one big datacenter and rent it out
in slices (the resource pooling from 01-introduction).

## Hypervisor - type 1 vs type 2

The hypervisor (VMM, virtual machine monitor) is the program that creates and runs VMs. Two kinds,
and this is a favourite exam question.

- type 1 (bare-metal) - runs directly on the hardware, no host OS under it. It IS the OS, more or
  less. Fast, used in production datacenters. Examples: VMware ESXi, Xen, KVM, Hyper-V.
- type 2 (hosted) - runs as an ordinary application on top of a normal OS (Windows/Linux). Easier to
  install on your laptop, slower because there's a full OS in the way. Examples: VirtualBox, VMware
  Workstation, QEMU on its own.

| | type 1 | type 2 |
|---|---|---|
| runs on | bare hardware | a host OS |
| speed | near-native | slower, extra layer |
| use | servers, cloud | desktop, testing |
| example | ESXi, Xen, KVM | VirtualBox, Workstation |

I ran VirtualBox (type 2) for the lab VM in lab/, but AWS/ESXi underneath the real cloud is type 1.

## Full vs para vs hardware-assisted

How the hypervisor deals with the guest OS trying to run privileged instructions.

- full virtualization - the guest OS is untouched and thinks it's on real hardware. The hypervisor
  traps and emulates the privileged instructions (binary translation). Guest needs no changes, but
  the trapping costs something.
- paravirtualization - the guest OS is modified to know it's a guest and makes hypercalls to the
  hypervisor instead of privileged instructions. Faster, but you need a patched kernel (classic Xen).
- hardware-assisted - the CPU itself helps (Intel VT-x, AMD-V). The chip has a guest mode, so traps
  are cheap and the guest stays unmodified. This is what everything uses now (KVM leans on it).

So the progression is full (slow, no guest changes) -> para (fast, needs guest changes) -> hardware-
assisted (fast, no guest changes, needs the CPU feature). Modern setups are basically all the last one.

## VM vs container

Both isolate workloads, but at different levels, and mixing them up cost me marks once.

| | virtual machine | container |
|---|---|---|
| isolates | whole machine + OS | just the process/app |
| includes | its own guest OS kernel | shares the host kernel |
| size | GBs | MBs |
| boot | tens of seconds | ~instant |
| overhead | a full OS each | almost none |
| example | VirtualBox, EC2 | Docker, LXC |

A VM virtualizes hardware and boots a full guest OS. A container virtualizes the OS - many containers
share one host kernel and just get isolated namespaces + cgroups. Containers are lighter and pack
denser, VMs isolate harder (separate kernels). More on containers in 08-containers-orchestration.

## Live migration

Moving a running VM from one host to another with (almost) no downtime. Copy the VM's memory pages to
the destination while it keeps running, re-copy the pages that changed (dirty pages), then at the last
moment pause it for a few ms, ship the final state, and resume it on the new host. Used to drain a
host for maintenance or to relieve an overloaded one - 02_vm_migration.py moves the biggest VMs off a
host that's over 80% until it drops back under.

## Overcommit

Because VMs rarely use everything they ask for, the hypervisor lets you allocate more virtual
resources than physically exist. Overcommit ratio = total virtual / total physical.

- CPU overcommit is usually safe - cores time-share, an idle vCPU costs nothing. 2:1 or 3:1 is normal.
- RAM overcommit is the dangerous one. Memory can't be time-shared the same way; if the VMs actually
  touch all the pages you promised, the host swaps to disk and everything crawls (or the OOM killer
  fires). 03_overcommit.py computes both ratios and flags RAM over 1:1.

## Benefits

Server consolidation (fewer physical boxes, less power/space), isolation (one VM crashing doesn't
take the others), snapshots and cloning, easy migration for maintenance, and the elasticity that makes
cloud possible - spin a VM up in seconds, tear it down when done. The placement/packing that decides
which host a VM lands on is bin-packing, same greedy heuristics as the DSA repo, in 01_vm_placement.py.
