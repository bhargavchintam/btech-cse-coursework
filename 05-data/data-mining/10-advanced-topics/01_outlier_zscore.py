#!/usr/bin/env python3
import numpy as np

x = np.array([78, 85, 82, 90, 76, 88, 79, 91, 84, 83, 77, 86, 80, 89, 81], dtype=float)
x = np.append(x, 250)   # someone fat-fingered a mark

z = (x - x.mean()) / x.std()
out = np.abs(z) > 3

for v, zi in zip(x, z):
    tag = "OUTLIER" if abs(zi) > 3 else ""
    print(f"{v:7.1f}  z={zi:6.2f}  {tag}")

print("\noutliers:", x[out])
