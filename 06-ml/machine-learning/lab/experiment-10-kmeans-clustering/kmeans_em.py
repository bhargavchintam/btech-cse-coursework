# compare k-means and EM (Gaussian mixture) clustering on the same blobs
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans
from sklearn.mixture import GaussianMixture
from sklearn.metrics import adjusted_rand_score, silhouette_score

np.random.seed(1)

# stretch the blobs so they are elliptical — this is where EM pulls ahead of k-means
X, y_true = make_blobs(n_samples=600, centers=4, cluster_std=1.3, random_state=1)
X = X @ np.array([[1.4, 0.6], [-0.3, 0.9]])

km = KMeans(n_clusters=4, n_init=10, random_state=1).fit(X)
gmm = GaussianMixture(n_components=4, covariance_type="full", random_state=1).fit(X)
y_km = km.labels_
y_em = gmm.predict(X)

# k-means only knows spherical, equal-size groups; EM fits a full covariance per cluster
print("                  ARI     silhouette")
print(f"k-means         {adjusted_rand_score(y_true, y_km):.3f}    {silhouette_score(X, y_km):.3f}")
print(f"EM (GaussMix)   {adjusted_rand_score(y_true, y_em):.3f}    {silhouette_score(X, y_em):.3f}")
print(f"\nk-means inertia: {km.inertia_:.1f}")
print(f"GMM converged:   {gmm.converged_}   log-likelihood: {gmm.score(X):.3f}")

fig, ax = plt.subplots(1, 3, figsize=(15, 4.6), sharex=True, sharey=True)
ax[0].scatter(X[:, 0], X[:, 1], c=y_true, cmap="tab10", s=12, alpha=0.7)
ax[0].set_title("true blobs")
ax[1].scatter(X[:, 0], X[:, 1], c=y_km, cmap="tab10", s=12, alpha=0.7)
ax[1].scatter(km.cluster_centers_[:, 0], km.cluster_centers_[:, 1],
              c="black", marker="X", s=160, edgecolor="white")
ax[1].set_title(f"k-means  (ARI {adjusted_rand_score(y_true, y_km):.2f})")
ax[2].scatter(X[:, 0], X[:, 1], c=y_em, cmap="tab10", s=12, alpha=0.7)
ax[2].scatter(gmm.means_[:, 0], gmm.means_[:, 1],
              c="black", marker="X", s=160, edgecolor="white")
ax[2].set_title(f"EM / GaussianMixture  (ARI {adjusted_rand_score(y_true, y_em):.2f})")
for a in ax:
    a.set_xlabel("x1")
ax[0].set_ylabel("x2")
plt.savefig("kmeans_vs_em.png", dpi=110, bbox_inches="tight")
