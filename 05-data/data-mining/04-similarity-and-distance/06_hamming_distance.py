#!/usr/bin/env python3
from scipy.spatial import distance


def hamming(a, b):
    if len(a) != len(b):
        raise ValueError("need equal length")
    return sum(x != y for x, y in zip(a, b))


print("karolin vs kathrin ->", hamming("karolin", "kathrin"))
print("1011101 vs 1001001 ->", hamming("1011101", "1001001"))

v1 = [1, 0, 1, 1, 1, 0, 1]
v2 = [1, 0, 0, 1, 0, 0, 1]
print("bit vectors ->", hamming(v1, v2), "| scipy", int(distance.hamming(v1, v2) * len(v1)))
