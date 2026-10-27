#!/usr/bin/env python3
# Lab 4: Association rules.
# From the frequent itemsets of the transactions, generate all rules and print
# their support, confidence and lift. Keep the rules with confidence >= 0.6.

import os
import pandas as pd
from itertools import combinations

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "transactions.csv"))
baskets = [set(row.split()) for row in df["Items"]]
n = len(baskets)
min_support = 0.6
min_conf = 0.6

def support(s):
    return sum(1 for b in baskets if s <= b) / n

items = sorted({i for b in baskets for i in b})
freq = {}
cur = [frozenset([i]) for i in items if support({i}) >= min_support]
k = 1
while cur:
    for s in cur:
        freq[s] = support(s)
    cand = {a | b for a in cur for b in cur if len(a | b) == k + 1}
    cur = [c for c in cand if support(c) >= min_support]
    k += 1

print(f"rules with conf >= {min_conf}\n")
print(f"{'rule':32}{'sup':>6}{'conf':>7}{'lift':>7}")
for s in freq:
    if len(s) < 2:
        continue
    for r in range(1, len(s)):
        for a in combinations(sorted(s), r):
            a = frozenset(a)
            b = s - a
            conf = freq[s] / freq[a]
            if conf < min_conf:
                continue
            lift = conf / support(b)   # lift > 1 means positively correlated
            rule = f"{{{','.join(sorted(a))}}} -> {{{','.join(sorted(b))}}}"
            print(f"{rule:32}{freq[s]:>6.2f}{conf:>7.2f}{lift:>7.2f}")
