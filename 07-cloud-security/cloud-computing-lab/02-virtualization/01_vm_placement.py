#!/usr/bin/env python3
# bin-pack VMs onto hosts. each host has mips + ram, each VM asks for some of both.
# first-fit / best-fit / worst-fit, count how many hosts each policy needs.

CAP_MIPS = 10000
CAP_RAM = 32

vms = [
    ("vm0", 5000, 8),
    ("vm1", 7000, 12),
    ("vm2", 1000, 2),
    ("vm3", 5000, 8),
    ("vm4", 1000, 2),
    ("vm5", 5000, 8),
    ("vm6", 1000, 2),
    ("vm7", 5000, 8),
]


def fits(h, mips, ram):
    return h[0] >= mips and h[1] >= ram


def new_host():
    return [CAP_MIPS, CAP_RAM, []]


def place(h, name, mips, ram):
    h[0] -= mips
    h[1] -= ram
    h[2].append(name)


def first_fit(vms):
    hosts = []
    for name, mips, ram in vms:
        for h in hosts:
            if fits(h, mips, ram):
                place(h, name, mips, ram)
                break
        else:
            h = new_host()
            place(h, name, mips, ram)
            hosts.append(h)
    return hosts


def best_fit(vms):
    hosts = []
    for name, mips, ram in vms:
        pick = None
        for h in hosts:
            if fits(h, mips, ram) and (pick is None or h[0] < pick[0]):
                pick = h
        if pick is None:
            pick = new_host()
            hosts.append(pick)
        place(pick, name, mips, ram)
    return hosts


def worst_fit(vms):
    hosts = []
    for name, mips, ram in vms:
        pick = None
        for h in hosts:
            if fits(h, mips, ram) and (pick is None or h[0] > pick[0]):
                pick = h
        if pick is None:
            pick = new_host()
            hosts.append(pick)
        place(pick, name, mips, ram)
    return hosts


def show(tag, hosts):
    print(f"{tag}: {len(hosts)} hosts")
    for i, h in enumerate(hosts):
        used = CAP_MIPS - h[0]
        print(f"  h{i}: mips {used}/{CAP_MIPS}  ram {CAP_RAM - h[1]}/{CAP_RAM}  {h[2]}")


print(f"host = {CAP_MIPS} mips, {CAP_RAM} GB ram")
print(f"{len(vms)} vms\n")
show("first-fit", first_fit(vms))
print()
show("best-fit", best_fit(vms))
print()
show("worst-fit", worst_fit(vms))
