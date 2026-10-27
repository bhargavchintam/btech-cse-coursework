# OS-Level Virtualization

**Definition:** **OS-level virtualization** allows a single OS kernel to run **multiple isolated user-space instances**. Each instance (a **container**) looks like a separate machine but they all **share the host's kernel**.

- No hypervisor, no separate guest OS per instance → this is **containerization**.
- e.g. **Docker, LXC, OpenVZ, Solaris Zones, FreeBSD Jails**.

## Key idea
- Traditional VM = full guest OS + own kernel on a hypervisor (heavy).
- Container = shares host kernel, isolates only the **user space** (processes, files, network) → light.
- Isolation done using kernel features: **namespaces** (isolation) + **cgroups** (resource limits) on Linux.

## How it works (Linux)
- **Namespaces** — give each container its own view of PID, network, mount, users, etc.
- **cgroups (control groups)** — limit CPU, memory, I/O per container.
- Together → each container feels like its own OS, but kernel is shared.

## Containers vs VMs (imp table)

| Point | Virtual Machine | Container (OS-level) |
|-------|-----------------|----------------------|
| Kernel | Own guest kernel | Shares host kernel |
| Hypervisor | Needed | Not needed |
| Size | GBs (full OS) | MBs (app + libs) |
| Boot time | Minutes | Seconds |
| Isolation | Strong (hardware level) | Weaker (OS level) |
| Overhead | High | Low |
| Example | ESXi, KVM, VirtualBox | Docker, LXC |

## Advantages
- **Lightweight** — no full guest OS, low overhead.
- **Fast** start/stop (seconds).
- High density — many containers per host.
- Portable — "build once, run anywhere" (Docker image).
- Ideal for microservices + CI/CD.

## Disadvantages / limitations
- **Shared kernel** → weaker isolation than VM; a kernel exploit affects all.
- Guest must use the **same OS family** as host (Linux containers need Linux kernel).
- Not ideal for running a different OS (can't run Windows container on Linux kernel).

## Note
- Containers **complement** VMs, not fully replace — often containers run **inside** VMs in cloud.

*(Q: Differentiate VM and container → draw the table; mention namespaces + cgroups.)*
