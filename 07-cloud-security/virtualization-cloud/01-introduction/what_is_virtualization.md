# What is Virtualization

**Definition:** Virtualization is the technique of creating a **virtual (not actual) version** of a resource — server, storage, network or OS — so that one physical machine can be split into many logical/isolated environments.

- The software layer that does this = **hypervisor** (also called **VMM — Virtual Machine Monitor**).
- Each isolated env running on top = **virtual machine (VM)** / guest.
- Physical machine underneath = **host**.

## Basic idea
- Normally 1 OS runs directly on 1 physical machine → hardware badly under-used (10-15% util only).
- Virt inserts a thin layer (hypervisor) between hardware and OS.
- That layer fools each guest OS into thinking it owns the full hardware.
- So multiple OS run side by side on same box, each in its own VM.

## What can be virtualized (imp)
- **Server / hardware** — one server → many VMs.
- **Storage** — many disks pooled and shown as one logical drive.
- **Network** — physical network split into VLANs / virtual switches.
- **Desktop** — user desktop hosted on server (VDI).
- **Application** — app packaged to run without install on host.
- **OS-level** — one kernel shared, many isolated user spaces (containers).

## Key terms
- **Host OS** — OS installed on physical machine.
- **Guest OS** — OS installed inside a VM.
- **Hypervisor / VMM** — creates and manages VMs, allots CPU/RAM/disk.
- **VM image** — file(s) holding a VM's disk + config.

## Simple analogy
One physical computer acting like **many separate computers**, each unaware of the others. Like partitions in a hostel room — one room, many curtained spaces, each tenant thinks it's private.

## Why it matters
- Better hardware use (run 10 VMs where 1 OS sat idle).
- Isolation — one VM crash does not touch the others.
- Easy to copy, move, snapshot a whole machine (it's just a file).

*(2 marks: Define virtualization + name the software layer = hypervisor/VMM.)*
