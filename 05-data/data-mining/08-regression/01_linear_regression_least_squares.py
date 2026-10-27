#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "students.csv"))
df = df.dropna(subset=["StudyHours", "Marks"])

x = df["StudyHours"].values
y = df["Marks"].values
n = len(x)

xbar = x.mean()
ybar = y.mean()
b = ((x - xbar) * (y - ybar)).sum() / ((x - xbar) ** 2).sum()
a = ybar - b * xbar

print(f"n = {n}")
print(f"slope     b = {b:.3f}")
print(f"intercept a = {a:.3f}")
print(f"line: Marks = {a:.2f} + {b:.2f} * StudyHours")

for h in [3, 4, 7]:
    print(f"StudyHours = {h}  ->  Marks = {a + b * h:.1f}")
