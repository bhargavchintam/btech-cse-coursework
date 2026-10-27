# hierarchical (Ward) with a dendrogram, and DBSCAN vs k-means on the two moons
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from scipy.cluster.hierarchy import linkage, dendrogram, fcluster
from sklearn.datasets import make_blobs, make_moons
from sklearn.cluster import AgglomerativeClustering, KMeans, DBSCAN

np.random.seed(1)

Xh, _ = make_blobs(n_samples=40, centers=3, cluster_std=0.7, random_state=1)
Z = linkage(Xh, method="ward")          # Ward merges the pair that adds least within-cluster SSE
agg = AgglomerativeClustering(n_clusters=3, linkage="ward").fit(Xh)
cut = fcluster(Z, t=3, criterion="maxclust")
print(f"agglomerative: {len(set(agg.labels_))} clusters, sizes {np.bincount(agg.labels_)}")

plt.figure(figsize=(9, 4.5))
dendrogram(Z, color_threshold=0.7 * Z[:, 2].max())
plt.title("Ward dendrogram — cut the tall link to get 3 clusters")
plt.xlabel("sample"); plt.ylabel("merge distance")
plt.savefig("dendrogram.png", dpi=110, bbox_inches="tight")
plt.close()

Xm, _ = make_moons(n_samples=400, noise=0.1, random_state=1)
km = KMeans(n_clusters=2, n_init=10, random_state=1).fit(Xm)
db = DBSCAN(eps=0.16, min_samples=5).fit(Xm)

n_db = len(set(db.labels_)) - (1 if -1 in db.labels_ else 0)
n_noise = int((db.labels_ == -1).sum())
print(f"k-means on moons: 2 clusters (splits each moon in half)")
print(f"DBSCAN  on moons: {n_db} clusters + {n_noise} noise points")

fig, ax = plt.subplots(1, 2, figsize=(11, 4.5))
ax[0].scatter(Xm[:, 0], Xm[:, 1], c=km.labels_, cmap="coolwarm", s=12)
ax[0].set_title("k-means — cuts straight across, gets the moons wrong")
mask = db.labels_ == -1
ax[1].scatter(Xm[~mask, 0], Xm[~mask, 1], c=db.labels_[~mask], cmap="coolwarm", s=12)
ax[1].scatter(Xm[mask, 0], Xm[mask, 1], c="lightgrey", s=12, label="noise")
ax[1].set_title("DBSCAN — follows the density, recovers both moons")
ax[1].legend(loc="upper right", fontsize=8)
for a in ax:
    a.set_xlabel("x1"); a.set_ylabel("x2")
plt.savefig("dbscan_vs_kmeans.png", dpi=110, bbox_inches="tight")
