#!/usr/bin/env python3
import os
import pandas as pd
from sklearn.decomposition import PCA

here = os.path.dirname(os.path.abspath(__file__))
df = pd.read_csv(os.path.join(here, "..", "datasets", "iris_subset.csv"))
feats = ["sepal_length", "sepal_width", "petal_length", "petal_width"]
X = df[feats].values

pca = PCA(n_components=2)
Z = pca.fit_transform(X)

print("explained variance ratio:", pca.explained_variance_ratio_.round(4))
print("cumulative:", pca.explained_variance_ratio_.cumsum().round(4))
print("components (each row is a PC):")
print(pca.components_.round(3))
print("first 5 rows in PC space:")
print(Z[:5].round(3))
