#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
X = pd.read_csv(os.path.join(here, "..", "datasets", "points2d.csv")).values
n = len(X)

D = np.sqrt(((X[:, None] - X[None]) ** 2).sum(axis=2))


def cost(medoids):
    return D[:, medoids].min(axis=1).sum()


def pam(k, seed=0):
    rng = np.random.default_rng(seed)
    medoids = list(rng.choice(n, k, replace=False))
    best = cost(medoids)
    improved = True
    while improved:
        improved = False
        for i in range(k):
            for h in range(n):
                if h in medoids:
                    continue
                cand = medoids.copy()
                cand[i] = h
                c = cost(cand)
                if c < best:
                    medoids, best = cand, c
                    improved = True
    labels = D[:, medoids].argmin(axis=1)
    return medoids, labels


medoids, labels = pam(2)
print("medoids:")
for j, m in enumerate(medoids):
    print(f"  cluster {j}: point {m} = ({X[m][0]:.1f}, {X[m][1]:.1f})")

print("\nlabels:")
for i, ((x, y), lab) in enumerate(zip(X, labels)):
    print(f"  ({x:.1f}, {y:.1f}) -> {lab}")
