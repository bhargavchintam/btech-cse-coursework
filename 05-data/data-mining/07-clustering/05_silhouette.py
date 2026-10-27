#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
X = pd.read_csv(os.path.join(here, "..", "datasets", "points2d.csv")).values
labels = np.array([0, 0, 0, 0, 1, 1, 1, 1, 1, 0])

D = np.sqrt(((X[:, None] - X[None]) ** 2).sum(axis=2))
clusters = set(labels)

sils = []
for i in range(len(X)):
    same = [j for j in range(len(X)) if labels[j] == labels[i] and j != i]
    a = D[i][same].mean()
    b = min(D[i][[j for j in range(len(X)) if labels[j] == c]].mean()
            for c in clusters if c != labels[i])
    s = (b - a) / max(a, b)
    sils.append(s)
    print(f"({X[i][0]:.1f}, {X[i][1]:.1f})  a={a:.3f}  b={b:.3f}  s={s:.3f}")

print(f"\nmean silhouette: {np.mean(sils):.3f}")
