#!/usr/bin/env python3

vms = ["vm0", "vm1", "vm2"]
et = {
    "t0": [10, 12, 14],
    "t1": [3, 4, 5],
    "t2": [4, 5, 6],
    "t3": [5, 6, 7],
    "t4": [2, 3, 4],
}

ready = [0] * len(vms)
left = list(et)
plan = []

while left:
    best = None
    for t in left:
        ct = [ready[j] + et[t][j] for j in range(len(vms))]
        j = min(range(len(vms)), key=lambda k: ct[k])
        if best is None or ct[j] < best[1]:
            best = (t, ct[j], j)
    t, c, j = best
    plan.append((t, vms[j], c))
    ready[j] = c
    left.remove(t)

print("Min-Min mapping")
for t, vm, c in plan:
    print(f"  {t} -> {vm}  completion={c}")
for j, vm in enumerate(vms):
    print(f"  {vm} load = {ready[j]}")
print("makespan =", max(ready))
