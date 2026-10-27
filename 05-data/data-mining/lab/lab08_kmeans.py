#!/usr/bin/env python3
# Lab 8: k-means clustering.
# Cluster the 2D points in points2d.csv into k=2 groups with Lloyd's algorithm.
# The two well separated blobs should land in one cluster each.

import os
import pandas as pd
import numpy as np

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "points2d.csv"))
pts = df.to_numpy()
k = 2

rng = np.random.default_rng(0)
centroids = pts[rng.choice(len(pts), k, replace=False)]

for _ in range(100):
    d = np.array([np.sqrt(((pts - c) ** 2).sum(axis=1)) for c in centroids])
    labels = d.argmin(axis=0)
    new = np.array([pts[labels == i].mean(axis=0) for i in range(k)])
    if np.allclose(new, centroids):   # stop when centroids dont move
        break
    centroids = new

for i in range(k):
    print(f"cluster {i}  centroid=({centroids[i][0]:.2f}, {centroids[i][1]:.2f})")
    print("  points:", pts[labels == i].tolist())
