# Virtualization vs Cloud Computing

Common confusion — they are related but NOT the same. Virtualization is a **technology**; cloud is a **model / service** built using it.

## One-line difference
- **Virtualization** = making one physical resource act as many virtual ones.
- **Cloud** = delivering computing as an on-demand, metered service over internet (often uses virt underneath).

## Comparison table (imp — 5 marks)

| Point | Virtualization | Cloud Computing |
|-------|----------------|-----------------|
| What it is | Technology / technique | Service delivery model |
| Purpose | Create virtual machines from one hardware | Provide IT resources on-demand over internet |
| Core tool | Hypervisor / VMM | Data centres + virt + automation |
| Scope | Single machine or data centre | Pool of many machines, often global |
| Access | Usually within org / local | Over internet, self-service |
| Billing | No metering by itself | Pay-per-use, metered |
| Scalability | Limited to physical host capacity | Elastic, appears near-infinite |
| Managed by | Own IT team (usually) | Cloud provider |
| Example | VirtualBox, VMware ESXi, KVM | AWS, Azure, GCP |

## Relationship (key point)
- **Virtualization is the foundation of cloud** — cloud data centres run on virtualized servers.
- But cloud adds: self-service portal, metering/billing, automation, elasticity, multi-tenancy.
- You can have virtualization **without** cloud (a lab with VMs, no internet service).
- You cannot have public cloud **without** some virtualization underneath.

## Analogy
- Virtualization = the **engine**.
- Cloud = the **taxi service** built around that engine (booking, billing, scale).

## Quick recall
- Virt → local, technology, no billing, hypervisor.
- Cloud → internet, service, metered, elastic, provider-run.

*(Differentiate virtualization and cloud computing → draw the table, add the "virt is foundation of cloud" line.)*
