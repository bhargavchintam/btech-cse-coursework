# FIND-S: the most-specific hypothesis consistent with the positive examples
import pandas as pd

df = pd.read_csv("enjoysport.csv")
attrs = df.columns[:-1]
target = df.columns[-1]

h = ["0"] * len(attrs)   # start maximally specific: nothing matches yet

print("Attributes:", list(attrs))
print(f"Initial h = {h}\n")

step = 0
for _, row in df.iterrows():
    example = list(row[attrs])
    label = row[target]
    if label != "Yes":
        # FIND-S never looks at negatives; the specific boundary only ever generalises
        print(f"skip (negative)  {example}  -> {label}")
        continue
    step += 1
    for i, val in enumerate(example):
        if h[i] == "0":
            h[i] = val
        elif h[i] != val:
            h[i] = "?"
    print(f"after +ve #{step}   {example}")
    print(f"    h = {h}\n")

print("Final hypothesis:")
print("  <" + ", ".join(h) + ">")
