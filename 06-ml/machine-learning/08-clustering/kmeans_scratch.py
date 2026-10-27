# k-means from scratch on make_blobs, checked against sklearn KMeans
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans

np.random.seed(1)


def kmeanspp_init(X, k, rng):
    # pick the first centre at random, then each next one far from the ones so far
    C = [X[rng.integers(len(X))]]
    for _ in range(1, k):
        d2 = np.min([np.sum((X - c) ** 2, axis=1) for c in C], axis=0)
        C.append(X[rng.choice(len(X), p=d2 / d2.sum())])
    return np.array(C)


def kmeans(X, k, max_iter=300):
    rng = np.random.default_rng(1)
    C = kmeanspp_init(X, k, rng)
    labels = np.zeros(len(X), dtype=int)
    for it in range(1, max_iter + 1):
        d = ((X[:, None, :] - C[None, :, :]) ** 2).sum(axis=2)
        new = d.argmin(axis=1)
        if it > 1 and np.array_equal(new, labels):
            break                       # assignments stopped changing -> converged
        labels = new
        for j in range(k):
            if np.any(labels == j):
                C[j] = X[labels == j].mean(axis=0)
    inertia = ((X - C[labels]) ** 2).sum()
    return labels, C, inertia, it


X, _ = make_blobs(n_samples=500, centers=[[-5, -5], [5, -5], [-5, 5], [5, 5]],
                  cluster_std=1.1, random_state=1)

labels, C, inertia, iters = kmeans(X, 4)
print(f"scratch   inertia={inertia:8.2f}   iters={iters}")

km = KMeans(n_clusters=4, n_init=10, random_state=1).fit(X)
print(f"sklearn   inertia={km.inertia_:8.2f}   iters={km.n_iter_}")
print(f"gap       {abs(inertia - km.inertia_) / km.inertia_ * 100:.3f}%")

fig, ax = plt.subplots(1, 2, figsize=(11, 4.5))
for a, (lab, cen, ttl) in zip(
    ax,
    [(labels, C, f"from scratch  (inertia {inertia:.0f})"),
     (km.labels_, km.cluster_centers_, f"sklearn  (inertia {km.inertia_:.0f})")],
):
    a.scatter(X[:, 0], X[:, 1], c=lab, cmap="tab10", s=12, alpha=0.7)
    a.scatter(cen[:, 0], cen[:, 1], c="black", marker="X", s=180, edgecolor="white")
    a.set_title(ttl)
    a.set_xlabel("x1"); a.set_ylabel("x2")
fig.suptitle("k-means, k=4 blobs — cluster numbering differs but the partition is the same")
plt.savefig("clusters.png", dpi=110, bbox_inches="tight")
