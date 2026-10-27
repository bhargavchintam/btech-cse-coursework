#!/usr/bin/env python3
y_true = ["Yes", "No", "Yes", "Yes", "No", "No", "Yes", "No", "Yes", "No"]
y_pred = ["Yes", "No", "Yes", "No", "No", "Yes", "Yes", "No", "Yes", "No"]
pos = "Yes"

tp = sum(1 for t, p in zip(y_true, y_pred) if t == pos and p == pos)
tn = sum(1 for t, p in zip(y_true, y_pred) if t != pos and p != pos)
fp = sum(1 for t, p in zip(y_true, y_pred) if t != pos and p == pos)
fn = sum(1 for t, p in zip(y_true, y_pred) if t == pos and p != pos)

acc = (tp + tn) / len(y_true)
prec = tp / (tp + fp)
rec = tp / (tp + fn)
f1 = 2 * prec * rec / (prec + rec)

print(f"tp={tp} tn={tn} fp={fp} fn={fn}")
print(f"accuracy  {acc:.3f}")
print(f"precision {prec:.3f}")
print(f"recall    {rec:.3f}")
print(f"f1        {f1:.3f}")
