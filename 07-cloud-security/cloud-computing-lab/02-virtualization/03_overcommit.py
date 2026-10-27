#!/usr/bin/env python3

pcpu = 16      # physical cores
pram = 64      # GB

vms = [
    ("vm0", 4, 12),
    ("vm1", 4, 12),
    ("vm2", 8, 16),
    ("vm3", 8, 20),
    ("vm4", 8, 16),
]

CPU_MAX = 4.0   # vcpu:pcpu is fine up to ~4:1, cores time-share ok
RAM_MAX = 1.0   # ram overcommit past 1:1 is risky - it swaps, can OOM

vcpu = sum(v[1] for v in vms)
vram = sum(v[2] for v in vms)

cpu_ratio = vcpu / pcpu
ram_ratio = vram / pram

print(f"physical : {pcpu} cores, {pram} GB ram")
print(f"allocated: {vcpu} vcpu, {vram} GB across {len(vms)} vms\n")

print(f"cpu overcommit = {vcpu}/{pcpu} = {cpu_ratio:.2f}:1", end="  ")
print("RISKY" if cpu_ratio > CPU_MAX else "ok")

print(f"ram overcommit = {vram}/{pram} = {ram_ratio:.2f}:1", end="  ")
print("RISKY" if ram_ratio > RAM_MAX else "ok")

if ram_ratio > RAM_MAX:
    print("\nram is oversubscribed - fine while VMs stay idle, but if they all")
    print("touch their pages at once the host swaps and everything slows/OOMs.")
