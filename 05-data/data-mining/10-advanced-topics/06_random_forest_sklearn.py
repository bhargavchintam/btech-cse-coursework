#!/usr/bin/env python3
import os
import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "iris_subset.csv"))
feats = ["sepal_length", "sepal_width", "petal_length", "petal_width"]
X = df[feats]
y = df["species"]

Xtr, Xte, ytr, yte = train_test_split(X, y, test_size=0.3, random_state=1, stratify=y)
rf = RandomForestClassifier(n_estimators=100, random_state=1)
rf.fit(Xtr, ytr)
pred = rf.predict(Xte)

print("accuracy:", accuracy_score(yte, pred))
print("feature importances:")
for f, imp in zip(feats, rf.feature_importances_):
    print(f"  {f:14s} {imp:.3f}")
