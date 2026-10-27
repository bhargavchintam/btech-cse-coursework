# Types of Virtualization

**Definition:** Virtualization can be applied to different resources. Based on **what** is virtualized, we classify the types below.

## Main types (imp — list any five)
1. **Server / Hardware virtualization** — one physical server → many VMs, each with own OS. Done by hypervisor. Most common.
2. **Storage virtualization** — pool many physical disks and present as a single logical storage. e.g. SAN, RAID.
3. **Network virtualization** — split/combine physical network into virtual networks. e.g. VLAN, VPN, virtual switch, SDN.
4. **Desktop virtualization (VDI)** — user desktop runs on a server, accessed remotely from thin client.
5. **Application virtualization** — app runs in isolated env, no full install on host. e.g. run app streamed to user.
6. **OS-level virtualization** — one OS kernel shared, many isolated user-space instances. = **containers** (Docker, LXC).

## By virtualized resource (quick table)

| Type | What is virtualized | Example |
|------|--------------------|---------|
| Server | CPU, RAM, whole machine | ESXi, KVM, Hyper-V |
| Storage | Disks | SAN, RAID, LVM |
| Network | Switches, links | VLAN, VPN, SDN |
| Desktop | User desktop | Citrix VDI, VMware Horizon |
| Application | Single app | App-V, ThinApp |
| OS-level | User space / process | Docker, LXC |

## By technique (server virt sub-types) — covered in detail elsewhere
- **Full virtualization** — guest OS unmodified, binary translation.
- **Paravirtualization** — guest OS modified, uses hypercalls.
- **Hardware-assisted** — CPU support (Intel VT-x / AMD-V).

## Note
- **Server virtualization** is what people usually mean by "virtualization".
- **OS-level virtualization (containers)** is lighter — no full guest OS per instance.

*(Q: "List and explain any five types of virtualization" — use the main-types list.)*
