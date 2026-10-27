#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "students.csv"))

print("shape:", df.shape)
print("\ncolumns:", list(df.columns))

print("\ndtypes:")
print(df.dtypes)

print("\nhead:")
print(df.head())

print("\ndescribe:")
print(df.describe())
