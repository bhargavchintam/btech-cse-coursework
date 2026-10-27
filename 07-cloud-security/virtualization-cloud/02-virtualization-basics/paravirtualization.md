# Paravirtualization

**Definition:** In **paravirtualization** the guest OS is **modified** (aware it is virtualized) and talks to the hypervisor directly through special calls called **hypercalls**, instead of issuing privileged hardware instructions.

## Key idea
- "Para" = alongside / assisting → guest cooperates with the hypervisor.
- No binary translation needed — guest **knows** it's virtual and asks the hypervisor politely.
- Privileged operations replaced by **hypercalls** (like system calls, but to the hypervisor).

## Characteristics
- Guest OS **kernel must be modified** — this is the main catch.
- Communicates via **hypercalls**.
- Lower overhead than full virtualization → **better performance**.
- Pioneered by **Xen**.

## Working (flow)
1. Guest OS kernel is patched to be virt-aware.
2. Instead of privileged instruction → guest makes a **hypercall** to hypervisor.
3. Hypervisor performs the operation on hardware.
4. Faster because no trap-and-translate.

## Advantages
- **Lower overhead / better performance** than full virt.
- Simpler than binary translation.
- Efficient use of resources.

## Disadvantages
- **Guest OS must be modified** → cannot run unmodified/closed OS easily (e.g. older Windows).
- Portability reduced — needs a supported, patched kernel.
- More maintenance (keep patched kernels updated).

## Example
- **Xen** hypervisor (classic paravirtualization).

## Full vs Para (imp table)

| Point | Full virtualization | Paravirtualization |
|-------|---------------------|--------------------|
| Guest OS | Unmodified | Modified (virt-aware) |
| Technique | Binary translation | Hypercalls |
| Performance | More overhead | Less overhead (faster) |
| OS support | Any OS | Only patchable OS |
| Example | VMware | Xen |

*(Q: What is a hypercall? → the interface a paravirtualized guest uses to call the hypervisor.)*
