#!/usr/bin/env python3
# Lab 9: k-medoids (PAM) clustering.
# Cluster points2d.csv into k=2 clusters where each centre is an actual data
# point (a medoid). Swap medoids while the total distance keeps dropping.

import os
import pandas as pd
import numpy as np
from itertools import product

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "points2d.csv"))
pts = df.to_numpy()
n = len(pts)
k = 2

D = np.array([[np.sqrt(((pts[i] - pts[j]) ** 2).sum()) for j in range(n)] for i in range(n)])

def cost(medoids):
    return D[:, medoids].min(axis=1).sum()

medoids = [0, n - 1]
best = cost(medoids)
improved = True
while improved:
    improved = False
    for m, o in product(range(k), range(n)):
        if o in medoids:
            continue
        cand = medoids.copy()
        cand[m] = o
        c = cost(cand)
        if c < best:
            best, medoids, improved = c, cand, True

labels = D[:, medoids].argmin(axis=1)
print(f"total cost = {best:.2f}")
for i, m in enumerate(medoids):
    print(f"cluster {i}  medoid={tuple(pts[m].tolist())}")
    print("  points:", pts[labels == i].tolist())
