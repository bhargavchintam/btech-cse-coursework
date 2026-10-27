#!/usr/bin/env python3
import os
from itertools import combinations
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "transactions.csv"))
txns = [set(r.split()) for r in df["Items"]]
n = len(txns)


def support(s):
    s = frozenset(s)
    return sum(1 for t in txns if s <= t) / n


def freq_itemsets(min_sup):
    items = sorted({i for t in txns for i in t})
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


min_sup, min_conf = 0.6, 0.7
freq = freq_itemsets(min_sup)

rules = []
for f in freq:
    if len(f) < 2:
        continue
    for r in range(1, len(f)):
        for a in combinations(f, r):
            a = frozenset(a)
            b = f - a
            conf = support(f) / support(a)
            if conf >= min_conf:
                rules.append((a, b, support(f), conf, conf / support(b)))

print(f"rules with support >= {min_sup} and confidence >= {min_conf}\n")
for a, b, sup, conf, lift in sorted(rules, key=lambda x: -x[4]):
    print(f"{sorted(a)} -> {sorted(b)}   sup={sup:.2f}  conf={conf:.2f}  lift={lift:.2f}")
