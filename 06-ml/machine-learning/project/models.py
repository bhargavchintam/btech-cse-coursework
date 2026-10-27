# train and compare five classifiers on the breast-cancer split. every model sits behind
# a StandardScaler pipeline so the CV folds don't leak scaling (and so knn/svm aren't
# dominated by the big-range columns). trees are scale-invariant, so the scaler is a no-op
# for them, but keeping one pipeline shape for all five keeps the comparison honest.

import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import cross_val_score, StratifiedKFold
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.svm import SVC
from sklearn.metrics import (accuracy_score, precision_score,
                             recall_score, f1_score)
from dataset import get_split

np.random.seed(1)

X_train, X_test, y_train, y_test = get_split()

models = {
    "LogisticRegression": LogisticRegression(max_iter=5000, random_state=1),
    "KNN": KNeighborsClassifier(n_neighbors=5),
    "DecisionTree": DecisionTreeClassifier(random_state=1),
    "RandomForest": RandomForestClassifier(n_estimators=200, random_state=1),
    "SVM": SVC(kernel="rbf", random_state=1),
}

cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=1)
rows = []
for name, model in models.items():
    pipe = make_pipeline(StandardScaler(), model)
    cv_mean = cross_val_score(pipe, X_train, y_train, cv=cv, scoring="accuracy").mean()
    pipe.fit(X_train, y_train)
    y_pred = pipe.predict(X_test)
    rows.append({
        "model": name,
        "accuracy": accuracy_score(y_test, y_pred),
        "precision": precision_score(y_test, y_pred),
        "recall": recall_score(y_test, y_pred),
        "f1": f1_score(y_test, y_pred),
        "cv_mean": cv_mean,
    })

rows.sort(key=lambda r: r["cv_mean"], reverse=True)

header = f"{'model':20s}{'acc':>8s}{'prec':>8s}{'recall':>8s}{'f1':>8s}{'cv_mean':>9s}"
print(header)
print("-" * len(header))
for r in rows:
    print(f"{r['model']:20s}{r['accuracy']:8.4f}{r['precision']:8.4f}"
          f"{r['recall']:8.4f}{r['f1']:8.4f}{r['cv_mean']:9.4f}")

best = rows[0]
print(f"\nbest by 5-fold CV: {best['model']}  (cv_mean={best['cv_mean']:.4f})")

names = [r["model"] for r in rows]
x = np.arange(len(names))
width = 0.4
plt.figure(figsize=(10, 5.5))
plt.bar(x - width / 2, [r["accuracy"] for r in rows], width, label="test accuracy", color="#2c7fb8")
plt.bar(x + width / 2, [r["f1"] for r in rows], width, label="test F1", color="#c0392b")
plt.xticks(x, names, rotation=15)
plt.ylim(0.85, 1.0)
plt.ylabel("score")
plt.title("Model comparison — breast cancer (test set)")
plt.legend()
plt.grid(axis="y", alpha=0.3)
plt.savefig("model_comparison.png", dpi=110, bbox_inches="tight")
plt.close()
