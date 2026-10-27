#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
X = pd.read_csv(os.path.join(here, "..", "datasets", "points2d.csv")).values
n = len(X)
eps = 2.0
minpts = 3

D = np.sqrt(((X[:, None] - X[None]) ** 2).sum(axis=2))
neigh = [np.where(D[i] <= eps)[0].tolist() for i in range(n)]
core = [len(neigh[i]) >= minpts for i in range(n)]

labels = [-1] * n
cid = 0
for i in range(n):
    if not core[i] or labels[i] != -1:
        continue
    labels[i] = cid
    stack = [i]
    while stack:
        p = stack.pop()
        for q in neigh[p]:
            if labels[q] == -1:
                labels[q] = cid
                if core[q]:
                    stack.append(q)
    cid += 1

for i in range(n):
    if labels[i] == -1:
        kind = "noise"
    elif core[i]:
        kind = "core"
    else:
        kind = "border"
    print(f"({X[i][0]:.1f}, {X[i][1]:.1f}) -> cluster {labels[i]:>2}  {kind}")
