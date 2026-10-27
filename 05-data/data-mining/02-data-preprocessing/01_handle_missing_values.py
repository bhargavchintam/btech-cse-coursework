#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "students.csv"))
cols = ["Age", "Attendance", "StudyHours", "Marks"]

print("rows:", len(df))
print("missing per column:")
print(df.isnull().sum().to_string())

dropped = df.dropna()
print("\nafter dropna:", len(dropped), "rows left")

mean_fill = df.copy()
med_fill = df.copy()
mode_fill = df.copy()
for c in cols:
    mean_fill[c] = df[c].fillna(df[c].mean())
    med_fill[c] = df[c].fillna(df[c].median())
    mode_fill[c] = df[c].fillna(df[c].mode()[0])

print("\nMarks column (has a NaN at RollNo 9):")
print("original :", df["Marks"].tolist())
print("mean     :", [round(v, 2) for v in mean_fill["Marks"]])
print("median   :", [round(v, 2) for v in med_fill["Marks"]])
print("mode     :", [round(v, 2) for v in mode_fill["Marks"]])
