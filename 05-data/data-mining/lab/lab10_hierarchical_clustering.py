#!/usr/bin/env python3
# Lab 10: Agglomerative hierarchical clustering.
# Bottom-up clustering of points2d.csv with complete linkage. Print the merge
# order and cut the tree at k=2 to show the two clusters.

import os
import pandas as pd
import numpy as np

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "points2d.csv"))
pts = df.to_numpy()
n = len(pts)

D = np.array([[np.sqrt(((pts[i] - pts[j]) ** 2).sum()) for j in range(n)] for i in range(n)])
clusters = {i: [i] for i in range(n)}

def linkage(a, b):
    return max(D[i][j] for i in clusters[a] for j in clusters[b])

nxt = n
while len(clusters) > 1:
    keys = list(clusters)
    a, b = min(((x, y) for i, x in enumerate(keys) for y in keys[i + 1:]),
               key=lambda p: linkage(*p))
    print(f"merge {clusters[a]} + {clusters[b]}  dist={linkage(a, b):.2f}")
    clusters[nxt] = clusters[a] + clusters[b]
    del clusters[a], clusters[b]
    nxt += 1
    if len(clusters) == 2:
        print("\ncut at k=2:")
        for c in clusters.values():
            print("  ", [tuple(pts[i].tolist()) for i in c])
