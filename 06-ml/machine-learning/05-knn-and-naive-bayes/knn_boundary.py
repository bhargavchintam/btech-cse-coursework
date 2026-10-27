# knn decision boundary on two iris features (petal length / petal width)

import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
from sklearn.datasets import load_iris
from sklearn.neighbors import KNeighborsClassifier

np.random.seed(1)

iris = load_iris()
X = iris.data[:, 2:4]   # petals separate the three species far better than sepals
y = iris.target

clf = KNeighborsClassifier(n_neighbors=5).fit(X, y)

h = 0.02
x_min, x_max = X[:, 0].min() - 0.5, X[:, 0].max() + 0.5
y_min, y_max = X[:, 1].min() - 0.5, X[:, 1].max() + 0.5
xx, yy = np.meshgrid(np.arange(x_min, x_max, h), np.arange(y_min, y_max, h))
Z = clf.predict(np.c_[xx.ravel(), yy.ravel()]).reshape(xx.shape)

cmap_bg = ListedColormap(["#FBE6CE", "#E4F0D4", "#D6E6F4"])
cmap_pt = ListedColormap(["#E8820C", "#5AA02C", "#2C6FB5"])

plt.figure(figsize=(7, 5.5))
plt.contourf(xx, yy, Z, cmap=cmap_bg, alpha=0.9)
for i, name in enumerate(iris.target_names):
    plt.scatter(X[y == i, 0], X[y == i, 1], color=cmap_pt(i), label=name,
                edgecolor="k", s=30)
plt.xlabel("petal length (cm)")
plt.ylabel("petal width (cm)")
plt.title("k-NN decision boundary (k=5)")
plt.legend()
plt.savefig("knn_boundary.png", dpi=110, bbox_inches="tight")
