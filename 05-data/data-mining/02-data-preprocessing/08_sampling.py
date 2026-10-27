#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "play_tennis.csv"))
n = len(df)

srs = df.sample(5, random_state=1)
print("simple random (5 rows):")
print(srs.to_string())

k = n // 5
sysamp = df.iloc[1::k]
print(f"\nsystematic (every {k}th from row 1):")
print(sysamp.to_string())

parts = []
for c, g in df.groupby("PlayTennis"):
    parts.append(g.sample(frac=0.5, random_state=1))
strat = pd.concat(parts)
print("\nstratified (50% of each PlayTennis class):")
print(strat.to_string())
print("\nfull class counts:")
print(df["PlayTennis"].value_counts().to_string())
print("strat class counts:")
print(strat["PlayTennis"].value_counts().to_string())
