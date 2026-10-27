# logistic regression on a 2D make_classification set, with the decision boundary drawn

import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

np.random.seed(1)

X, y = make_classification(
    n_samples=300, n_features=2, n_redundant=0, n_informative=2,
    n_clusters_per_class=1, class_sep=1.2, random_state=1)

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25, random_state=1, stratify=y)

clf = LogisticRegression(random_state=1)
clf.fit(X_train, y_train)
acc = accuracy_score(y_test, clf.predict(X_test))
print(f"test acc: {acc:.4f}")

pad = 0.5
x_min, x_max = X[:, 0].min() - pad, X[:, 0].max() + pad
y_min, y_max = X[:, 1].min() - pad, X[:, 1].max() + pad
xx, yy = np.meshgrid(np.linspace(x_min, x_max, 300),
                     np.linspace(y_min, y_max, 300))
grid = np.c_[xx.ravel(), yy.ravel()]
probs = clf.predict_proba(grid)[:, 1].reshape(xx.shape)

fig, ax = plt.subplots(figsize=(6.5, 5.5))
ax.contourf(xx, yy, probs, levels=20, cmap="RdBu", alpha=0.6)
# the 0.5 contour is where w·x + b = 0 — the actual boundary
ax.contour(xx, yy, probs, levels=[0.5], colors="k", linewidths=1.5)
ax.scatter(X_train[:, 0], X_train[:, 1], c=y_train, cmap="RdBu",
           edgecolors="k", s=30, label="train")
ax.scatter(X_test[:, 0], X_test[:, 1], c=y_test, cmap="RdBu",
           edgecolors="k", s=55, marker="^", label="test")
ax.set_title(f"logistic regression decision boundary (test acc {acc:.2f})")
ax.set_xlabel("feature 1")
ax.set_ylabel("feature 2")
ax.legend(loc="best")

plt.savefig("decision_boundary.png", dpi=110, bbox_inches="tight")
