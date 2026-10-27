#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "iris_subset.csv"))
x = df["sepal_length"].tolist()
n = len(x)
m = sum(x) / n

rng = max(x) - min(x)
var = sum((v - m) ** 2 for v in x) / n      # population, matches np.var default
std = var ** 0.5


def pct(x, p):
    s = sorted(x)
    r = (p / 100) * (len(s) - 1)
    lo = int(r)
    frac = r - lo
    if lo + 1 < len(s):
        return s[lo] + frac * (s[lo + 1] - s[lo])
    return s[lo]


iqr = pct(x, 75) - pct(x, 25)

print(f"range   {rng:.4f}")
print(f"var     {var:.4f}   np {np.var(x):.4f}")
print(f"std     {std:.4f}   np {np.std(x):.4f}")
print(f"IQR     {iqr:.4f}   np {np.percentile(x, 75) - np.percentile(x, 25):.4f}")
