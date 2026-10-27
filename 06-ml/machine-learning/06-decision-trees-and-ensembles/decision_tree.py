# decision trees on breast cancer: an unpruned tree overfits, a shallow one generalises
# iris/wine are too separable to overfit (their full tree is only depth 3), so use a harder set
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.inspection import DecisionBoundaryDisplay

np.random.seed(1)

data = load_breast_cancer()
X, y = data.data, data.target
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=1, stratify=y)

deep = DecisionTreeClassifier(random_state=1).fit(X_train, y_train)
pruned = DecisionTreeClassifier(max_depth=3, random_state=1).fit(X_train, y_train)

print("             depth   train    test")
for name, clf in [("unpruned", deep), ("max_depth=3", pruned)]:
    tr = clf.score(X_train, y_train)
    te = clf.score(X_test, y_test)
    print(f"  {name:12s} {clf.get_depth():3d}   {tr:.3f}   {te:.3f}")
# unpruned hits train 1.0 but tests LOWER than the depth-3 tree -> classic overfitting

gini = DecisionTreeClassifier(max_depth=3, criterion="gini", random_state=1).fit(X_train, y_train)
entr = DecisionTreeClassifier(max_depth=3, criterion="entropy", random_state=1).fit(X_train, y_train)
print("\nroot split (feature <= threshold) under each criterion:")
for name, clf in [("gini", gini), ("entropy", entr)]:
    t = clf.tree_
    f, thr, imp = t.feature[0], t.threshold[0], t.impurity[0]
    print(f"  {name:8s}: {data.feature_names[f]} <= {thr:.2f}   root impurity {imp:.3f}")

plt.figure(figsize=(13, 7))
plot_tree(pruned, feature_names=data.feature_names, class_names=data.target_names,
          filled=True, rounded=True, fontsize=7)
plt.title("breast cancer decision tree (max_depth=3)")
plt.savefig("tree.png", dpi=110, bbox_inches="tight")
plt.close()

# boundary in 2D on two strong, partly-overlapping features -> shows the axis-aligned rectangles
pair = [data.feature_names.tolist().index(n) for n in ["mean radius", "mean concave points"]]
Xp = X[:, pair]
Xp_tr, Xp_te, yp_tr, yp_te = train_test_split(
    Xp, y, test_size=0.3, random_state=1, stratify=y)
clf2 = DecisionTreeClassifier(max_depth=4, random_state=1).fit(Xp_tr, yp_tr)

fig, ax = plt.subplots(figsize=(7, 5))
DecisionBoundaryDisplay.from_estimator(
    clf2, Xp, ax=ax, response_method="predict", alpha=0.3,
    xlabel="mean radius", ylabel="mean concave points")
for i, colour, lab in zip([0, 1], ["#d95f02", "#1b9e77"], data.target_names):
    ax.scatter(Xp[y == i, 0], Xp[y == i, 1], c=colour, edgecolor="k", s=18, label=lab)
ax.set_xlim(Xp[:, 0].min() - 0.5, Xp[:, 0].max() + 0.5)
ax.set_ylim(Xp[:, 1].min() - 0.02, Xp[:, 1].max() + 0.02)
ax.set_title("decision tree boundary (axis-aligned rectangles, depth 4)")
ax.legend()
plt.savefig("tree_boundary.png", dpi=110, bbox_inches="tight")
plt.close()
