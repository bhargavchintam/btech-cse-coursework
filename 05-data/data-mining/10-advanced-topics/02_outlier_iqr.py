#!/usr/bin/env python3
import pandas as pd

s = pd.Series([12, 15, 14, 10, 13, 11, 16, 12, 14, 13, 15, 40, 2])

q1 = s.quantile(0.25)
q3 = s.quantile(0.75)
iqr = q3 - q1
lo = q1 - 1.5 * iqr
hi = q3 + 1.5 * iqr

print(f"Q1={q1}  Q3={q3}  IQR={iqr}")
print(f"whiskers: [{lo}, {hi}]")

out = s[(s < lo) | (s > hi)]
print("\noutliers:", list(out))
