#!/usr/bin/env python3
# Lab 5: ID3 decision tree.
# Build a decision tree on play_tennis.csv using entropy and information gain.
# The attribute with the highest gain at the root should come out as Outlook.

import os
import math
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "play_tennis.csv"))
target = "PlayTennis"

def entropy(rows):
    total = len(rows)
    e = 0.0
    for _, c in rows[target].value_counts().items():
        p = c / total
        e -= p * math.log2(p)
    return e

def gain(rows, attr):
    total = len(rows)
    g = entropy(rows)
    for v in rows[attr].unique():
        sub = rows[rows[attr] == v]
        g -= len(sub) / total * entropy(sub)
    return g

def build(rows, attrs):
    labels = rows[target].unique()
    if len(labels) == 1:
        return labels[0]
    if not attrs:
        return rows[target].mode()[0]
    best = max(attrs, key=lambda a: gain(rows, a))
    tree = {best: {}}
    for v in rows[best].unique():
        sub = rows[rows[best] == v]
        tree[best][v] = build(sub, [a for a in attrs if a != best])
    return tree

attrs = [c for c in df.columns if c != target]
gains = {a: round(gain(df, a), 3) for a in attrs}
print("info gain at root:", gains)

tree = build(df, attrs)

def show(node, depth=0):
    if not isinstance(node, dict):
        print("  " * depth + "-> " + node)
        return
    attr = next(iter(node))
    for v, child in node[attr].items():
        print("  " * depth + f"{attr} = {v}")
        show(child, depth + 1)

print("\ntree:")
show(tree)
