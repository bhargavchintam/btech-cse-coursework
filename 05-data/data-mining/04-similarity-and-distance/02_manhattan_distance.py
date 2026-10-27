#!/usr/bin/env python3
import numpy as np
from scipy.spatial import distance


def manhattan(a, b):
    a, b = np.asarray(a, float), np.asarray(b, float)
    return np.abs(a - b).sum()


pairs = [
    ([0, 0], [3, 4]),
    ([1, 2, 3], [4, 5, 6]),
    ([5, 5], [5, 5]),
]
for a, b in pairs:
    d = manhattan(a, b)
    print(a, b, "->", d, "| scipy", distance.cityblock(a, b))
