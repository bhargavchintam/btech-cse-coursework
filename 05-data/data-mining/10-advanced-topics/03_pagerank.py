#!/usr/bin/env python3
import numpy as np

pages = ["A", "B", "C", "D"]
links = {
    "A": ["B", "C"],
    "B": ["C"],
    "C": ["A"],
    "D": ["C"],
}
n = len(pages)
idx = {p: i for i, p in enumerate(pages)}

M = np.zeros((n, n))
for p, outs in links.items():
    for q in outs:
        M[idx[q], idx[p]] = 1 / len(outs)

d = 0.85
r = np.ones(n) / n
for it in range(100):
    new = (1 - d) / n + d * (M @ r)
    if np.abs(new - r).sum() < 1e-10:
        r = new
        break
    r = new

print("converged in", it, "iterations")
for p in pages:
    print(f"{p}  {r[idx[p]]:.4f}")
print("sum:", round(r.sum(), 6))
