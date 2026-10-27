#!/usr/bin/env python3

n = 5

class Replica:
    def __init__(self, rid):
        self.rid = rid
        self.val = None
        self.ver = 0

reps = [Replica(i) for i in range(n)]

def write(val, ids):
    ver = max(reps[i].ver for i in ids) + 1
    for i in ids:
        reps[i].val = val
        reps[i].ver = ver
    print(f"write {val!r} ver={ver} to {sorted(ids)}  W={len(ids)}")
    return ver

def read(ids):
    best = max((reps[i] for i in ids), key=lambda r: r.ver)
    print(f"read from {sorted(ids)}  R={len(ids)} -> {best.val!r} ver={best.ver}")
    return best.ver


w = write("A", [0, 1, 2])

print(f"\ncase 1: R=3, W+R={3+3} > N={n}")
got = read([2, 3, 4])
print("  overlaps the write set, got latest" if got == w else "  stale!")

print(f"\ncase 2: R=2, W+R={3+2} <= N={n}")
got = read([3, 4])
print("  latest" if got == w else "  stale read, missed the write")
