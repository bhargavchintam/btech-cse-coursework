# single tree vs bagging, random forest, adaboost, gradient boosting on the wine data
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import load_wine
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import (BaggingClassifier, RandomForestClassifier,
                              AdaBoostClassifier, GradientBoostingClassifier)

np.random.seed(1)

data = load_wine()
X, y = data.data, data.target
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=1, stratify=y)

models = {
    "Decision Tree":     DecisionTreeClassifier(random_state=1),
    "Bagging":           BaggingClassifier(n_estimators=100, random_state=1),
    "Random Forest":     RandomForestClassifier(n_estimators=100, random_state=1),
    "AdaBoost":          AdaBoostClassifier(n_estimators=100, random_state=1),
    "Gradient Boosting": GradientBoostingClassifier(random_state=1),  # n_estimators=100 default
}

print(f"{'model':18s}  train   test")
for name, m in models.items():
    m.fit(X_train, y_train)
    print(f"{name:18s}  {m.score(X_train, y_train):.3f}   {m.score(X_test, y_test):.3f}")
# the lone tree overfits (train 1.0, test ~0.96); every ensemble lifts test above it

rf = models["Random Forest"]
importances = rf.feature_importances_
std = np.std([t.feature_importances_ for t in rf.estimators_], axis=0)
order = np.argsort(importances)  # ascending -> biggest bar on top with barh

plt.figure(figsize=(7, 6))
plt.barh(range(len(order)), importances[order], xerr=std[order],
         color="#4c72b0", ecolor="gray", capsize=2)
plt.yticks(range(len(order)), [data.feature_names[i] for i in order], fontsize=8)
plt.xlabel("mean decrease in impurity")
plt.title("random forest feature importances (wine)")
plt.savefig("feature_importance.png", dpi=110, bbox_inches="tight")
plt.close()

top = order[::-1][:3]
print("\ntop features:", ", ".join(data.feature_names[i] for i in top))
