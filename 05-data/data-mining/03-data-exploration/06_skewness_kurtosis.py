#!/usr/bin/env python3
import numpy as np
from scipy import stats

x = [1, 2, 2, 3, 3, 3, 4, 5, 8, 20]     # long right tail, expect positive skew
n = len(x)
m = sum(x) / n
m2 = sum((v - m) ** 2 for v in x) / n
m3 = sum((v - m) ** 3 for v in x) / n
m4 = sum((v - m) ** 4 for v in x) / n

skew = m3 / m2 ** 1.5
kurt = m4 / m2 ** 2 - 3      # excess kurtosis, scipy's default

print(f"skew  {skew:.4f}   scipy {stats.skew(x):.4f}")
print(f"kurt  {kurt:.4f}   scipy {stats.kurtosis(x):.4f}")
print("sign:", "right / positive skew" if skew > 0 else "left / negative skew")
