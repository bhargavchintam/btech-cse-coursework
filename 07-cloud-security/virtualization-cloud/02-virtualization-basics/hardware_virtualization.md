# Hardware Virtualization

**Definition:** Hardware (server) virtualization = abstracting the **physical hardware** (CPU, memory, disk, I/O) so that multiple virtual machines, each with its own OS, run on a single physical machine.

- Also called **server virtualization** / **platform virtualization**.
- Done by the **hypervisor (VMM)**.

## How it works
- Hypervisor sits between hardware and VMs.
- It partitions physical resources (CPU cores, RAM, disk) and allots a share to each VM.
- Each VM gets **virtual hardware** — vCPU, virtual RAM, virtual disk, virtual NIC.
- Guest OS runs on this virtual hardware, unaware it is virtual.

## Components
- **Host machine** — the physical server.
- **Hypervisor / VMM** — creates and manages VMs.
- **Guest VMs** — each with own guest OS + apps.
- **Virtual hardware** — vCPU, vRAM, vDisk, vNIC per VM.

## Types of hypervisor (short — detailed in hypervisors.md)
- **Type 1 (bare-metal)** — runs directly on hardware. e.g. ESXi, Xen, Hyper-V, KVM.
- **Type 2 (hosted)** — runs on top of a host OS. e.g. VirtualBox, VMware Workstation.

## Techniques used
- **Full virtualization** — binary translation, guest unmodified.
- **Paravirtualization** — modified guest, hypercalls.
- **Hardware-assisted** — Intel **VT-x** / AMD **AMD-V** CPU extensions do the heavy lifting.

## Benefits
- Server consolidation, high utilization.
- Isolation between VMs.
- Easy backup/snapshot/migration.
- Run mixed OS (Linux + Windows) on one box.

## Challenges
- Hypervisor overhead (small performance cost).
- Single host failure affects all its VMs → need HA / clustering.
- Licensing + management complexity.

*(2 marks: What is hardware virtualization + name the layer that does it = hypervisor/VMM.)*
