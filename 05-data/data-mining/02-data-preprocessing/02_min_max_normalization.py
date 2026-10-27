#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "students.csv"))
col = df["Marks"].dropna()

mn, mx = col.min(), col.max()
scaled = (col - mn) / (mx - mn)      # min-max scales to [0,1]

print("original:", col.tolist())
print("scaled  :", [round(v, 3) for v in scaled])
print(f"\nmin {scaled.min():.3f}  max {scaled.max():.3f}   (should be 0 and 1)")
