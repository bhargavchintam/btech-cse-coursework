#!/usr/bin/env python3
# Lab 14: PageRank.
# Rank the pages of a small web graph by the PageRank algorithm (damping 0.85)
# using power iteration. The final ranks add up to 1.

import numpy as np

pages = ["A", "B", "C", "D"]
links = {
    "A": ["B", "C"],
    "B": ["C"],
    "C": ["A"],
    "D": ["C"],
}

n = len(pages)
idx = {p: i for i, p in enumerate(pages)}
M = np.zeros((n, n))
for p, outs in links.items():
    for q in outs:
        M[idx[q]][idx[p]] = 1 / len(outs)

d = 0.85
rank = np.ones(n) / n
for _ in range(100):
    new = (1 - d) / n + d * M @ rank
    if np.allclose(new, rank):
        break
    rank = new

for p, r in sorted(zip(pages, rank), key=lambda t: -t[1]):
    print(f"{p}: {r:.4f}")
print(f"sum = {rank.sum():.4f}")
