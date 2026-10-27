#!/usr/bin/env python3
import os
from itertools import combinations
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "transactions.csv"))
txns = [set(r.split()) for r in df["Items"]]
n = len(txns)


def count(s):
    return sum(1 for t in txns if s <= t)


def support(s):
    return count(s) / n


def join(prev, k):
    cand = set()
    for a in prev:
        for b in prev:
            u = a | b
            if len(u) == k and all(frozenset(x) in prev for x in combinations(u, k - 1)):
                cand.add(u)
    return cand


def apriori(min_sup):
    items = sorted({i for t in txns for i in t})
    level = {frozenset([i]) for i in items}
    freq = {}
    k = 1
    while level:
        keep = {s for s in level if support(s) >= min_sup}
        if not keep:
            break
        print(f"frequent {k}-itemsets:")
        for s in sorted(keep, key=lambda x: sorted(x)):
            print(f"  {sorted(s)}  count={count(s)}  sup={support(s):.2f}")
        freq.update({s: support(s) for s in keep})
        level = join(keep, k + 1)
        k += 1
    return freq


min_sup = 0.6
print(f"min_support = {min_sup}  (count >= {round(min_sup * n)} of {n})\n")
apriori(min_sup)
