#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "iris_subset.csv"))
feats = ["sepal_length", "sepal_width", "petal_length", "petal_width"]
X = df[feats].values.astype(float)
y = (df["species"] == "versicolor").astype(int).values

X = (X - X.mean(axis=0)) / X.std(axis=0)   # standardize so gd behaves


def sigmoid(z):
    return 1 / (1 + np.exp(-z))


w = np.zeros(X.shape[1])
b = 0.0
lr = 0.1
n = len(y)
for i in range(5000):
    p = sigmoid(X @ w + b)
    err = p - y
    w -= lr * (X.T @ err) / n
    b -= lr * err.sum() / n

p = sigmoid(X @ w + b)
loss = -(y * np.log(p) + (1 - y) * np.log(1 - p)).mean()
pred = (p >= 0.5).astype(int)
acc = (pred == y).mean()

print("weights:", np.round(w, 3))
print(f"bias:    {b:.3f}")
print(f"log loss: {loss:.4f}")
print(f"accuracy: {acc:.3f}")
