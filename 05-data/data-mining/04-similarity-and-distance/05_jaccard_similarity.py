#!/usr/bin/env python3
# Bindu Bhargava  05-08-20
import numpy as np
from scipy.spatial import distance


def jaccard_sets(a, b):
    a, b = set(a), set(b)
    return len(a & b) / len(a | b)


def jaccard_bits(a, b):
    a, b = np.asarray(a, bool), np.asarray(b, bool)
    return (a & b).sum() / (a | b).sum()


s1 = {1, 2, 3}
s2 = {2, 3, 4}
print("sets", s1, s2, "->", jaccard_sets(s1, s2))

v1 = [1, 0, 1, 1, 0]
v2 = [0, 0, 1, 1, 1]
print("bits", v1, v2, "->", round(jaccard_bits(v1, v2), 4), "| scipy", round(1 - distance.jaccard(v1, v2), 4))
