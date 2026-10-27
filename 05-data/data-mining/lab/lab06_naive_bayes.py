#!/usr/bin/env python3
# Lab 6: Naive Bayes classifier.
# Train a categorical Naive Bayes on play_tennis.csv and classify the test day
# <Sunny, Cool, High, Strong>. Uses the plain (non-smoothed) probabilities.

import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "play_tennis.csv"))
target = "PlayTennis"
attrs = [c for c in df.columns if c != target]

test = {"Outlook": "Sunny", "Temperature": "Cool", "Humidity": "High", "Wind": "Strong"}

n = len(df)
scores = {}
for label in df[target].unique():
    sub = df[df[target] == label]
    p = len(sub) / n
    for a in attrs:
        p *= (sub[a] == test[a]).sum() / len(sub)
    scores[label] = p
    print(f"P({label} | test) proportional to {p:.5f}")

pred = max(scores, key=scores.get)
print("\ntest day:", test)
print("prediction:", pred)
