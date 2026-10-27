#!/usr/bin/env python3
# lab 2 - schedule a batch of cloudlets onto a set of VMs and report makespan.
# two brokers: round robin (deal them out in turn) and greedy (send each
# cloudlet to the VM that would finish it earliest). makespan = last finish.

vms = [("vm0", 1000), ("vm1", 1500), ("vm2", 2000)]   # name, mips
cloudlets = [1200, 2000, 800, 3000, 1500, 600, 2400, 900]   # lengths in MI


def run(pick):
    mips = dict(vms)
    end = {v: 0.0 for v, _ in vms}
    place = []
    for i, ln in enumerate(cloudlets):
        v = pick(i, ln, end, mips)
        end[v] += ln / mips[v]
        place.append((f"cl{i}", v, ln))
    return end, place


def rr(i, ln, end, mips):
    return vms[i % len(vms)][0]


def greedy(i, ln, end, mips):
    best = None
    for v, m in vms:
        fin = end[v] + ln / m
        if best is None or fin < best[1]:
            best = (v, fin)
    return best[0]


for tag, fn in [("round-robin", rr), ("greedy", greedy)]:
    end, place = run(fn)
    print(tag)
    for name, v, ln in place:
        print(f"  {name:4} ({ln:4} MI) -> {v}")
    for v, _ in vms:
        print(f"  {v} busy till {end[v]:.2f}")
    print(f"  makespan = {max(end.values()):.2f}\n")
