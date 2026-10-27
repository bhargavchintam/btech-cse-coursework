# entropy and information gain from scratch on the PlayTennis table (ID3, Quinlan)
import numpy as np
import pandas as pd

rows = [
    ("Sunny",    "Hot",  "High",   "Weak",   "No"),
    ("Sunny",    "Hot",  "High",   "Strong", "No"),
    ("Overcast", "Hot",  "High",   "Weak",   "Yes"),
    ("Rain",     "Mild", "High",   "Weak",   "Yes"),
    ("Rain",     "Cool", "Normal", "Weak",   "Yes"),
    ("Rain",     "Cool", "Normal", "Strong", "No"),
    ("Overcast", "Cool", "Normal", "Strong", "Yes"),
    ("Sunny",    "Mild", "High",   "Weak",   "No"),
    ("Sunny",    "Cool", "Normal", "Weak",   "Yes"),
    ("Rain",     "Mild", "Normal", "Weak",   "Yes"),
    ("Sunny",    "Mild", "Normal", "Strong", "Yes"),
    ("Overcast", "Mild", "High",   "Strong", "Yes"),
    ("Overcast", "Hot",  "Normal", "Weak",   "Yes"),
    ("Rain",     "Mild", "High",   "Strong", "No"),
]
df = pd.DataFrame(rows, columns=["Outlook", "Temperature", "Humidity", "Wind", "PlayTennis"])


def entropy(labels):
    _, counts = np.unique(labels, return_counts=True)
    p = counts / counts.sum()
    return -np.sum(p * np.log2(p))


def information_gain(data, attr, target="PlayTennis"):
    parent = entropy(data[target])
    n = len(data)
    weighted = 0.0
    for v in data[attr].unique():
        subset = data[data[attr] == v][target]
        weighted += (len(subset) / n) * entropy(subset)
    return parent - weighted


base = entropy(df["PlayTennis"])
print(f"Entropy(S) = {base:.3f}   (9 Yes, 5 No out of 14)\n")

gains = {a: information_gain(df, a) for a in ["Outlook", "Temperature", "Humidity", "Wind"]}
for attr, g in sorted(gains.items(), key=lambda kv: -kv[1]):
    print(f"  Gain({attr:12s}) = {g:.3f}")

root = max(gains, key=gains.get)
print(f"\nRoot attribute chosen by ID3: {root}")

# the Overcast branch is pure Yes -> a leaf with no further splitting
for v in df["Outlook"].unique():
    sub = df[df["Outlook"] == v]["PlayTennis"]
    counts = {k: int(c) for k, c in sub.value_counts().items()}
    tag = "pure leaf" if sub.nunique() == 1 else "split further"
    print(f"  Outlook={v:9s}: {counts}  -> {tag}")
