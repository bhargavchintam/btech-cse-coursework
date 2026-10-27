#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "iris_subset.csv"))
x = df["petal_length"].values
y = df["petal_width"].values

mx = x.mean()
my = y.mean()
num = ((x - mx) * (y - my)).sum()
den = (((x - mx) ** 2).sum() * ((y - my) ** 2).sum()) ** 0.5
r = num / den

print("petal_length vs petal_width")
print(f"pearson r    {r:.4f}")
print(f"np corrcoef  {np.corrcoef(x, y)[0, 1]:.4f}")
