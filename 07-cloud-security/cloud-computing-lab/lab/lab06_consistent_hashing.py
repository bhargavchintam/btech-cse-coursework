#!/usr/bin/env python3
# lab 6 - consistent hashing. nodes and keys both hash onto a ring and a key
# belongs to the first node clockwise from it. add a node and only the keys in
# its arc move - about 1/N of them, not the whole keyspace like plain mod-N.

import hashlib
import bisect
from collections import Counter


def h(s):
    return int(hashlib.md5(s.encode()).hexdigest(), 16)


class Ring:
    def __init__(self, nodes, vnodes=100):
        self.vnodes = vnodes
        self.ring = []
        self.owner = {}
        for n in nodes:
            self.add(n)

    def add(self, node):
        for i in range(self.vnodes):
            hv = h(f"{node}#{i}")
            bisect.insort(self.ring, hv)
            self.owner[hv] = node

    def locate(self, key):
        i = bisect.bisect(self.ring, h(key)) % len(self.ring)
        return self.owner[self.ring[i]]


keys = [f"key{i}" for i in range(2000)]

r = Ring(["A", "B", "C"])
before = {k: r.locate(k) for k in keys}

r.add("D")
after = {k: r.locate(k) for k in keys}

moved = sum(1 for k in keys if before[k] != after[k])
print("nodes A,B,C  then add D")
print(f"keys           = {len(keys)}")
print(f"moved after +D = {moved}  ({100 * moved / len(keys):.1f}%)")
print(f"1/N ideal      = {100 / 4:.1f}%")
print("spread after   =", dict(sorted(Counter(after.values()).items())))
