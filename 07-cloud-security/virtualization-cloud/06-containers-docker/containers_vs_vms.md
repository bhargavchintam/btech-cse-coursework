# Containers vs Virtual Machines

Very commonly asked — differentiate the two, usually as a table. (asked prev year)

## Basic difference
- **VM** virtualizes the **hardware** — each VM runs a full **guest OS** on top of a hypervisor.
- **Container** virtualizes the **OS** — containers **share the host OS kernel**, no guest OS.

That single line (guest OS vs shared kernel) is the core of the answer.

## Comparison table (imp)

| Point | Virtual Machine | Container |
|-------|-----------------|-----------|
| OS | Each VM has its own **guest OS** | **Shares host OS kernel**, no guest OS |
| Runs on | Hypervisor (Type 1 / Type 2) | Container engine (e.g. Docker) on host OS |
| Size | Heavy — GBs (full OS) | Light — MBs (app + libs only) |
| Startup time | Slow — minutes (boots OS) | Fast — seconds |
| Isolation | Strong (full OS-level, separate kernel) | Process-level (namespaces + cgroups) |
| Resource use | High (each carries an OS) | Low, more containers per host |
| Portability | Less portable (large images) | Highly portable |
| Boot | Full OS boot each time | No OS boot, just process start |

## Architecture (how they stack)
VM stack:
```
App | App
Guest OS | Guest OS
Hypervisor
Host OS (optional, type 2)
Hardware
```

Container stack:
```
App | App | App
Container Engine (Docker)
Host OS  (kernel shared)
Hardware
```

Note the container stack has **no guest OS layer** — that layer is what makes VMs heavy.

## When to use which
- **VM** — need strong isolation, run different OS (Windows on Linux host), legacy apps.
- **Container** — need speed, density, microservices, CI/CD, cloud-native apps.

## One-liner for exam
VM = heavy, own guest OS, strong isolation, slow boot. Container = light, shares host kernel, fast, portable.
