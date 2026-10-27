#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

here = os.path.dirname(os.path.abspath(__file__))
X = pd.read_csv(os.path.join(here, "..", "datasets", "points2d.csv")).values


def kmeans(X, k, seed=1):
    rng = np.random.default_rng(seed)
    c = X[rng.choice(len(X), k, replace=False)].astype(float)
    for _ in range(100):
        d = np.sqrt(((X[:, None] - c[None]) ** 2).sum(axis=2))
        labels = d.argmin(axis=1)
        new = np.array([X[labels == j].mean(axis=0) if (labels == j).any() else c[j]
                        for j in range(k)])
        if np.allclose(new, c):
            break
        c = new
    return c, labels


def wcss(X, c, labels):
    return sum(((X[labels == j] - c[j]) ** 2).sum() for j in range(len(c)))


ks = range(1, 7)
scores = []
for k in ks:
    c, labels = kmeans(X, k)
    w = wcss(X, c, labels)
    scores.append(w)
    print(f"k={k}  wcss={w:.3f}")

plt.plot(list(ks), scores, "o-")
plt.xlabel("k")
plt.ylabel("wcss")
plt.savefig(os.path.join(here, "elbow.png"))
print("saved elbow.png")
