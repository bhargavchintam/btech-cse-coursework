# Hardware-Assisted Virtualization

**Definition:** **Hardware-assisted virtualization** uses special **CPU extensions** to run virtualization efficiently — the processor itself provides support for trapping privileged guest instructions, so the guest OS stays **unmodified** and there is **no need for binary translation**.

- CPU support: **Intel VT-x** and **AMD-V** (AMD SVM). (imp — remember both names)

## Key idea
- Older x86 had no clean way to virtualize (ring problem) → needed binary translation or para virt.
- Intel/AMD added a **new CPU mode** for the hypervisor + a mode for guests.
- Guest privileged instructions are trapped **by hardware** and handed to the hypervisor.
- Result: unmodified guest + near-native performance.

## Extensions
- **Intel VT-x** — Virtualization Technology for x86. Adds root (hypervisor) + non-root (guest) modes.
- **AMD-V** — AMD's equivalent.
- **EPT (Intel) / RVI (AMD)** — hardware support for memory (nested/second-level page tables) → faster memory virtualization.

## Working (flow)
1. Hypervisor runs in **root mode** (VMX root, ring -1 conceptually).
2. Guest runs in **non-root mode**, thinks it owns ring 0.
3. Privileged/sensitive instruction → **VM exit** to hypervisor (done by CPU).
4. Hypervisor handles it → **VM entry** back to guest.

## Advantages
- **Guest OS unmodified** (like full virt) **and** low overhead (like para virt) — best of both.
- Simpler hypervisor design.
- Near-native performance.
- Required by modern Type-1 hypervisors (**KVM needs VT-x/AMD-V**).

## Disadvantages
- Needs **CPU with the extensions** + enabled in BIOS.
- Frequent VM exits can still cost performance in some workloads.

## Three techniques — final compare (imp)

| Technique | Guest OS | How privileged instr handled |
|-----------|----------|------------------------------|
| Full virt | Unmodified | Binary translation (software) |
| Paravirt | Modified | Hypercalls |
| Hardware-assisted | Unmodified | CPU traps (VT-x / AMD-V) |

*(2 marks: Name the Intel and AMD CPU extensions = VT-x and AMD-V.)*
