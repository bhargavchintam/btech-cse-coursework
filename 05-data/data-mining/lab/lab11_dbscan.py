#!/usr/bin/env python3
# Lab 11: DBSCAN clustering.
# Density based clustering of points2d.csv with eps=2.0 and min_samples=2.
# Core points grow a cluster over their neighbours; the rest is noise (-1).

import os
import pandas as pd
import numpy as np

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "points2d.csv"))
pts = df.to_numpy()
n = len(pts)
eps = 2.0
min_samples = 2

def region(i):
    return [j for j in range(n) if np.sqrt(((pts[i] - pts[j]) ** 2).sum()) <= eps]

labels = [None] * n
cid = 0
for i in range(n):
    if labels[i] is not None:
        continue
    nb = region(i)
    if len(nb) < min_samples:
        labels[i] = -1
        continue
    labels[i] = cid
    seeds = [j for j in nb if j != i]
    while seeds:
        j = seeds.pop()
        if labels[j] == -1:
            labels[j] = cid
        if labels[j] is not None:
            continue
        labels[j] = cid
        jn = region(j)
        if len(jn) >= min_samples:
            seeds += jn
    cid += 1

print(f"eps={eps}  min_samples={min_samples}  clusters={cid}")
for c in range(cid):
    print(f"cluster {c}:", [tuple(pts[i].tolist()) for i in range(n) if labels[i] == c])
noise = [tuple(pts[i].tolist()) for i in range(n) if labels[i] == -1]
print("noise:", noise)
