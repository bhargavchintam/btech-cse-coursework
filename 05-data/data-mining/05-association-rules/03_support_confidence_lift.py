#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "transactions.csv"))
txns = [set(r.split()) for r in df["Items"]]
n = len(txns)


def support(*items):
    s = set(items)
    return sum(1 for t in txns if s <= t) / n


def rule(a, b):
    sup = support(*a, *b)
    conf = sup / support(*a)
    lift = conf / support(*b)
    return sup, conf, lift


print(f"transactions: {n}\n")
for it in ["bread", "milk", "diaper", "beer"]:
    print(f"support({it}) = {support(it):.2f}")
print()

pairs = [(["beer"], ["diaper"]),
         (["diaper"], ["beer"]),
         (["bread"], ["milk"]),
         (["bread", "milk"], ["diaper"])]

for a, b in pairs:
    sup, conf, lift = rule(a, b)
    tag = "independent" if abs(lift - 1) < 1e-9 else ("positive" if lift > 1 else "negative")
    print(f"{a} -> {b}")
    print(f"  support    = {sup:.2f}")
    print(f"  confidence = {conf:.2f}")
    print(f"  lift       = {lift:.2f}  ({tag} correlation)")
    print()

print("lift > 1 : A and B occur together more than if independent")
print("lift = 1 : A and B are independent, rule adds nothing")
print("lift < 1 : A and B occur together less than expected")
