#!/usr/bin/env python3
# Lab 12: Simple linear regression.
# Fit Marks = m*StudyHours + b on students.csv by least squares (rows with
# missing StudyHours or Marks are dropped). Report the line and R-squared.

import os
import pandas as pd
import numpy as np

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "students.csv"))
d = df[["StudyHours", "Marks"]].dropna()

x = d["StudyHours"].to_numpy()
y = d["Marks"].to_numpy()
xm, ym = x.mean(), y.mean()

m = ((x - xm) * (y - ym)).sum() / ((x - xm) ** 2).sum()
b = ym - m * xm

pred = m * x + b
ss_res = ((y - pred) ** 2).sum()
ss_tot = ((y - ym) ** 2).sum()
r2 = 1 - ss_res / ss_tot

print(f"Marks = {m:.2f} * StudyHours + {b:.2f}")
print(f"R^2 = {r2:.3f}")
print(f"predict StudyHours=5 -> {m * 5 + b:.1f} marks")
