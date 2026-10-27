# PCA on iris: drop 4 features to 2 and see the species separate
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA

np.random.seed(1)

data = load_iris()
X = StandardScaler().fit_transform(data.data)   # standardise first so no feature dominates
y = data.target

pca = PCA(random_state=1).fit(X)
ratio = pca.explained_variance_ratio_
print("explained variance ratio per component:")
for i, r in enumerate(ratio, 1):
    print(f"  PC{i}: {r:.4f}")
print(f"first two components: {ratio[:2].sum() * 100:.1f}% of total variance")
print(f"sum of all ratios: {ratio.sum():.4f}")

Z = pca.transform(X)[:, :2]

fig, ax = plt.subplots(figsize=(7, 5.5))
for c, name in enumerate(data.target_names):
    m = y == c
    ax.scatter(Z[m, 0], Z[m, 1], s=32, alpha=0.85, label=name)
ax.set_xlabel(f"PC1  ({ratio[0] * 100:.1f}% var)")
ax.set_ylabel(f"PC2  ({ratio[1] * 100:.1f}% var)")
ax.set_title("iris in 2D after PCA")
ax.legend(title="species")
ax.grid(alpha=0.3)
plt.savefig("pca.png", dpi=110, bbox_inches="tight")
