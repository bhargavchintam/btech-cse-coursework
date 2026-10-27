#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "students.csv"))
col = df["Marks"].dropna()

j = len(str(int(col.abs().max())))   # digits in the biggest value
scaled = col / (10 ** j)

print("original:", col.tolist())
print(f"j = {j}, divide by {10 ** j}")
print("scaled  :", [round(v, 3) for v in scaled])
print(f"\nmin {scaled.min():.3f}  max {scaled.max():.3f}   (all inside [-1,1])")
