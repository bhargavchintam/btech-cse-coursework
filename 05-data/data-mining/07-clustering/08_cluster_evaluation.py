#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd
from itertools import combinations

here = os.path.dirname(os.path.abspath(__file__))
X = pd.read_csv(os.path.join(here, "..", "datasets", "points2d.csv")).values
true = np.array([0, 0, 0, 0, 1, 1, 1, 1, 1, 0])
pred = np.array([1, 1, 1, 1, 0, 0, 0, 0, 0, 1])

c = np.array([X[pred == j].mean(axis=0) for j in set(pred)])
sse = sum(((X[pred == j] - c[i]) ** 2).sum() for i, j in enumerate(sorted(set(pred))))
print(f"sse: {sse:.3f}")

# purity: each cluster votes for its most common true class
total = 0
for j in set(pred):
    counts = np.bincount(true[pred == j])
    total += counts.max()
print(f"purity: {total / len(true):.3f}")

# rand index: agreements over all pairs
a = b = 0
for i, k in combinations(range(len(X)), 2):
    st = true[i] == true[k]
    sp = pred[i] == pred[k]
    if st and sp:
        a += 1
    elif not st and not sp:
        b += 1
pairs = len(X) * (len(X) - 1) // 2
print(f"rand index: {(a + b) / pairs:.3f}")
