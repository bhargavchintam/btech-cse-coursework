#!/usr/bin/env python3
import os
import statistics as st
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "iris_subset.csv"))
x = df["petal_width"].tolist()


def mean(x):
    return sum(x) / len(x)


def median(x):
    s = sorted(x)
    n = len(s)
    m = n // 2
    if n % 2:
        return s[m]
    return (s[m - 1] + s[m]) / 2


def mode(x):
    freq = {}
    for v in x:
        freq[v] = freq.get(v, 0) + 1
    best = max(freq.values())
    for v in x:                 # first value that hits the top count
        if freq[v] == best:
            return v


print("n =", len(x))
print(f"mean    {mean(x):.4f}   np {np.mean(x):.4f}   stats {st.mean(x):.4f}")
print(f"median  {median(x):.4f}   np {np.median(x):.4f}   stats {st.median(x):.4f}")
print(f"mode    {mode(x):.4f}   stats {st.mode(x):.4f}")
