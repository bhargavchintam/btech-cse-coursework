#!/usr/bin/env python3
# Lab 1: Data preprocessing.
# Load students.csv, fill the missing values in the numeric columns with the
# column mean, then min-max normalize those columns to [0,1].

import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "students.csv"))

print("missing per column:")
print(df.isna().sum())

cols = ["Age", "Attendance", "StudyHours", "Marks"]
for c in cols:
    df[c] = df[c].fillna(df[c].mean())

norm = df.copy()
for c in cols:
    lo, hi = df[c].min(), df[c].max()
    norm[c] = (df[c] - lo) / (hi - lo)   # min-max scales to [0,1]

print("\nafter fill + normalize:")
print(norm.round(3).to_string(index=False))
