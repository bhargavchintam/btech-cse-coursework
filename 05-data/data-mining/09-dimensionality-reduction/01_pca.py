#!/usr/bin/env python3
import os
import numpy as np
import pandas as pd
from sklearn.decomposition import PCA

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "iris_subset.csv"))
feats = ["sepal_length", "sepal_width", "petal_length", "petal_width"]
X = df[feats].values.astype(float)

X = X - X.mean(axis=0)
cov = np.cov(X, rowvar=False)
vals, vecs = np.linalg.eig(cov)
vals, vecs = vals.real, vecs.real

order = vals.argsort()[::-1]
vals = vals[order]
vecs = vecs[:, order]
ratio = vals / vals.sum()

print("eigenvalues:", np.round(vals, 4))
print("explained variance ratio:", np.round(ratio, 4))

Z = X @ vecs[:, :2]
print("first 5 rows projected to 2 PCs:")
print(np.round(Z[:5], 3))

p = PCA(n_components=2).fit(X)
print("sklearn top ratio:", round(p.explained_variance_ratio_[0], 4))
print("mine   top ratio:", round(ratio[0], 4))
