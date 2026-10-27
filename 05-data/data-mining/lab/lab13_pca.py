#!/usr/bin/env python3
# Lab 13: Principal component analysis.
# Standardize the four iris_subset.csv features, build the covariance matrix and
# take its eigenvectors. Print the explained variance ratio of each component.

import os
import pandas as pd
import numpy as np

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "iris_subset.csv"))

feat = ["sepal_length", "sepal_width", "petal_length", "petal_width"]
X = df[feat].to_numpy()
X = (X - X.mean(axis=0)) / X.std(axis=0)

cov = np.cov(X, rowvar=False)
vals, vecs = np.linalg.eigh(cov)
order = vals.argsort()[::-1]
vals = vals[order]

ratio = vals / vals.sum()
print("explained variance ratio:")
for i, r in enumerate(ratio):
    print(f"  PC{i + 1}: {r:.3f}")
print(f"first two components keep {ratio[:2].sum():.3f} of the variance")
