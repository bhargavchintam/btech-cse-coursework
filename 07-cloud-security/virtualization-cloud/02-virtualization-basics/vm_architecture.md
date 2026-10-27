# Virtual Machine Architecture

**Definition:** A **virtual machine (VM)** is a software-based emulation of a physical computer that runs its own OS and apps, isolated from other VMs, on top of a hypervisor.

## Layered architecture (bottom to top) — imp, draw it
```
+-----------------------------------+
|  App | App    App | App           |   <- applications
+-----------------------------------+
| Guest OS   |  Guest OS            |   <- each VM has its own OS
+-----------------------------------+
|      Virtual Hardware (per VM)     |   <- vCPU, vRAM, vDisk, vNIC
+-----------------------------------+
|        Hypervisor / VMM            |   <- creates + manages VMs
+-----------------------------------+
|      Physical Hardware (Host)      |   <- CPU, RAM, disk, NIC
+-----------------------------------+
```
(For Type 2, insert a **Host OS** layer between hardware and hypervisor.)

## Components
- **Physical hardware (host)** — real CPU, memory, storage, network.
- **Hypervisor / VMM** — the manager; allots + isolates resources.
- **Virtual hardware** — vCPU, virtual RAM, virtual disk, virtual NIC given to each VM.
- **Guest OS** — OS installed inside each VM.
- **Applications** — run on the guest OS.

## VM files (a VM = just files)
- **Disk image** — virtual hard disk (.vmdk VMware, .vdi VirtualBox, .qcow2 KVM/QEMU).
- **Config file** — VM settings (RAM, CPU count, NIC).
- Because it's files → easy to **copy, move, snapshot, backup**.

## Ring / privilege point (short)
- OS normally runs in **ring 0** (most privileged).
- With virt, hypervisor takes ring 0; guest OS is de-privileged.
- This mismatch is what full/para/hardware-assisted virt solve.

## Properties of a VM (imp)
- **Isolation** — VMs separated; one crash doesn't affect others.
- **Encapsulation** — whole VM captured as files.
- **Hardware independence** — VM can run on any host with a compatible hypervisor.
- **Partitioning** — one host's resources split among many VMs.

## Types of VM (brief)
- **System VM** — emulates a full machine, runs a complete OS (what we mostly mean).
- **Process VM** — runs a single program in a platform-independent env. e.g. **JVM**.

*(Q: Draw and explain VM architecture → the 5-layer diagram + component list.)*
