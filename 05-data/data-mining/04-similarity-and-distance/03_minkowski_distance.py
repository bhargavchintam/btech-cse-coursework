#!/usr/bin/env python3
import numpy as np
from scipy.spatial import distance


def minkowski(a, b, p):
    a, b = np.asarray(a, float), np.asarray(b, float)
    if np.isinf(p):
        return np.abs(a - b).max()
    return (np.abs(a - b) ** p).sum() ** (1 / p)


a = [1, 2, 3]
b = [4, 0, 3]
print("p=1  ", round(minkowski(a, b, 1), 4), " manhattan", distance.cityblock(a, b))
print("p=2  ", round(minkowski(a, b, 2), 4), " euclidean", round(distance.euclidean(a, b), 4))
print("p=3  ", round(minkowski(a, b, 3), 4), " scipy    ", round(distance.minkowski(a, b, 3), 4))
print("p=inf", round(minkowski(a, b, np.inf), 4), " chebyshev", distance.chebyshev(a, b))
