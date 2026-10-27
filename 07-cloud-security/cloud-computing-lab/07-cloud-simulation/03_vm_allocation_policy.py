#!/usr/bin/env python3

CAP = 5000
req = [("vm0", 1500), ("vm1", 2500), ("vm2", 3000),
       ("vm3", 1500), ("vm4", 500), ("vm5", 1000)]


def first_fit(req, cap):
    hosts = []
    for name, m in req:
        for h in hosts:
            if h[0] >= m:
                h[0] -= m
                h[1].append(name)
                break
        else:
            hosts.append([cap - m, [name]])
    return hosts


def best_fit(req, cap):
    hosts = []
    for name, m in req:
        best = None
        for h in hosts:
            if h[0] >= m and (best is None or h[0] < best[0]):
                best = h
        if best is None:
            hosts.append([cap - m, [name]])
        else:
            best[0] -= m
            best[1].append(name)
    return hosts


def show(tag, hosts):
    print(f"{tag}: {len(hosts)} hosts")
    for i, h in enumerate(hosts):
        print(f"  h{i}: used={CAP - h[0]}/{CAP}  {h[1]}")


print("host capacity mips =", CAP)
print("vm requests:", req, "\n")
show("first-fit", first_fit(req, CAP))
print()
show("best-fit", best_fit(req, CAP))
