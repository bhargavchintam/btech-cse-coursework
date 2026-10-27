#!/usr/bin/env python3
import os
import pandas as pd
from scipy.stats import chi2_contingency

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "play_tennis.csv"))

obs = pd.crosstab(df["Outlook"], df["PlayTennis"])
print("contingency table (Outlook vs PlayTennis):")
print(obs)

o = obs.values.astype(float)
row = o.sum(axis=1, keepdims=True)
col = o.sum(axis=0, keepdims=True)
exp = row @ col / o.sum()
chi2 = ((o - exp) ** 2 / exp).sum()
dof = (o.shape[0] - 1) * (o.shape[1] - 1)
print(f"\nfrom scratch: chi2 = {chi2:.4f}, dof = {dof}")

stat, p, d, _ = chi2_contingency(obs, correction=False)
print(f"scipy:        chi2 = {stat:.4f}, dof = {d}, p = {p:.4f}")
