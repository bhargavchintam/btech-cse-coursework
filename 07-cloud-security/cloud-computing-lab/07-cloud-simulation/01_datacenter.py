#!/usr/bin/env python3

class Host:
    def __init__(self, hid, mips, cores, ram):
        self.hid = hid
        self.mips = mips
        self.cores = cores
        self.ram = ram
        self.vms = []

    def fits(self, vm):
        return self.mips >= vm.mips and self.cores >= vm.cores and self.ram >= vm.ram

    def place(self, vm):
        self.mips -= vm.mips
        self.cores -= vm.cores
        self.ram -= vm.ram
        self.vms.append(vm)


class VM:
    def __init__(self, vid, mips, cores, ram):
        self.vid = vid
        self.mips = mips
        self.cores = cores
        self.ram = ram


hosts = [
    Host("h0", 6000, 6, 12288),
    Host("h1", 4000, 4, 8192),
]

vms = [
    VM("vm0", 2000, 2, 4096),
    VM("vm1", 2000, 2, 4096),
    VM("vm2", 1500, 2, 4096),
    VM("vm3", 2000, 2, 4096),
]


def allocate(vm):
    for h in hosts:
        if h.fits(vm):
            h.place(vm)
            return h
    return None


print("datacenter dc-1:", len(hosts), "hosts")
for vm in vms:
    h = allocate(vm)
    if h:
        print(f"  {vm.vid} (mips={vm.mips} cores={vm.cores} ram={vm.ram}) -> {h.hid}")
    else:
        print(f"  {vm.vid} could not be placed")

print("\nremaining capacity")
for h in hosts:
    on = ",".join(v.vid for v in h.vms) or "-"
    print(f"  {h.hid}: mips={h.mips} cores={h.cores} ram={h.ram}  [{on}]")
