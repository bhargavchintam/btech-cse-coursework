#!/usr/bin/env python3
# Lab 3: Apriori frequent itemsets.
# Read the market-basket transactions and find all frequent itemsets with
# support >= min_support using the Apriori level-wise algorithm.

import os
import pandas as pd
from itertools import combinations

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "transactions.csv"))
baskets = [set(row.split()) for row in df["Items"]]
n = len(baskets)
min_support = 0.6

def support(itemset):
    c = sum(1 for b in baskets if itemset <= b)
    return c / n

items = sorted({i for b in baskets for i in b})
L = [frozenset([i]) for i in items if support({i}) >= min_support]

all_freq = []
k = 1
while L:
    for s in L:
        all_freq.append((s, support(s)))
    cand = set()
    for a in L:
        for b in L:
            u = a | b
            if len(u) == k + 1:
                cand.add(frozenset(u))
    # keep a candidate only if all its k-subsets were frequent
    prev = set(L)
    L = []
    for c in cand:
        if all(frozenset(sub) in prev for sub in combinations(c, k)):
            if support(c) >= min_support:
                L.append(c)
    k += 1

print(f"transactions={n}  min_support={min_support}\n")
for s, sup in sorted(all_freq, key=lambda t: (len(t[0]), sorted(t[0]))):
    print(f"{sup:.2f}  {{{', '.join(sorted(s))}}}")
