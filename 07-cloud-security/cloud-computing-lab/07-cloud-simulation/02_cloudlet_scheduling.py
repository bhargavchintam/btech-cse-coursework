#!/usr/bin/env python3

def space_shared(mips, cls):
    t = 0.0
    out = []
    for name, length in cls:
        start = t
        t += length / mips
        out.append((name, start, t))
    return out


def time_shared(mips, cls):
    rem = {name: float(length) for name, length in cls}
    finish = {}
    t = 0.0
    while rem:
        share = mips / len(rem)          # split the VM evenly over live cloudlets
        dt = min(r / share for r in rem.values())
        t += dt
        done = []
        for name in rem:
            rem[name] -= share * dt
            if rem[name] <= 1e-9:
                done.append(name)
        for name in done:
            finish[name] = t
            del rem[name]
    return finish


vms = {
    "vm0": (1000, [("c0", 1000), ("c1", 2000)]),
    "vm1": (2000, [("c2", 4000), ("c3", 2000)]),
}

for vid, (mips, cls) in vms.items():
    print(f"{vid} mips={mips}  cloudlets={cls}")
    print("  space-shared:")
    for name, s, f in space_shared(mips, cls):
        print(f"    {name}: start={s:.2f} finish={f:.2f}")
    print("  time-shared:")
    fin = time_shared(mips, cls)
    for name, _ in cls:
        print(f"    {name}: finish={fin[name]:.2f}")
    print()
