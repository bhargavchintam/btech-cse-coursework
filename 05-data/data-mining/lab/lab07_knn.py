#!/usr/bin/env python3
# Lab 7: k-nearest neighbours.
# Classify a couple of test flowers from iris_subset.csv with KNN (k=3),
# using Euclidean distance on the four measurements.

import os
import pandas as pd
import numpy as np

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "iris_subset.csv"))

feat = ["sepal_length", "sepal_width", "petal_length", "petal_width"]
X = df[feat].to_numpy()
y = df["species"].to_numpy()
k = 3

def classify(p):
    d = np.sqrt(((X - p) ** 2).sum(axis=1))
    idx = d.argsort()[:k]
    vals, counts = np.unique(y[idx], return_counts=True)
    return vals[counts.argmax()]

tests = [
    [5.0, 3.4, 1.5, 0.2],
    [6.5, 3.0, 4.6, 1.4],
]
for t in tests:
    print(t, "->", classify(np.array(t)))
