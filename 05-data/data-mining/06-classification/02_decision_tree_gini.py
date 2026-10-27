#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "play_tennis.csv"))
target = "PlayTennis"


def gini(rows):
    n = len(rows)
    g = 1.0
    for c in rows[target].value_counts():
        g -= (c / n) ** 2
    return g


def split_gini(rows, attr):
    n = len(rows)
    s = 0.0
    for _, sub in rows.groupby(attr):
        s += (len(sub) / n) * gini(sub)
    return s


def build(rows, attrs):
    labels = rows[target]
    if labels.nunique() == 1:
        return labels.iloc[0]
    if not attrs:
        return labels.mode()[0]
    best = min(attrs, key=lambda a: split_gini(rows, a))
    rest = [a for a in attrs if a != best]
    tree = {best: {}}
    for val, sub in rows.groupby(best):
        tree[best][val] = build(sub, rest)
    return tree


def show(tree, depth=0):
    if not isinstance(tree, dict):
        print("  " * depth + "-> " + tree)
        return
    for attr, branches in tree.items():
        for val, sub in branches.items():
            print("  " * depth + f"{attr} = {val}")
            show(sub, depth + 1)


attrs = [c for c in df.columns if c != target]
print("weighted gini per attribute (lower is better):")
for a in attrs:
    print(f"  {a:12s} {split_gini(df, a):.3f}")

tree = build(df, attrs)
print("\ntree:")
show(tree)
