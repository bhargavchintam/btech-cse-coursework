#!/usr/bin/env python3
# live migration to relieve an overloaded host: move its biggest VMs onto the
# least-loaded host that has room, until it drops under the threshold.

CAP = 10000
THRESHOLD = 0.80


class Host:
    def __init__(self, hid, vms):
        self.hid = hid
        self.vms = dict(vms)   # name -> mips

    def load(self):
        return sum(self.vms.values())

    def util(self):
        return self.load() / CAP

    def room(self, mips):
        return self.load() + mips <= CAP


hosts = [
    Host("h0", {"vm0": 4000, "vm1": 3000, "vm2": 2000, "vm3": 1000}),
    Host("h1", {"vm4": 2000}),
    Host("h2", {"vm5": 2000, "vm6": 1000}),
]


def report(tag):
    print(tag)
    for h in hosts:
        flag = "  OVERLOADED" if h.util() > THRESHOLD else ""
        print(f"  {h.hid}: load {h.load()}/{CAP} ({h.util()*100:.0f}%) {sorted(h.vms)}{flag}")


def migrate():
    moves = []
    for src in hosts:
        while src.util() > THRESHOLD:
            name = max(src.vms, key=src.vms.get)
            mips = src.vms[name]
            dst = min((h for h in hosts if h is not src and h.room(mips)),
                      key=lambda h: h.load(), default=None)
            if dst is None:
                break
            del src.vms[name]
            dst.vms[name] = mips
            moves.append((name, src.hid, dst.hid))
    return moves


report("before")
print(f"\nthreshold = {THRESHOLD*100:.0f}%\n")
for name, s, d in migrate():
    print(f"migrate {name} : {s} -> {d}")
print()
report("after")
