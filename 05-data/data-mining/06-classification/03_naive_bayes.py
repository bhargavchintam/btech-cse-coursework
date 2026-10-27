#!/usr/bin/env python3
# Bindu Bhargava  05-08-20
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "play_tennis.csv"))
target = "PlayTennis"
attrs = [c for c in df.columns if c != target]
classes = df[target].unique()

test = {"Outlook": "Sunny", "Temperature": "Cool", "Humidity": "High", "Wind": "Strong"}


def posterior(c):
    sub = df[df[target] == c]
    p = len(sub) / len(df)
    for a in attrs:
        k = df[a].nunique()
        cnt = (sub[a] == test[a]).sum()
        p *= (cnt + 1) / (len(sub) + k)   # laplace, +1 so no zero probs
    return p


post = {c: posterior(c) for c in classes}
total = sum(post.values())

print("test day:", test)
print("\nposteriors (raw / normalized):")
for c in classes:
    print(f"  {c:4s} {post[c]:.6f}   {post[c] / total:.3f}")

pred = max(post, key=post.get)
print("\nprediction:", pred)
