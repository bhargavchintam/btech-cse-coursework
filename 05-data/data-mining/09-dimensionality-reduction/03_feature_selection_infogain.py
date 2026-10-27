#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "play_tennis.csv"))
target = "PlayTennis"
attrs = [c for c in df.columns if c != target]


def entropy(labels):
    _, counts = np.unique(labels, return_counts=True)
    p = counts / counts.sum()
    return -(p * np.log2(p)).sum()


base = entropy(df[target])


def gain(a):
    e = 0.0
    for v in df[a].unique():
        sub = df[df[a] == v][target]
        e += len(sub) / len(df) * entropy(sub)
    return base - e


gains = {a: gain(a) for a in attrs}
print(f"entropy of {target}: {base:.3f}")
print("attributes ranked by information gain:")
for a, g in sorted(gains.items(), key=lambda kv: kv[1], reverse=True):
    print(f"  {a:12s} {g:.3f}")
