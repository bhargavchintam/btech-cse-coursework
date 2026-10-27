# linear vs rbf vs poly on make_moons: why the kernel trick matters
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import make_moons
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC

np.random.seed(1)

X, y = make_moons(n_samples=300, noise=0.22, random_state=1)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=1)

kernels = [
    ("linear", SVC(kernel="linear", C=1)),
    ("rbf", SVC(kernel="rbf", C=1, gamma="scale")),
    ("poly", SVC(kernel="poly", degree=3, C=1, gamma="scale")),
]

x_min, x_max = X[:, 0].min() - 0.5, X[:, 0].max() + 0.5
y_min, y_max = X[:, 1].min() - 0.5, X[:, 1].max() + 0.5
XX, YY = np.meshgrid(np.linspace(x_min, x_max, 300),
                     np.linspace(y_min, y_max, 300))
grid = np.c_[XX.ravel(), YY.ravel()]

fig, axes = plt.subplots(1, 3, figsize=(15, 5), sharex=True, sharey=True)
for ax, (name, clf) in zip(axes, kernels):
    clf.fit(X_train, y_train)
    acc = clf.score(X_test, y_test)
    print(f"{name:6s} test acc: {acc:.3f}   (support vectors: {len(clf.support_vectors_)})")

    Z = clf.predict(grid).reshape(XX.shape)
    ax.contourf(XX, YY, Z, alpha=0.25, cmap="coolwarm")
    ax.scatter(X_train[:, 0], X_train[:, 1], c=y_train, cmap="coolwarm",
               s=20, edgecolors="k", linewidths=0.3)
    ax.set_title(f"{name}  —  acc {acc:.2f}")
    ax.set_xlabel("x1")
axes[0].set_ylabel("x2")
plt.savefig("kernel_boundaries.png", dpi=110, bbox_inches="tight")

# a straight line cant cut the moons apart; the rbf kernel bends the boundary
print()

# C trades margin width against training errors; gamma sets the reach of each rbf bump
print("effect of C (rbf, gamma=scale):")
for C in [0.1, 1, 10, 100]:
    m = SVC(kernel="rbf", C=C, gamma="scale").fit(X_train, y_train)
    print(f"  C={C:<5} test acc {m.score(X_test, y_test):.3f}   sv {len(m.support_vectors_)}")

print("effect of gamma (rbf, C=1):")
for g in [0.1, 1, 10, 100]:
    m = SVC(kernel="rbf", C=1, gamma=g).fit(X_train, y_train)
    print(f"  gamma={g:<5} test acc {m.score(X_test, y_test):.3f}   sv {len(m.support_vectors_)}")
