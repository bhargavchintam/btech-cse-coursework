#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "iris_subset.csv"))
feats = ["sepal_length", "sepal_width", "petal_length", "petal_width"]
X = df[feats].values
y = df["species"].values


def knn(Xtr, ytr, p, k=3):
    d = np.sqrt(((Xtr - p) ** 2).sum(axis=1))
    near = ytr[d.argsort()[:k]]
    votes = {}
    for lab in near:
        votes[lab] = votes.get(lab, 0) + 1
    return max(votes, key=votes.get)


rng = np.random.default_rng(1)
order = rng.permutation(len(X))
kf = 5
folds = np.array_split(order, kf)

accs = []
for i in range(kf):
    te = folds[i]
    tr = np.concatenate([folds[j] for j in range(kf) if j != i])
    Xtr, ytr = X[tr], y[tr]
    hits = sum(knn(Xtr, ytr, X[t]) == y[t] for t in te)
    a = hits / len(te)
    accs.append(a)
    print(f"fold {i + 1}: acc {a:.3f}")

print(f"mean accuracy {np.mean(accs):.3f}")
