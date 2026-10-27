#!/usr/bin/env python3
import numpy as np
from scipy.spatial import distance


def euclidean(a, b):
    a, b = np.asarray(a, float), np.asarray(b, float)
    return np.sqrt(((a - b) ** 2).sum())


pairs = [
    ([0, 0], [3, 4]),
    ([1, 2, 3], [4, 5, 6]),
    ([2.0, -1.0], [2.0, -1.0]),
]
for a, b in pairs:
    d = euclidean(a, b)
    print(a, b, "->", round(d, 4), "| scipy", round(distance.euclidean(a, b), 4))
