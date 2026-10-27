#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
X = pd.read_csv(os.path.join(here, "..", "datasets", "points2d.csv")).values


def kmeans(X, k, seed=0):
    rng = np.random.default_rng(seed)
    c = X[rng.choice(len(X), k, replace=False)].astype(float)
    for _ in range(100):
        d = np.sqrt(((X[:, None] - c[None]) ** 2).sum(axis=2))
        labels = d.argmin(axis=1)
        new = np.array([X[labels == j].mean(axis=0) for j in range(k)])
        if np.allclose(new, c):   # stop when centroids dont move
            break
        c = new
    return c, labels


c, labels = kmeans(X, 2)
print("centroids:")
for j, (cx, cy) in enumerate(c):
    print(f"  cluster {j}: ({cx:.2f}, {cy:.2f})")

print("\nlabels:")
for (x, y), lab in zip(X, labels):
    print(f"  ({x:.1f}, {y:.1f}) -> {lab}")
