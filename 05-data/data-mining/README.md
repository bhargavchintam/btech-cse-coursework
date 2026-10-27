<p align="center"><img src="assets/banner.svg" alt="Data Mining Techniques and Lab" width="100%"></p>

# Data Mining Techniques and Lab

Python code from Data Mining Techniques at **REVA University, Bengaluru** (B.Tech, sixth semester, 2020). The whole point of this course is understanding the algorithms, so almost everything here is **written from scratch** — Apriori, k-means, decision trees, KNN, Naive Bayes, PCA, PageRank — with numpy for the maths and pandas for loading the data. A handful of programs use scikit-learn as well, to line the hand-written version up against the library.

76 programs across the pipeline: preprocessing → exploration → the mining techniques (association, classification, clustering, regression) → dimensionality reduction → advanced topics, plus the labs.

## Structure

| Folder | Technique | Programs |
|---|---|---|
| `01-introduction/` | KDD process, data types, a tiny end-to-end pipeline | 3 |
| `02-data-preprocessing/` | Missing values, normalization, binning, discretization, encoding | 8 |
| `03-data-exploration/` | Central tendency, dispersion, five-number summary, correlation | 6 |
| `04-similarity-and-distance/` | Euclidean, Manhattan, Minkowski, cosine, Jaccard, Hamming | 7 |
| `05-association-rules/` | Apriori, FP-growth, support/confidence/lift | 5 |
| `06-classification/` | Decision tree (ID3/CART), Naive Bayes, KNN, evaluation | 10 |
| `07-clustering/` | k-means, k-medoids, hierarchical, DBSCAN, silhouette, elbow | 8 |
| `08-regression/` | Linear (least-squares + gradient descent), logistic, metrics | 5 |
| `09-dimensionality-reduction/` | PCA, information gain, chi-square | 4 |
| `10-advanced-topics/` | Outliers, PageRank, TF-IDF, bagging | 6 |
| `datasets/` | The shared CSVs the programs read | — |
| `lab/` | The 14 numbered lab programs | 14 |

Each topic folder has a `NOTES.md` with the algorithm steps and the formulas.

## Datasets

The programs read from `datasets/`, so nothing depends on downloading anything:

- `play_tennis.csv` — the classic 14-row Quinlan set (decision trees, Naive Bayes, info gain)
- `transactions.csv` — a 5-transaction market basket (Apriori, association rules)
- `points2d.csv` — 10 points in two obvious clusters (all the clustering programs)
- `iris_subset.csv` — setosa + versicolor (KNN, PCA, logistic regression)
- `students.csv` — has missing values on purpose (preprocessing, regression)

Programs load them by a path relative to the script, so they run from any directory.

## Running

Standard scientific-Python stack:

```sh
python3 06-classification/01_decision_tree_id3.py     # prints the tree; root splits on Outlook
python3 07-clustering/01_kmeans.py                    # separates the two clusters in points2d
python3 05-association-rules/01_apriori.py            # frequent itemsets on the market basket
```

Needs `numpy pandas scikit-learn scipy` (and `matplotlib` for the two plotting scripts). The from-scratch programs check themselves against the library where it makes sense — the k-means centroids match sklearn's, the PCA explained-variance matches sklearn's, the regression metrics match `sklearn.metrics`.

## Worth a look

- `06-classification/01_decision_tree_id3.py` — ID3 by entropy and information gain; the root comes out **Outlook** (gain 0.247) on the play-tennis data, the textbook answer.
- `05-association-rules/` — Apriori, FP-growth, and a brute-force check all agree on the frequent itemsets, which is the whole reassurance that Apriori's pruning didn't drop anything.
- `10-advanced-topics/03_pagerank.py` — power iteration with damping 0.85; the ranks converge and sum to 1.

## A note on the code

Sixth-semester Python — short names (`df`, `X`, `y`, `k`, `sup`, `conf`, `gain`), the algorithm written out in plain loops rather than a clever one-liner, sklearn only where the point is to compare. It's the code as submitted, and it's meant to be read, not just run.
