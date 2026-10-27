# Clustering

Unsupervised — no labels, we just group points by similarity and hope the groups mean something. The
opposite of classification (06), where every row already came with a class. Here the only signal is
distance, usually euclidean (see 04-similarity for the distance stuff).

All the programs here run on datasets/points2d.csv — 10 points that fall into two obvious blobs, a low one
near (1.4, 1.5) and a high one near (8.6, 8.4). Small and separable on purpose so I can check the answer by
eye: any sane method must put the 5 low points in one cluster and the 5 high points in the other.

## Three families

- Partitional: fix k up front, split the data into k flat groups, move things around to minimise some cost.
  k-means, k-medoids.
- Hierarchical: build a tree of merges (agglomerative, bottom-up) or splits (divisive, top-down). No k
  needed until you cut the tree.
- Density-based: a cluster is a dense region, low-density gaps are the borders, sparse points are noise.
  DBSCAN. This one finds the number of clusters itself and can do non-round shapes.

## k-means (Lloyd's loop)

1. pick k initial centroids (random points here)
2. assign every point to its nearest centroid
3. move each centroid to the mean of its assigned points
4. repeat 2-3 until the centroids stop moving

    WCSS = sum over clusters of sum over points ||x - c_j||^2

that's the thing it minimises. It only finds a local optimum and the result depends on the init, so in
practice you run it a few times and keep the best (sklearn's n_init does exactly that). On points2d it lands
on centroids (1.40, 1.50) and (8.60, 8.40) every time.

> k-means centroid is a made-up mean point, not a real data point. k-medoids uses an actual point.

## k-medoids (PAM)

Same idea but the cluster centre is one of the actual data points (the medoid). PAM = Partitioning Around
Medoids:

- start with k points as medoids
- for every (medoid, non-medoid) swap, check if swapping lowers the total distance to nearest medoid
- keep the best swap, repeat until no swap helps

Slower than k-means (all those swaps) but more robust to outliers, because a mean gets dragged by a far
point and a medoid doesn't. On points2d it picks one low point and one high point as the two medoids.

## Agglomerative hierarchical

Start with every point its own cluster, then repeatedly merge the two closest clusters until one is left.
"Closest" depends on the linkage:

- single    : distance between the two nearest points (can chain into long straggly clusters)
- complete  : distance between the two farthest points (tight, compact clusters)
- average   : mean distance over all cross pairs (a compromise, what 03 uses)

The merge order and heights give a dendrogram; cut it at a height to get flat clusters. On points2d the
first eight merges are all tiny distances inside the two blobs, then the last merge jumps to ~10.0 — that
big gap is where you cut to get the 2 clusters.

## DBSCAN

Two parameters: eps (neighbourhood radius) and minpts (how many neighbours make a point dense).

- core point   : has >= minpts points within eps (counting itself)
- border point : within eps of a core point but not core itself
- noise        : neither

Grow a cluster from a core point by pulling in everything density-reachable. No k needed, and points that
sit in empty space just get labelled noise instead of being forced into a cluster. On points2d with
eps=2.0, minpts=3 every point is core and you get exactly 2 clusters, 0 noise. Bump eps too high and the two
blobs merge into one; too low and everything becomes noise — picking eps is the whole game.

## Evaluation

WCSS / SSE — the within-cluster squared error above. Always drops as k goes up (k=n gives 0), so you can't
just minimise it.

Elbow method — plot WCSS against k and look for the bend where extra clusters stop helping much. On points2d:

    k=1  254.725
    k=2    6.100   <- elbow, the big drop
    k=3    4.283
    k=4    3.083
    k=5    2.542
    k=6    2.458

that k=1 -> k=2 fall is enormous and after that it flattens, so k=2 is the answer.

Silhouette — for each point, a = mean distance to its own cluster, b = mean distance to the nearest other
cluster, then

    s = (b - a) / max(a, b)

ranges -1..1, near 1 is well clustered, near 0 is on a boundary, negative means probably misassigned.
Average over all points scores the clustering. points2d with the 2-way split gives ~0.88, which is high
(it should be, the blobs are far apart).

With true labels you can also score externally: purity (each cluster votes for its majority true class,
sum the hits, divide by n) and the Rand index (fraction of point pairs the two labellings agree on). Both
come out 1.0 on points2d because the split is perfect. (Mixed these two up with accuracy in the internal —
purity needs the true labels, silhouette and WCSS don't.)
