# ID3 (Quinlan): grow a decision tree by greedily splitting on highest information gain
import numpy as np
import pandas as pd

df = pd.read_csv("playtennis.csv")
target = "PlayTennis"


def entropy(labels):
    _, counts = np.unique(labels, return_counts=True)
    p = counts / counts.sum()
    return -np.sum(p * np.log2(p))


def info_gain(data, attr):
    parent = entropy(data[target])
    n = len(data)
    rem = 0.0
    for v in data[attr].unique():
        sub = data[data[attr] == v][target]
        rem += (len(sub) / n) * entropy(sub)
    return parent - rem


def id3(data, attrs):
    labels = data[target]
    if labels.nunique() == 1:
        return labels.iloc[0]                       # pure node -> leaf
    if not attrs:
        return labels.mode()[0]                     # no attributes left -> majority vote
    gains = {a: info_gain(data, a) for a in attrs}
    best = max(gains, key=gains.get)
    tree = {best: {}}
    for v in data[best].unique():
        sub = data[data[best] == v]
        remaining = [a for a in attrs if a != best]
        tree[best][v] = id3(sub, remaining)
    return tree


def show(node, indent=""):
    if not isinstance(node, dict):
        print(indent + "-> " + node)
        return
    attr = next(iter(node))
    for v, child in node[attr].items():
        print(f"{indent}{attr} = {v}")
        show(child, indent + "    ")


def classify(node, sample):
    while isinstance(node, dict):
        attr = next(iter(node))
        node = node[attr][sample[attr]]
    return node


attributes = [c for c in df.columns if c != target]
print(f"Entropy(S) = {entropy(df[target]):.3f}   (9 Yes, 5 No)")
for a in attributes:
    print(f"  Gain({a:12s}) = {info_gain(df, a):.3f}")

tree = id3(df, attributes)
print("\nDecision tree:")
show(tree)

new_sample = {"Outlook": "Sunny", "Temperature": "Cool", "Humidity": "High", "Wind": "Strong"}
print(f"\nClassify {new_sample}")
print("  PlayTennis ->", classify(tree, new_sample))
