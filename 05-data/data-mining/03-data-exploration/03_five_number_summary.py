#!/usr/bin/env python3
import numpy as np

x = [12, 14, 14, 15, 16, 18, 19, 20, 21, 48]     # 48 is the odd one out


def pct(x, p):
    s = sorted(x)
    r = (p / 100) * (len(s) - 1)
    lo = int(r)
    frac = r - lo
    if lo + 1 < len(s):
        return s[lo] + frac * (s[lo + 1] - s[lo])
    return s[lo]


lo = min(x)
q1 = pct(x, 25)
med = pct(x, 50)
q3 = pct(x, 75)
hi = max(x)
iqr = q3 - q1
lower = q1 - 1.5 * iqr
upper = q3 + 1.5 * iqr
out = [v for v in x if v < lower or v > upper]

print(f"min  {lo}")
print(f"Q1   {q1}   np {np.percentile(x, 25)}")
print(f"med  {med}   np {np.percentile(x, 50)}")
print(f"Q3   {q3}   np {np.percentile(x, 75)}")
print(f"max  {hi}")
print(f"IQR  {iqr}   fences [{lower}, {upper}]")
print("outliers:", out)
