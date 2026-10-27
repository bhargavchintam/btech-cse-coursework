# Benefits and Challenges of Virtualization

Summary sheet — pairs the gains against the problems. Good for a 5/10 mark answer.

## Benefits (imp — list any five)
- **Server consolidation** — many VMs on one host → fewer physical servers.
- **High resource utilization** — idle CPU/RAM (was ~15%) put to use.
- **Cost saving** — less hardware, power, cooling, floor space (CapEx + OpEx down).
- **Isolation** — one VM's crash/malware does not affect others.
- **Fast provisioning** — clone/deploy a VM in minutes.
- **Snapshots & rollback** — save VM state, revert on failure.
- **Live migration** — move a running VM to another host with ~no downtime.
- **Disaster recovery** — VMs are files → easy backup + quick restore.
- **Test/dev flexibility** — run many OS/versions on one machine.
- **Hardware independence** — VM not tied to specific physical hardware.
- **Green IT** — fewer servers → less energy.

## Challenges / limitations (imp)
- **Performance overhead** — hypervisor layer adds some cost vs bare metal.
- **Single point of failure** — host fails → all its VMs go down (need HA/clustering).
- **VM sprawl** — too many VMs created and forgotten → wasted resources, hard to manage.
- **Security** — new attack surface: hypervisor attack, **VM escape**, side-channel.
- **Resource contention** — noisy VM hogs CPU/IO, hurts neighbours.
- **Licensing & cost** — hypervisor + guest OS licenses, management tools.
- **Complexity** — needs skilled admins, monitoring, patching.
- **Not all workloads suit virt** — very high I/O / latency-sensitive apps.

## Benefit ↔ Challenge (quick pairing)
| Benefit | Related challenge |
|---------|-------------------|
| Consolidation | Single point of failure |
| Easy to create VMs | VM sprawl |
| Isolation | VM escape / hypervisor attacks |
| Shared hardware | Resource contention |

## One-liners to recall
- Best benefit → **better utilization + consolidation**.
- Biggest risk → **host = single point of failure** and **security (VM escape)**.

*(Q: "State any five benefits and any three challenges of virtualization" — pick from lists.)*
