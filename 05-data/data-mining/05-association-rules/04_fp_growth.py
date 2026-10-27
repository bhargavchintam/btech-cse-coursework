#!/usr/bin/env python3
import os
from itertools import combinations
from collections import defaultdict
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "transactions.csv"))
txns = [r.split() for r in df["Items"]]
n = len(txns)
min_sup = 0.6
min_count = round(min_sup * n)


class Node:
    def __init__(self, item, parent):
        self.item = item
        self.count = 0
        self.parent = parent
        self.kids = {}


def order(items, freq):
    items = [i for i in items if freq.get(i, 0) >= min_count]
    return sorted(items, key=lambda i: (-freq.get(i, 0), i))


def build(transactions, freq):
    root = Node(None, None)
    header = defaultdict(list)
    for t in transactions:
        node = root
        for i in order(t, freq):
            if i not in node.kids:
                node.kids[i] = Node(i, node)
                header[i].append(node.kids[i])
            node = node.kids[i]
            node.count += 1
    return header


def mine(header, freq, suffix, found):
    for item in sorted(header, key=lambda i: (freq.get(i, 0), i)):
        base = suffix + [item]
        found[frozenset(base)] = sum(nd.count for nd in header[item])
        paths = []
        sub = defaultdict(int)
        for nd in header[item]:
            path = []
            p = nd.parent
            while p.item is not None:
                path.append(p.item)
                p = p.parent
            paths.append((path, nd.count))
            for it in path:
                sub[it] += nd.count
        sub = {it: c for it, c in sub.items() if c >= min_count}
        if sub:
            cond = []
            for path, c in paths:
                cond += [path] * c
            mine(build(cond, sub), sub, base, found)


freq1 = defaultdict(int)
for t in txns:
    for i in set(t):
        freq1[i] += 1

found = {}
mine(build(txns, freq1), freq1, [], found)


def cnt(s):
    s = set(s)
    return sum(1 for t in txns if s <= set(t))


def apriori_freq():
    items = sorted({i for t in txns for i in t})
    level = {frozenset([i]) for i in items}
    freq = {}
    k = 1
    while level:
        keep = {s for s in level if cnt(s) >= min_count}
        if not keep:
            break
        freq.update({s: cnt(s) for s in keep})
        level = {a | b for a in keep for b in keep
                 if len(a | b) == k + 1
                 and all(frozenset(x) in keep for x in combinations(a | b, k))}
        k += 1
    return freq


print(f"FP-growth frequent itemsets (min_count = {min_count}):")
for s in sorted(found, key=lambda x: (len(x), sorted(x))):
    print(f"  {sorted(s)}  count={found[s]}")

ap = apriori_freq()
print("\ncross-check against Apriori on the same data:")
print("  same itemsets? ", set(found) == set(ap))
print("  same counts?   ", all(found[s] == ap[s] for s in found))
