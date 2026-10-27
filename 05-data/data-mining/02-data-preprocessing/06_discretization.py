#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "students.csv"))
df = df.dropna(subset=["Marks"]).copy()


def grade(m):
    if m < 60:
        return "low"
    if m < 80:
        return "med"
    return "high"


df["Level"] = df["Marks"].apply(grade)
df["EqWidth"] = pd.cut(df["Marks"], bins=3, labels=["low", "med", "high"])

print(df[["RollNo", "Marks", "Level", "EqWidth"]].to_string(index=False))
print("\nhand cut-points 60/80:")
print(df["Level"].value_counts().to_string())
print("\nequal-width (pd.cut):")
print(df["EqWidth"].value_counts().to_string())
