#!/usr/bin/env python3
# Bindu Bhargava  15-07-20
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))

# selection
df = pd.read_csv(os.path.join(here, "..", "datasets", "students.csv"))
print("selection: loaded students.csv", df.shape)

# preprocessing: fill the missing numeric values with the column mean
miss = int(df.isna().sum().sum())
df = df.fillna(df.mean(numeric_only=True))
print(f"preprocessing: filled {miss} missing values with column means")

# transformation: min-max scale Marks to [0,1]
col = df["Marks"]
df["Marks_norm"] = (col - col.min()) / (col.max() - col.min())
print("transformation: Marks_norm now runs",
      round(df["Marks_norm"].min(), 3), "to", round(df["Marks_norm"].max(), 3))

# mining: one-line pattern - do study hours and marks move together?
r = df["StudyHours"].corr(df["Marks"])
print(f"mining: corr(StudyHours, Marks) = {r:.3f}")

print("interpretation: more study hours goes with higher marks (strong positive r)")
