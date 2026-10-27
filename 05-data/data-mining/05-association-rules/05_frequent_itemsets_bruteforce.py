#!/usr/bin/env python3
import os
from itertools import combinations
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "transactions.csv"))
txns = [set(r.split()) for r in df["Items"]]
n = len(txns)
items = sorted({i for t in txns for i in t})
min_sup = 0.6


def support(s):
    s = frozenset(s)
    return sum(1 for t in txns if s <= t) / n


brute = {}
for r in range(1, len(items) + 1):
    for combo in combinations(items, r):
        brute[frozenset(combo)] = support(combo)

freq_brute = {s: sup for s, sup in brute.items() if sup >= min_sup}


def apriori_freq(min_sup):
    level = {frozenset([i]) for i in items}
    freq = {}
    k = 1
    while level:
        keep = {s for s in level if support(s) >= min_sup}
        if not keep:
            break
        freq.update({s: support(s) for s in keep})
        level = {a | b for a in keep for b in keep
                 if len(a | b) == k + 1
                 and all(frozenset(x) in keep for x in combinations(a | b, k))}
        k += 1
    return freq


freq_ap = apriori_freq(min_sup)

print(f"brute force: scanned all {len(brute)} itemsets, {len(freq_brute)} frequent (sup >= {min_sup}):\n")
for s in sorted(freq_brute, key=lambda x: (len(x), sorted(x))):
    print(f"  {sorted(s)}  sup={freq_brute[s]:.2f}")

print("\nApriori found the same frequent set? ", set(freq_brute) == set(freq_ap))
