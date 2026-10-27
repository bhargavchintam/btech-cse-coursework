#!/usr/bin/env python3

tasks = ["t0", "t1", "t2", "t3"]
bt = [6, 8, 7, 3]

order = sorted(range(len(bt)), key=lambda i: bt[i])

t = 0
ct = {}
for i in order:
    t += bt[i]
    ct[i] = t

print("SJF (non-preemptive)")
print("run order:", [tasks[i] for i in order])
print("task  bt  ct  tat  wt")
n = len(bt)
twt = ttat = 0
for i in range(n):
    tat = ct[i]
    wt = tat - bt[i]
    twt += wt
    ttat += tat
    print(f"{tasks[i]:>4}  {bt[i]:>2}  {ct[i]:>2}  {tat:>3}  {wt:>2}")

print(f"avg waiting    = {twt / n:.2f}")
print(f"avg turnaround = {ttat / n:.2f}")
