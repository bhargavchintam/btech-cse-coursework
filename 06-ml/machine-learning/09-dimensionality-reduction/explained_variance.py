# PCA on breast_cancer (30 features): cumulative explained variance, how many
# components reach 95%
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA

np.random.seed(1)

X, y = load_breast_cancer(return_X_y=True)
Xs = StandardScaler().fit_transform(X)    # the 30 features span very different ranges, scale first

pca = PCA(random_state=1).fit(Xs)
cum = np.cumsum(pca.explained_variance_ratio_)
k90 = int(np.searchsorted(cum, 0.90) + 1)
k95 = int(np.searchsorted(cum, 0.95) + 1)

print(f"original features: {X.shape[1]}")
print(f"PC1 alone: {pca.explained_variance_ratio_[0] * 100:.1f}%")
print(f"components for 90% variance: {k90}")
print(f"components for 95% variance: {k95}")
print(f"first 10 components carry {cum[9] * 100:.1f}%")

fig, ax = plt.subplots(figsize=(8, 5))
ax.plot(range(1, len(cum) + 1), cum, "o-", color="steelblue", ms=4)
ax.axhline(0.95, ls="--", color="grey")
ax.axvline(k95, ls="--", color="crimson")
ax.annotate(f"95% at {k95} comps", xy=(k95, 0.95), xytext=(k95 + 4, 0.72),
            arrowprops=dict(arrowstyle="->", color="crimson"))
ax.set_xlabel("number of components")
ax.set_ylabel("cumulative explained variance")
ax.set_title("breast_cancer — cumulative explained variance vs #components")
ax.set_ylim(0, 1.02)
ax.grid(alpha=0.3)
plt.savefig("explained_variance.png", dpi=110, bbox_inches="tight")
