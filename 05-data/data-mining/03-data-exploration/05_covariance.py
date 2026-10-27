#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "iris_subset.csv"))
feats = ["sepal_length", "sepal_width", "petal_length", "petal_width"]
X = df[feats].values
n = len(X)


def cov(a, b):
    ma, mb = a.mean(), b.mean()
    return ((a - ma) * (b - mb)).sum() / (n - 1)    # n-1 like np.cov


x = X[:, 0]
y = X[:, 2]
print(f"cov(sepal_length, petal_length)  {cov(x, y):.4f}   np {np.cov(x, y)[0, 1]:.4f}")

d = len(feats)
C = [[cov(X[:, i], X[:, j]) for j in range(d)] for i in range(d)]

print("\ncovariance matrix (scratch):")
for row in C:
    print("  " + "  ".join(f"{v:7.4f}" for v in row))

print("\nnumpy cov:")
print(np.cov(X, rowvar=False))
