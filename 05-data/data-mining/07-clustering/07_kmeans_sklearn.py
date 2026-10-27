#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd
from sklearn.cluster import KMeans

here = os.path.dirname(os.path.abspath(__file__))
X = pd.read_csv(os.path.join(here, "..", "datasets", "points2d.csv")).values


def mine(X, k, seed=0):
    rng = np.random.default_rng(seed)
    c = X[rng.choice(len(X), k, replace=False)].astype(float)
    for _ in range(100):
        d = np.sqrt(((X[:, None] - c[None]) ** 2).sum(axis=2))
        labels = d.argmin(axis=1)
        new = np.array([X[labels == j].mean(axis=0) for j in range(k)])
        if np.allclose(new, c):
            break
        c = new
    return labels


km = KMeans(n_clusters=2, n_init=10, random_state=0).fit(X)
sk = km.labels_
my = mine(X, 2)

print("sklearn centroids:")
for cx, cy in km.cluster_centers_:
    print(f"  ({cx:.2f}, {cy:.2f})")

print("\n   point        sklearn  scratch")
for (x, y), a, b in zip(X, sk, my):
    print(f"  ({x:.1f}, {y:.1f})     {a}        {b}")

# labels can be swapped (0<->1) yet still be the same grouping
same = (sk == my).all() or (sk == 1 - my).all()
print("\nsame 2-way split:", same)
