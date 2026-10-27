#!/usr/bin/env python3
from collections import deque

tasks = ["t0", "t1", "t2", "t3"]
bt = [6, 8, 7, 3]
q = 4

rem = bt[:]
ct = [0] * len(bt)
dq = deque(range(len(bt)))
sched = []
t = 0
while dq:
    i = dq.popleft()
    run = min(q, rem[i])
    sched.append((tasks[i], t, t + run))
    t += run
    rem[i] -= run
    if rem[i] > 0:
        dq.append(i)            # not done, back of the queue
    else:
        ct[i] = t

print("round robin, quantum =", q)
print("schedule:")
for name, s, e in sched:
    print(f"  {name}: {s} -> {e}")

n = len(bt)
twt = 0
print("task  bt  ct  tat  wt")
for i in range(n):
    tat = ct[i]
    wt = tat - bt[i]
    twt += wt
    print(f"{tasks[i]:>4}  {bt[i]:>2}  {ct[i]:>2}  {tat:>3}  {wt:>2}")

print(f"avg waiting = {twt / n:.2f}")
