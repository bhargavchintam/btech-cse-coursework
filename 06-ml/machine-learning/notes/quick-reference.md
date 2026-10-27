# Quick reference — night-before revision sheet

One page. Formulas and tables, no prose. For the whole picture read the unit notes.

## Algorithm cheat-sheet

| Algorithm | Type | Key idea | Scaling? | Key hyperparameters | When to use |
|---|---|---|---|---|---|
| Linear regression | Supervised (reg) | fit a line, minimise MSE | for GD yes, normal-eqn no | none (Ridge/Lasso: α) | continuous target, linear-ish trend |
| Logistic regression | Supervised (clf) | sigmoid of a linear score, min cross-entropy | for GD yes | C (inverse reg), penalty | linear decision boundary, want probabilities |
| KNN | Supervised (both) | vote among k nearest neighbours | **yes, critical** | k, distance metric | small data, non-linear boundary, lazy |
| Naive Bayes | Supervised (clf) | Bayes + feature independence | no | var_smoothing (Gaussian) | text/spam, high-dim, fast baseline |
| Decision tree | Supervised (both) | recursive splits on best feature | **no** | max_depth, min_samples_leaf | interpretable rules, mixed feature types |
| Random forest | Supervised (both) | bag many de-correlated trees | no | n_estimators, max_depth, max_features | strong tabular default, low tuning |
| SVM | Supervised (clf) | max-margin separator, kernel trick | **yes** | C, kernel, gamma | small/medium data, clear margin, non-linear via rbf |
| k-Means | Unsupervised | assign to nearest centroid, update means | **yes** | k (n_clusters), init, n_init | round, similar-size clusters |
| PCA | Unsupervised (dim-red) | project onto top-variance directions | **yes** | n_components | compress features, de-correlate, plot in 2-D |
| Neural net (MLP) | Supervised (both) | layers of weighted sums + activations, backprop | **yes** | layers, units, lr, activation, epochs | large data, complex non-linear patterns |

Scaling rule of thumb: distance- and gradient-based methods (KNN, SVM, k-means, PCA, NN, GD-linear/logistic) need it. Tree-based methods (tree, RF, gradient boosting) do not — splits are threshold-based, invariant to monotone rescaling.

## Classification metrics

Confusion matrix: TP, FP, FN, TN.

```
accuracy    = (TP + TN) / (TP + TN + FP + FN)
precision   = TP / (TP + FP)          of flagged, how many right
recall/TPR  = TP / (TP + FN)          of actual positives, how many caught
specificity = TN / (TN + FP)          true negative rate
F1          = 2 · precision · recall / (precision + recall)      harmonic mean
FPR         = FP / (FP + TN) = 1 − specificity
```

Precision when false alarms hurt (spam); recall when misses hurt (cancer, fraud). F1 for one number on imbalanced data. On imbalanced data never report accuracy alone.

## Regression metrics

```
MSE  = (1/m) Σ (yᵢ − ŷᵢ)²
RMSE = √MSE                          same units as y
MAE  = (1/m) Σ |yᵢ − ŷᵢ|             robust to outliers
R²   = 1 − SS_res / SS_tot           = 1 − Σ(yᵢ−ŷᵢ)² / Σ(yᵢ−ȳ)²
```

R² = 1 perfect, 0 no better than predicting the mean, can go negative. RMSE punishes big errors more than MAE.

## Activation functions

| Name | Formula | Range | Notes |
|---|---|---|---|
| Sigmoid | σ(z) = 1 / (1 + e⁻ᶻ) | (0, 1) | output layer for binary prob; saturates, vanishing gradient |
| Tanh | tanh(z) = (eᶻ − e⁻ᶻ)/(eᶻ + e⁻ᶻ) | (−1, 1) | zero-centred, still saturates |
| ReLU | max(0, z) | [0, ∞) | default hidden activation; cheap; dying-ReLU risk |
| Softmax | eᶻⁱ / Σⱼ eᶻʲ | (0, 1), sums to 1 | multiclass output layer, gives a distribution |

σ′(z) = σ(z)(1 − σ(z)).   tanh′(z) = 1 − tanh²(z).   ReLU′ = 1 if z>0 else 0.

## Distance metrics

```
Euclidean (L2):  d(a,b) = √ Σ (aᵢ − bᵢ)²
Manhattan (L1):  d(a,b) =  Σ |aᵢ − bᵢ|
```

Both need features on the same scale, else the large-range column dominates.

## Impurity and split criteria (trees)

For a node with class proportions pᵢ:

```
Entropy   H = − Σ pᵢ log₂ pᵢ            (0 pure, 1 for a 50/50 binary split)
Gini      G = 1 − Σ pᵢ²                 (0 pure, 0.5 for 50/50 binary)
Info gain IG = H(parent) − Σ (nₖ/n) H(childₖ)
```

ID3 splits on the feature with the highest information gain. CART uses Gini. Gini and entropy usually pick the same split; Gini is cheaper (no log).

## PCA — steps

1. Standardise X (mean 0, unit variance per column).
2. Covariance matrix C = (1/m) XᵀX.
3. Eigen-decompose C → eigenvalues λ, eigenvectors (the principal components).
4. Sort by λ descending; keep top k vectors as columns of W.
5. Project: Z = X W. Explained variance ratio of a PC = λᵢ / Σλ.

## k-Means — steps

1. Choose k; initialise k centroids (k-means++).
2. Assign each point to the nearest centroid (Euclidean).
3. Recompute each centroid as the mean of its assigned points.
4. Repeat 2–3 until assignments stop changing (converged).
5. Pick k with the elbow of inertia (WCSS) or the silhouette score.

## Bias–variance

| | Underfit (high bias) | Overfit (high variance) |
|---|---|---|
| Train error | high | low |
| Test error | high | high |
| Gap train→test | small | large |
| Cause | model too simple | model too flexible, fit noise |
| Fix | more capacity, more features | more data, regularise, simplify, early stop |

Total test error = bias² + variance + irreducible σ². Sit at the bottom of the U.

## sklearn API pattern

```python
from sklearn.model_selection import train_test_split, cross_val_score, GridSearchCV
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=1, stratify=y)

scaler = StandardScaler().fit(X_train)      # fit on TRAIN only
X_train = scaler.transform(X_train)
X_test  = scaler.transform(X_test)          # reuse the train stats

clf = LogisticRegression(C=1.0, max_iter=1000)
clf.fit(X_train, y_train)
y_pred = clf.score(X_test, y_test)          # accuracy on held-out data

cross_val_score(clf, X_train, y_train, cv=5).mean()   # honest estimate, no leak

grid = GridSearchCV(clf, {"C": [0.01, 0.1, 1, 10]}, cv=5)
grid.fit(X_train, y_train)
grid.best_params_, grid.best_score_
```

Scale AFTER the split, fit on train only — fitting the scaler on all the data leaks test statistics.
