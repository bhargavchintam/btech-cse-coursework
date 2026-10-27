# PCA from scratch (center, covariance, eigh, sort, project) on iris,
# checked against sklearn's PCA
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.decomposition import PCA

np.random.seed(1)


def pca_fit(X, k):
    Xc = X - X.mean(axis=0)
    C = np.cov(Xc, rowvar=False)          # feature-by-feature covariance, n-1 denominator
    vals, vecs = np.linalg.eigh(C)        # eigh: ascending eigenvalues, orthonormal columns
    order = np.argsort(vals)[::-1]        # want the biggest-variance directions first
    vals, vecs = vals[order], vecs[:, order]
    ratio = vals / vals.sum()
    Z = Xc @ vecs[:, :k]
    return Z, ratio, vecs


data = load_iris()
X, y = data.data, data.target

Z, ratio, vecs = pca_fit(X, 2)

pca = PCA(random_state=1).fit(X)
Zsk = pca.transform(X)[:, :2]

# an eigenvector is only defined up to sign, so align columns before comparing
for j in range(2):
    if Z[:, j] @ Zsk[:, j] < 0:
        Z[:, j] *= -1

print("explained variance ratio")
print("  PC   scratch  sklearn")
for i, (a, b) in enumerate(zip(ratio, pca.explained_variance_ratio_), 1):
    print(f"  PC{i}   {a:.4f}   {b:.4f}")
print(f"sum of ratios: {ratio.sum():.4f}")
print(f"first two hold {ratio[:2].sum() * 100:.1f}% of the variance")
print(f"projection matches sklearn: {np.allclose(Z, Zsk, atol=1e-8)}")

assert np.allclose(ratio, pca.explained_variance_ratio_, atol=1e-10)
assert np.allclose(Z, Zsk, atol=1e-8)

fig, ax = plt.subplots(figsize=(7, 5.5))
for c, name in enumerate(data.target_names):
    m = y == c
    ax.scatter(Z[m, 0], Z[m, 1], s=30, alpha=0.85, label=name)
ax.set_xlabel(f"PC1  ({ratio[0] * 100:.1f}% var)")
ax.set_ylabel(f"PC2  ({ratio[1] * 100:.1f}% var)")
ax.set_title("iris projected onto its first two principal components")
ax.legend(title="species")
ax.grid(alpha=0.3)
plt.savefig("pca_scatter.png", dpi=110, bbox_inches="tight")
