# Virtualization in cloud

Virtualization is the **base technology** that makes cloud possible. Cloud = the service model; virt = the enabling tech underneath.

**Definition:** virtualization is creating a **virtual (not actual) version** of something — a server, storage device, OS or network — so that one physical resource can be shared as many logical ones.

## Why cloud needs virt
- **Resource pooling** (NIST characteristic) is achieved by virt — one big physical pool sliced into VMs.
- **Multi-tenancy** — many customers on same hardware, isolated by virt.
- **Elasticity** — spin VMs up/down fast because they're just software.
- **Better utilisation** — a bare server sits ~10-15% used; virt packs many VMs → higher use.
- **Isolation** — one VM crash/attack doesn't take the neighbour down.

## Hypervisor
Software layer that creates and runs VMs. Also called **VMM** (Virtual Machine Monitor).
- **Type 1 (bare-metal)** — runs directly on hardware. e.g. VMware ESXi, Xen, Microsoft Hyper-V, KVM. Used in datacenters/cloud.
- **Type 2 (hosted)** — runs on top of a host OS. e.g. VirtualBox, VMware Workstation. Used on desktops.

Cloud providers use **Type 1** for performance.

## Types of virtualization used in cloud
- **Server virt** — one physical server → many VMs. (most common in cloud)
- **Storage virt** — pool many storage devices, present as one.
- **Network virt** — VLANs, virtual switches, SDN.
- **Desktop virt** — VDI, deliver desktops from datacenter.
- **OS-level virt** — containers (Docker) — lighter than full VM.

## Virt vs cloud (differentiate — asked)

| Basis | Virtualization | Cloud computing |
|-------|----------------|-----------------|
| What | tech to make virtual resources | delivery of computing as a service |
| Scope | one machine / datacenter | whole service model over network |
| Relation | enabler | built on top of virt |
| Example | VMware ESXi, KVM | AWS, Azure |

One-liner for the exam: *every cloud uses virtualization, but not every use of virtualization is a cloud.*
