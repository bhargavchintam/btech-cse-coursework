#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd
from scipy.spatial import distance

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "points2d.csv"))
pts = df.values
n = len(pts)

D = np.zeros((n, n))
for i in range(n):
    for j in range(n):
        D[i, j] = np.sqrt(((pts[i] - pts[j]) ** 2).sum())

np.set_printoptions(precision=2, suppress=True)
print(D)

ref = distance.squareform(distance.pdist(pts))
print("matches scipy pdist:", np.allclose(D, ref))
