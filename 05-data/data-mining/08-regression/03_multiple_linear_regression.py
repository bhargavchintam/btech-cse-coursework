#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "students.csv"))
feats = ["StudyHours", "Attendance"]
df = df.dropna(subset=feats + ["Marks"])

X = df[feats].values.astype(float)
y = df["Marks"].values.astype(float)
X = np.column_stack([np.ones(len(X)), X])   # bias column

theta = np.linalg.inv(X.T @ X) @ X.T @ y

print("coefficients (normal equation):")
print(f"  intercept    {theta[0]:.3f}")
for f, c in zip(feats, theta[1:]):
    print(f"  {f:11s}  {c:.3f}")

pred = X @ theta
ss_res = ((y - pred) ** 2).sum()
ss_tot = ((y - y.mean()) ** 2).sum()
print(f"R2 on the fit = {1 - ss_res / ss_tot:.4f}")
