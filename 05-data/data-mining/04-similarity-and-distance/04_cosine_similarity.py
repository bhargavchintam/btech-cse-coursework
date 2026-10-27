#!/usr/bin/env python3
import numpy as np
from scipy.spatial import distance


def cosine(a, b):
    a, b = np.asarray(a, float), np.asarray(b, float)
    return a.dot(b) / (np.linalg.norm(a) * np.linalg.norm(b))  # only the angle, not the length


pairs = [
    ([1, 2, 3], [1, 2, 3]),
    ([1, 0], [0, 1]),
    ([1, 1, 1], [2, 2, 2]),
    ([1, 2, 3], [4, 5, 6]),
]
for a, b in pairs:
    s = cosine(a, b)
    print(a, b, "sim", round(s, 4), "dist", round(1 - s, 4), "| scipy sim", round(1 - distance.cosine(a, b), 4))
