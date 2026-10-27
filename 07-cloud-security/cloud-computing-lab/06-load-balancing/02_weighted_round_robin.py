#!/usr/bin/env python3
from collections import Counter

servers = ["a", "b", "c"]
weights = [5, 1, 1]


class WeightedRR:
    def __init__(self, servers, weights):
        self.servers = servers
        self.w = weights
        self.cw = [0] * len(servers)
        self.total = sum(weights)

    def pick(self):
        for i in range(len(self.servers)):
            self.cw[i] += self.w[i]
        i = self.cw.index(max(self.cw))
        self.cw[i] -= self.total
        return self.servers[i]


lb = WeightedRR(servers, weights)
n = 7
seq = [lb.pick() for _ in range(n)]
print("order:", " ".join(seq))

dist = Counter(seq)
print(f"\n{n} requests, weights {dict(zip(servers, weights))}")
for s, w in zip(servers, weights):
    print(f"  {s}: {dist[s]}  (weight {w})")
