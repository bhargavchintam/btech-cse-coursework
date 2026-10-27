#!/usr/bin/env python3

tasks = ["t0", "t1", "t2", "t3"]
bt = [6, 8, 7, 3]

n = len(tasks)
ct = [0] * n
tat = [0] * n
wt = [0] * n

t = 0
for i in range(n):
    t += bt[i]
    ct[i] = t
    tat[i] = ct[i]          # arrival 0, so turnaround = completion
    wt[i] = tat[i] - bt[i]

print("FCFS on one VM")
print("task  bt  ct  tat  wt")
for i in range(n):
    print(f"{tasks[i]:>4}  {bt[i]:>2}  {ct[i]:>2}  {tat[i]:>3}  {wt[i]:>2}")

print(f"avg waiting    = {sum(wt) / n:.2f}")
print(f"avg turnaround = {sum(tat) / n:.2f}")
