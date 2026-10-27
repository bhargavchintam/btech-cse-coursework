#!/usr/bin/env python3
# Lab 2: Descriptive statistics.
# Compute mean, median, mode, variance, standard deviation and the quartiles
# for the Marks column of students.csv (missing values dropped first).

import os
import pandas as pd
import numpy as np

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "students.csv"))

x = df["Marks"].dropna().to_numpy()

mean = x.mean()
median = np.median(x)
vals, counts = np.unique(x, return_counts=True)
mode = vals[counts.argmax()]
var = x.var(ddof=1)
sd = x.std(ddof=1)
q1, q2, q3 = np.percentile(x, [25, 50, 75])

print(f"n        {len(x)}")
print(f"mean     {mean:.2f}")
print(f"median   {median:.2f}")
print(f"mode     {mode:.2f}")
print(f"variance {var:.2f}")
print(f"std dev  {sd:.2f}")
print(f"Q1 Q2 Q3 {q1:.2f} {q2:.2f} {q3:.2f}")
print(f"IQR      {q3 - q1:.2f}")
