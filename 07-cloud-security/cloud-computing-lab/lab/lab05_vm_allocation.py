#!/usr/bin/env python3
# lab 5 - place VMs on hosts as a bin-packing problem. each host has a fixed
# mips capacity, each VM asks for some mips. compare first-fit (first host with
# room) against best-fit (host with the least leftover that still fits).

CAP = 8000
demand = [("vm0", 3000), ("vm1", 6000), ("vm2", 2000), ("vm3", 4000), ("vm4", 1000)]


def first_fit(demand, cap):
    hosts = []
    for name, m in demand:
        for h in hosts:
            if h["free"] >= m:
                h["free"] -= m
                h["vms"].append(name)
                break
        else:
            hosts.append({"free": cap - m, "vms": [name]})
    return hosts


def best_fit(demand, cap):
    hosts = []
    for name, m in demand:
        best = None
        for h in hosts:
            if h["free"] >= m and (best is None or h["free"] < best["free"]):
                best = h
        if best is None:
            hosts.append({"free": cap - m, "vms": [name]})
        else:
            best["free"] -= m
            best["vms"].append(name)
    return hosts


def show(tag, hosts):
    print(f"{tag}: {len(hosts)} hosts")
    for i, h in enumerate(hosts):
        used = CAP - h["free"]
        print(f"  h{i}: {used}/{CAP} mips ({100 * used // CAP}%)  {h['vms']}")


total = sum(m for _, m in demand)
print(f"host cap = {CAP} mips, total demand = {total} mips")
print(f"lower bound = {-(-total // CAP)} hosts\n")
show("first-fit", first_fit(demand, CAP))
print()
show("best-fit", best_fit(demand, CAP))
