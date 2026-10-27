#!/usr/bin/env python3
# Bindu Bhargava  22-08-20
# mini cloud sim: broker maps cloudlets to VMs round robin, each VM is space-shared

rate = 2.0   # cost per second a VM is up

vms = [("vm0", 1000), ("vm1", 1000), ("vm2", 1000)]
lengths = [1000, 2000, 1000, 3000, 2000, 1000]
mips = dict(vms)

queues = {v: [] for v, _ in vms}
for i, ln in enumerate(lengths):
    v = vms[i % len(vms)][0]          # broker: round robin over the VMs
    queues[v].append((f"cl{i}", ln))

rows = []
uptime = {}
for v, _ in vms:
    t = 0.0
    for name, ln in queues[v]:
        start = t
        t += ln / mips[v]
        rows.append((name, v, ln, start, t))
    uptime[v] = t

rows.sort(key=lambda r: (r[3], r[0]))
print("cloudlet  vm    len   start  finish")
for name, v, ln, s, f in rows:
    print(f"  {name:5} {v:4} {ln:5}  {s:5.1f} {f:6.1f}")

mk = max(r[4] for r in rows)
cost = sum(uptime[v] * rate for v, _ in vms)
print(f"\nmakespan = {mk:.1f} s")
for v, _ in vms:
    print(f"  {v} up {uptime[v]:.1f}s  cost {uptime[v] * rate:.1f}")
print(f"total cost = {cost:.1f}  (rate {rate}/s per vm)")
