# the two front-runners in models.py were logistic regression and the RBF SVM, within a
# point of each other. an untuned SVM leaves performance on the table because gamma sits at
# a default — so that's the one worth tuning. grid-search (C, gamma) with 5-fold CV on the
# training set only, then check whether the tuned SVM overtakes the logistic model.

import numpy as np
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.model_selection import GridSearchCV, cross_val_score, StratifiedKFold
from dataset import get_split

np.random.seed(1)

X_train, X_test, y_train, y_test = get_split()
cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=1)

pipe = Pipeline([
    ("scaler", StandardScaler()),
    ("svc", SVC(kernel="rbf", random_state=1)),
])
grid = {
    "svc__C": [0.1, 1, 10, 100],
    "svc__gamma": ["scale", 0.0001, 0.001, 0.01, 0.1],
}

base = cross_val_score(pipe, X_train, y_train, cv=cv, scoring="accuracy").mean()
print(f"default SVM (C=1, gamma=scale) CV accuracy: {base:.4f}")

search = GridSearchCV(pipe, grid, cv=cv, scoring="accuracy", n_jobs=-1)
search.fit(X_train, y_train)
print(f"best params: {search.best_params_}")
print(f"best CV accuracy: {search.best_score_:.4f}")
print(f"improvement over default SVM: {search.best_score_ - base:+.4f}")
print(f"searched {len(search.cv_results_['params'])} combos x 5 folds")

# a small gamma makes each support vector's influence wide and smooth; the default lets it
# run larger and start bending the boundary around noise. the large C just says fit closely.
print(f"\nheld-out test accuracy with tuned SVM: {search.score(X_test, y_test):.4f}")
