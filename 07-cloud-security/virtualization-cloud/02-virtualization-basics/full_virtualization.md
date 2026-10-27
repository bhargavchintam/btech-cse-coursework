# Full Virtualization

**Definition:** In **full virtualization** the guest OS runs **completely unmodified** — it does not know it is virtualized. The hypervisor presents a full virtual hardware and handles the guest's privileged instructions using **binary translation** + direct execution.

## Key idea
- Guest OS thinks it is running on real hardware.
- Problem: some privileged (ring 0) instructions cannot run safely from a guest.
- Solution: hypervisor **traps** those instructions and **translates** them on the fly = **binary translation**.
- Normal (non-privileged) instructions run directly on CPU for speed.

## Characteristics
- Guest OS **unmodified** — any OS works (Windows, Linux) as-is.
- Uses **binary translation** for sensitive instructions.
- Full hardware emulation presented to guest.
- Pioneered by **VMware** (on early x86 without hardware support).

## Working (flow)
1. Guest runs normally for user-level instructions (direct execution).
2. When guest issues a privileged instruction → hypervisor intercepts.
3. Hypervisor translates it into safe instructions and executes.
4. Result returned to guest → guest never realizes.

## Advantages
- **No guest OS modification** — portability, run any unmodified OS.
- Strong isolation.
- Good compatibility.

## Disadvantages
- **Performance overhead** — binary translation costs CPU time.
- More complex hypervisor.

## Examples
- **VMware ESX/Workstation** (early), **Microsoft Virtual Server**.

## Compare (one line each) — imp
- **Full virt** → guest unmodified, binary translation.
- **Para virt** → guest modified, hypercalls.
- **Hardware-assisted** → CPU support (VT-x / AMD-V) replaces binary translation.

*(2 marks: Full virtualization uses ______ = binary translation, guest OS is ______ = unmodified.)*
