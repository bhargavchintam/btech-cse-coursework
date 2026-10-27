#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "play_tennis.csv"))
col = df["Outlook"]

code = {c: i for i, c in enumerate(sorted(col.unique()))}
labels = col.map(code)
print("label map:", code)
print("label encoded:", labels.tolist())

onehot = pd.get_dummies(col, prefix="Outlook").astype(int)
print("\none-hot encoded:")
print(onehot.to_string(index=False))
