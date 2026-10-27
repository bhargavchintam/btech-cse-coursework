# why a single train/test split is a shaky estimate, and how k-fold CV fixes it.
# breast_cancer, two models, stratified 5-fold.

import numpy as np
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import cross_val_score, StratifiedKFold, train_test_split
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC

np.random.seed(1)

data = load_breast_cancer()
X, y = data.data, data.target

# scaling goes INSIDE the pipeline so each fold scales on its own training part — no leakage
models = {
    "logistic": make_pipeline(StandardScaler(), LogisticRegression(max_iter=5000, random_state=1)),
    "svm-rbf":  make_pipeline(StandardScaler(), SVC(kernel="rbf", C=1, gamma="scale", random_state=1)),
}

cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=1)

print("5-fold cross-validation (accuracy):")
for name, model in models.items():
    scores = cross_val_score(model, X, y, cv=cv, scoring="accuracy")
    print(f"  {name:9s} folds {np.round(scores, 3)}  ->  {scores.mean():.4f} +/- {scores.std():.4f}")

# the point: one split can flatter or punish a model by luck of the draw.
# sweep the split's random_state and watch the single-split score bounce around,
# while the 5-fold mean barely moves.
print("\nsame logistic model, accuracy from a single 75/25 split under different seeds:")
pipe = make_pipeline(StandardScaler(), LogisticRegression(max_iter=5000, random_state=1))
single = []
for seed in range(10):
    Xtr, Xte, ytr, yte = train_test_split(X, y, test_size=0.25, random_state=seed, stratify=y)
    pipe.fit(Xtr, ytr)
    single.append(pipe.score(Xte, yte))
single = np.array(single)
print(f"  scores {np.round(single, 3)}")
print(f"  single-split range: {single.min():.3f} to {single.max():.3f}  (spread {np.ptp(single):.3f})")

cv_means = []
for seed in range(10):
    cv_s = StratifiedKFold(n_splits=5, shuffle=True, random_state=seed)
    cv_means.append(cross_val_score(pipe, X, y, cv=cv_s, scoring="accuracy").mean())
cv_means = np.array(cv_means)
print(f"\n  5-fold mean under the same 10 seeds: {np.round(cv_means, 3)}")
print(f"  cv-mean range: {cv_means.min():.3f} to {cv_means.max():.3f}  (spread {np.ptp(cv_means):.3f})")
print("\n  the single split swings ~5x wider than the CV mean — same data, steadier estimate.")
