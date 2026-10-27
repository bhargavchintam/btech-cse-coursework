#!/usr/bin/env python3
import hashlib, bisect

class Ring:
    def __init__(self, vnodes=150):
        self.vnodes = vnodes
        self.ring = []       # sorted hashes
        self.owner = {}      # hash -> node

    def _h(self, s):
        return int(hashlib.md5(s.encode()).hexdigest(), 16)

    def add(self, node):
        for v in range(self.vnodes):
            h = self._h(f"{node}#{v}")
            bisect.insort(self.ring, h)
            self.owner[h] = node

    def remove(self, node):
        self.ring = [h for h in self.ring if self.owner[h] != node]
        self.owner = {h: nd for h, nd in self.owner.items() if nd != node}

    def locate(self, key):
        h = self._h(key)
        i = bisect.bisect(self.ring, h)
        if i == len(self.ring):
            i = 0                        # wrap around the ring
        return self.owner[self.ring[i]]


ring = Ring()
for node in ["n0", "n1", "n2"]:
    ring.add(node)

keys = [f"key{i}" for i in range(2000)]
before = {k: ring.locate(k) for k in keys}

ring.add("n3")
after = {k: ring.locate(k) for k in keys}

moved = sum(1 for k in keys if before[k] != after[k])
n = 4
print(f"nodes now: n0 n1 n2 n3")
print(f"keys moved when adding n3: {moved}/{len(keys)} = {moved/len(keys):.2%}")
print(f"1/N with N={n} is {1/n:.2%}  (naive mod hashing would move ~75%)")
