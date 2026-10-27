# Virtualization security

Since cloud runs on virtualization, securing the **hypervisor and VMs** is core. Attacks here can affect many tenants at once.

## Why it matters
- one physical host runs **many VMs** of different tenants (multi-tenancy).
- if the **hypervisor** is compromised, attacker can reach every VM on it → big blast radius.
- isolation between VMs must hold — a tenant should never see another tenant's data.

## Key threats
- **VM escape** — malicious code breaks out of a VM to the hypervisor / host, then other VMs. (worst case)
- **Hyperjacking** — attacker installs a rogue hypervisor or takes over the real one, controls all VMs below.
- **VM sprawl** — too many unused/forgotten VMs → unpatched, unmonitored, attack surface grows.
- **VM snapshot / image risks** — snapshots contain data + secrets; if leaked, data exposed. Old images may be unpatched.
- **Inter-VM attacks / side channels** — one VM snoops on another via shared hardware (cache timing etc.).
- **Migration attacks** — VM data intercepted while being live-migrated between hosts (if unencrypted).

## Countermeasures
- **harden the hypervisor** — patch it, minimise it, disable unused services.
- **strong VM isolation** — provider enforces separation, no shared memory across tenants.
- **secure VM images** — use trusted, patched base images; scan them.
- **encrypt snapshots & migration traffic**.
- **limit VM sprawl** — inventory, decommission unused VMs, patch management.
- **least privilege** on the management console (who can create/delete VMs).
- **monitoring & logging** at hypervisor and VM level.
- **virtual firewalls / security groups** to control VM-to-VM traffic.

## Terms to remember (table)

| Term | Meaning |
|------|---------|
| VM escape | breaking out of a VM to the host/hypervisor |
| Hyperjacking | taking control of the hypervisor |
| VM sprawl | uncontrolled growth of unused VMs |
| Isolation | keeping tenants' VMs separated |

One-liner: the **hypervisor is the single most critical thing to secure** in a virtualized cloud.
