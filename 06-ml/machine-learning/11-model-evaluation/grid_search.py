# tune an RBF SVM with GridSearchCV over (C, gamma), then draw a learning curve
# to read off whether the tuned model is bias- or variance-limited.

import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import GridSearchCV, learning_curve, StratifiedKFold
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC

np.random.seed(1)

data = load_breast_cancer()
X, y = data.data, data.target

pipe = Pipeline([("scaler", StandardScaler()), ("svc", SVC(kernel="rbf", random_state=1))])
grid = {
    "svc__C": [0.1, 1, 10, 100],
    "svc__gamma": [0.001, 0.01, 0.1, "scale"],
}
cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=1)

search = GridSearchCV(pipe, grid, cv=cv, scoring="accuracy", n_jobs=-1)
search.fit(X, y)
print(f"best params: {search.best_params_}")
print(f"best CV accuracy: {search.best_score_:.4f}")
print(f"grid size: {len(search.cv_results_['params'])} combos x 5 folds")

train_sizes, train_scores, val_scores = learning_curve(
    search.best_estimator_, X, y, cv=cv, scoring="accuracy",
    train_sizes=np.linspace(0.1, 1.0, 8), n_jobs=-1)

train_mean, train_std = train_scores.mean(1), train_scores.std(1)
val_mean, val_std = val_scores.mean(1), val_scores.std(1)

# the gap between the two curves is the variance; where the validation curve plateaus is the bias
print(f"\nfinal train acc {train_mean[-1]:.3f}, validation acc {val_mean[-1]:.3f}, "
      f"gap {train_mean[-1] - val_mean[-1]:.3f}")

plt.figure(figsize=(7, 5))
plt.plot(train_sizes, train_mean, "o-", color="#2c3e50", label="training score")
plt.fill_between(train_sizes, train_mean - train_std, train_mean + train_std, alpha=0.15, color="#2c3e50")
plt.plot(train_sizes, val_mean, "o-", color="#c0392b", label="cross-validation score")
plt.fill_between(train_sizes, val_mean - val_std, val_mean + val_std, alpha=0.15, color="#c0392b")
plt.xlabel("training set size")
plt.ylabel("accuracy")
plt.title(f"Learning curve — tuned RBF SVM (C={search.best_params_['svc__C']}, "
          f"gamma={search.best_params_['svc__gamma']})")
plt.legend(loc="lower right")
plt.grid(alpha=0.3)
plt.savefig("learning_curve.png", dpi=110, bbox_inches="tight")
plt.close()
