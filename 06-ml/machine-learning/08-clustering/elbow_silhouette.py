# choosing k: the elbow (inertia) and the silhouette score, k = 1..10
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score

np.random.seed(1)

X, _ = make_blobs(n_samples=500, centers=[[-5, -5], [5, -5], [-5, 5], [5, 5]],
                  cluster_std=1.1, random_state=1)

Ks = range(1, 11)
inertias, sils = [], []
for k in Ks:
    km = KMeans(n_clusters=k, n_init=10, random_state=1).fit(X)
    inertias.append(km.inertia_)
    sils.append(silhouette_score(X, km.labels_) if k >= 2 else np.nan)

best_k = int(np.nanargmax(sils)) + 1     # silhouette peaks at the true number of blobs
print("k   inertia    silhouette")
for k, i, s in zip(Ks, inertias, sils):
    print(f"{k:<3d} {i:9.1f}  {s:.3f}" if k >= 2 else f"{k:<3d} {i:9.1f}     -")
print(f"suggested k = {best_k}")

fig, ax = plt.subplots(1, 2, figsize=(11, 4.5))
ax[0].plot(list(Ks), inertias, "o-", color="steelblue")
ax[0].axvline(best_k, ls="--", color="grey")
ax[0].set_title("elbow: inertia vs k"); ax[0].set_xlabel("k"); ax[0].set_ylabel("inertia")
ax[0].grid(alpha=0.3)

ax[1].plot(list(Ks)[1:], sils[1:], "o-", color="darkorange")
ax[1].axvline(best_k, ls="--", color="grey")
ax[1].set_title("silhouette vs k"); ax[1].set_xlabel("k"); ax[1].set_ylabel("mean silhouette")
ax[1].grid(alpha=0.3)

plt.savefig("elbow.png", dpi=110, bbox_inches="tight")
