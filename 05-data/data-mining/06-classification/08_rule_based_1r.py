#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "play_tennis.csv"))
target = "PlayTennis"
attrs = [c for c in df.columns if c != target]


def rule_for(attr):
    rule = {}
    err = 0
    for val, sub in df.groupby(attr):
        top = sub[target].mode()[0]
        rule[val] = top
        err += (sub[target] != top).sum()
    return rule, err


best_attr, best_rule, best_err = None, None, len(df) + 1
for a in attrs:
    rule, err = rule_for(a)
    print(f"{a:12s} error {err}/{len(df)}")
    if err < best_err:
        best_attr, best_rule, best_err = a, rule, err

print(f"\n1R picks: {best_attr}  (error {best_err}/{len(df)})")
for val, cls in best_rule.items():
    print(f"  if {best_attr} = {val:9s} -> {cls}")
