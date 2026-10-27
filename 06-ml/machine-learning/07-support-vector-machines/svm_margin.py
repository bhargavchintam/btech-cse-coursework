# linear SVM on a separable blob: the maximum-margin street and its support vectors
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.svm import SVC

np.random.seed(1)

X, y = make_blobs(n_samples=60, centers=2, cluster_std=1.2, random_state=1)

clf = SVC(kernel="linear", C=100)
clf.fit(X, y)

w = clf.coef_[0]
b = clf.intercept_[0]
print("weight vector w:", w)
print("bias b:", b)
print("margin width 2/||w||:", 2 / np.linalg.norm(w))
print("support vectors:", len(clf.support_vectors_))

fig, ax = plt.subplots(figsize=(7, 6))
ax.scatter(X[:, 0], X[:, 1], c=y, cmap="coolwarm", s=35, edgecolors="k", linewidths=0.4)

xlim = ax.get_xlim()
ylim = ax.get_ylim()
xx = np.linspace(xlim[0], xlim[1], 40)
yy = np.linspace(ylim[0], ylim[1], 40)
XX, YY = np.meshgrid(xx, yy)
Z = clf.decision_function(np.c_[XX.ravel(), YY.ravel()]).reshape(XX.shape)
# levels -1/0/+1 are the two gutters and the centre of the street
ax.contour(XX, YY, Z, levels=[-1, 0, 1], colors="k",
           linestyles=["--", "-", "--"], linewidths=[1, 1.6, 1])

ax.scatter(clf.support_vectors_[:, 0], clf.support_vectors_[:, 1],
           s=180, facecolors="none", edgecolors="k", linewidths=1.4,
           label="support vectors")

ax.set_title("Linear SVM — the widest street between two classes")
ax.set_xlabel("x1")
ax.set_ylabel("x2")
ax.legend(loc="upper left")
plt.savefig("svm_margin.png", dpi=110, bbox_inches="tight")
