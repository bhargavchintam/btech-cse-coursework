# Hypervisors

**Definition:** A **hypervisor** (also **VMM — Virtual Machine Monitor**) is the software/firmware layer that **creates, runs and manages virtual machines**. It allocates hardware resources (CPU, RAM, disk, I/O) to each VM and keeps them isolated.

- VMM = hypervisor (same thing, remember this).

## Two types (imp — asked prev year)

### Type 1 — Bare-metal (native)
- Runs **directly on the physical hardware**, no host OS below it.
- Hypervisor itself acts like a thin OS.
- Better performance, more secure, used in data centres / production.
- e.g. **VMware ESXi, Microsoft Hyper-V, Xen, KVM**.

### Type 2 — Hosted
- Runs **on top of a host OS** (like an application).
- Host OS → hypervisor → guest VMs.
- Easier to install, used on desktops/laptops for testing.
- More overhead (extra host OS layer) → slower.
- e.g. **Oracle VirtualBox, VMware Workstation, VMware Player, QEMU**.

## Comparison table (imp — 5 marks)

| Point | Type 1 (Bare-metal) | Type 2 (Hosted) |
|-------|---------------------|-----------------|
| Runs on | Directly on hardware | On top of a host OS |
| Host OS needed | No | Yes |
| Performance | High (less overhead) | Lower (extra OS layer) |
| Security/isolation | Stronger | Weaker |
| Use case | Servers, data centres, production | Desktop, testing, labs |
| Setup | Complex | Easy |
| Examples | ESXi, Xen, Hyper-V, KVM | VirtualBox, VMware Workstation |

## Note on KVM (common doubt)
- **KVM** turns the Linux kernel itself into a Type 1 hypervisor → treated as bare-metal.
- Some call it a hybrid, but for exams: **KVM = Type 1**.

## Functions of a hypervisor
- Create / delete / start / stop VMs.
- Allocate + schedule CPU, memory, I/O.
- Isolate VMs from each other.
- Handle privileged instructions from guests.
- Support snapshots + live migration.

*(Q: Differentiate Type 1 and Type 2 hypervisor with examples → draw the table.)*
