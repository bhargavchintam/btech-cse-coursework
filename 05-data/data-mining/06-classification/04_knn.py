#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "iris_subset.csv"))
feats = ["sepal_length", "sepal_width", "petal_length", "petal_width"]
X = df[feats].values
y = df["species"].values


def knn(p, k=3):
    d = np.sqrt(((X - p) ** 2).sum(axis=1))
    near = y[d.argsort()[:k]]
    votes = {}
    for lab in near:
        votes[lab] = votes.get(lab, 0) + 1
    return max(votes, key=votes.get)


tests = [
    [5.0, 3.4, 1.5, 0.2],
    [4.8, 3.1, 1.5, 0.1],
    [6.5, 3.0, 4.6, 1.4],
    [6.0, 2.7, 4.2, 1.3],
]
for p in tests:
    print(p, "->", knn(np.array(p, dtype=float)))
