#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
X = pd.read_csv(os.path.join(here, "..", "datasets", "points2d.csv")).values
n = len(X)

D = np.sqrt(((X[:, None] - X[None]) ** 2).sum(axis=2))

# average linkage: distance between two clusters is the mean pairwise distance
clusters = {i: [i] for i in range(n)}
nxt = n

while len(clusters) > 1:
    best = None
    for a in clusters:
        for b in clusters:
            if a >= b:
                continue
            pairs = [D[i][j] for i in clusters[a] for j in clusters[b]]
            dist = sum(pairs) / len(pairs)
            if best is None or dist < best[0]:
                best = (dist, a, b)
    dist, a, b = best
    print(f"merge {a} + {b}  (dist {dist:.3f})  -> {nxt}   size {len(clusters[a]) + len(clusters[b])}")
    clusters[nxt] = clusters.pop(a) + clusters.pop(b)
    nxt += 1
