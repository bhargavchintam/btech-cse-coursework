#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "students.csv"))
df = df.dropna(subset=["StudyHours", "Marks"])

x = df["StudyHours"].values.astype(float)
y = df["Marks"].values.astype(float)
n = len(x)

w = 0.0
b = 0.0
lr = 0.02
for i in range(20000):
    pred = w * x + b
    err = pred - y
    dw = (2 / n) * (err * x).sum()
    db = (2 / n) * err.sum()
    w -= lr * dw
    b -= lr * db

print(f"gradient descent, lr={lr}, 20000 steps")
print(f"slope     w = {w:.3f}")
print(f"intercept b = {b:.3f}")

xbar, ybar = x.mean(), y.mean()
bc = ((x - xbar) * (y - ybar)).sum() / ((x - xbar) ** 2).sum()
ac = ybar - bc * xbar
print(f"closed form: w = {bc:.3f}  b = {ac:.3f}")
