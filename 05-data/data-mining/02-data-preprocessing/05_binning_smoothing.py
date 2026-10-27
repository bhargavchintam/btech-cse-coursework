#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "students.csv"))
x = sorted(df["Marks"].dropna().tolist())
k = 3
print("sorted data:", x)

mn, mx = min(x), max(x)
w = (mx - mn) / k
width_bins = [[] for _ in range(k)]
for v in x:
    i = min(int((v - mn) / w), k - 1)
    width_bins[i].append(v)

n = len(x)
size = n // k
depth_bins = [x[i:i + size] for i in range(0, size * k, size)]
depth_bins[-1] += x[size * k:]       # leftover rows go in the last bin

print("\nequal-width bins:")
for b in width_bins:
    print(" ", b)
print("equal-depth bins:")
for b in depth_bins:
    print(" ", b)


def by_mean(bins):
    return [[round(sum(b) / len(b), 1)] * len(b) for b in bins]


def by_median(bins):
    out = []
    for b in bins:
        s = sorted(b)
        m = s[len(s) // 2] if len(s) % 2 else (s[len(s) // 2 - 1] + s[len(s) // 2]) / 2
        out.append([m] * len(b))
    return out


def by_bounds(bins):
    return [[b[0] if v - b[0] <= b[-1] - v else b[-1] for v in b] for b in bins]


print("\nsmoothing the equal-depth bins:")
print("by mean    :", by_mean(depth_bins))
print("by median  :", by_median(depth_bins))
print("by boundary:", by_bounds(depth_bins))
