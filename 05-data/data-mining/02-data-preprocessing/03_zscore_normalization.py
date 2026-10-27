#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "students.csv"))
col = df["Marks"].dropna()

mean = col.mean()
std = col.std(ddof=0)
z = (col - mean) / std

print(f"mean {mean:.3f}  std {std:.3f}")
print("original:", col.tolist())
print("z-score :", [round(v, 3) for v in z])
print(f"\nafter: mean {z.mean():.6f}  std {z.std(ddof=0):.6f}   (should be ~0 and ~1)")
