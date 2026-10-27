#!/usr/bin/env python3
# Bindu Bhargava  09-09-20
import os
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "iris_subset.csv"))
feats = ["sepal_length", "sepal_width", "petal_length", "petal_width"]
X = df[feats].values
y = df["species"].values
classes = np.unique(y)


def stump(Xs, ys):
    best = None
    for f in range(Xs.shape[1]):
        vals = np.unique(Xs[:, f])
        for t in (vals[:-1] + vals[1:]) / 2:
            left = Xs[:, f] <= t
            for a in classes:
                b = classes[classes != a][0]
                pred = np.where(left, a, b)
                acc = (pred == ys).mean()
                if best is None or acc > best[0]:
                    best = (acc, f, t, a, b)
    return best


def predict(s, row):
    _, f, t, a, b = s
    return a if row[f] <= t else b


rng = np.random.default_rng(0)
stumps = []
for _ in range(15):
    idx = rng.integers(0, len(X), len(X))   # bootstrap sample, with replacement
    stumps.append(stump(X[idx], y[idx]))

preds = []
for row in X:
    votes = {}
    for s in stumps:
        c = predict(s, row)
        votes[c] = votes.get(c, 0) + 1
    preds.append(max(votes, key=votes.get))
preds = np.array(preds)

used = [feats[s[1]] for s in stumps]
print("stumps split on:", used[:5], "...")
print("accuracy:", (preds == y).mean())
