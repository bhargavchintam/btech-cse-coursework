#!/usr/bin/env python3
import os
import math
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "play_tennis.csv"))
target = "PlayTennis"


def entropy(rows):
    n = len(rows)
    ent = 0.0
    for c in rows[target].value_counts():
        p = c / n
        ent -= p * math.log2(p)
    return ent


def gain(rows, attr):
    n = len(rows)
    g = entropy(rows)
    for _, sub in rows.groupby(attr):
        g -= (len(sub) / n) * entropy(sub)
    return g


def build(rows, attrs):
    labels = rows[target]
    if labels.nunique() == 1:
        return labels.iloc[0]
    if not attrs:
        return labels.mode()[0]
    best = max(attrs, key=lambda a: gain(rows, a))
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
print("info gain at root:")
for a in attrs:
    print(f"  {a:12s} {gain(df, a):.3f}")

tree = build(df, attrs)
print("\ntree:")
show(tree)
