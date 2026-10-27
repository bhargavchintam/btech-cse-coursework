#!/usr/bin/env python3

HOST_MIPS = 10000
IDLE = 100.0     # watts, host on but idle
PEAK = 250.0     # watts, host at full load
HOURS = 1.0

vms = [(f"vm{i}", 2500) for i in range(6)]


def power(load):
    u = load / HOST_MIPS
    return IDLE + (PEAK - IDLE) * u


def energy(loads):
    return sum(power(l) for l in loads) * HOURS


before = [m for _, m in vms]

after = []
for _, m in vms:
    for i in range(len(after)):
        if after[i] + m <= HOST_MIPS:
            after[i] += m
            break
    else:
        after.append(m)

print(f"host mips={HOST_MIPS}  idle={IDLE}W peak={PEAK}W")
print(f"{len(vms)} vms x 2500 mips\n")

print(f"before: {len(before)} hosts on")
for i, l in enumerate(before):
    print(f"  h{i}: load {l}/{HOST_MIPS} util {l / HOST_MIPS:.0%}  {power(l):.1f}W")
eb = energy(before)
print(f"  energy = {eb:.1f} Wh\n")

print(f"after:  {len(after)} hosts on, {len(before) - len(after)} off")
for i, l in enumerate(after):
    print(f"  h{i}: load {l}/{HOST_MIPS} util {l / HOST_MIPS:.0%}  {power(l):.1f}W")
ea = energy(after)
print(f"  energy = {ea:.1f} Wh")
print(f"\nsaved {eb - ea:.1f} Wh ({(eb - ea) / eb:.0%})")
