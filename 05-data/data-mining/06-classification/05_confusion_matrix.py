#!/usr/bin/env python3
y_true = ["Yes", "No", "Yes", "Yes", "No", "No", "Yes", "No", "Yes", "No"]
y_pred = ["Yes", "No", "Yes", "No", "No", "Yes", "Yes", "No", "Yes", "No"]

labels = sorted(set(y_true) | set(y_pred))
idx = {l: i for i, l in enumerate(labels)}
m = [[0] * len(labels) for _ in labels]
for t, p in zip(y_true, y_pred):
    m[idx[t]][idx[p]] += 1

print("rows = actual, cols = predicted")
print("      " + "  ".join(f"{l:>4s}" for l in labels))
for l in labels:
    row = m[idx[l]]
    print(f"{l:>4s}  " + "  ".join(f"{v:>4d}" for v in row))
