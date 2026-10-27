# SVM with a linear and an rbf kernel on the two-moons data
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import make_moons
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score

np.random.seed(1)

X, y = make_moons(n_samples=400, noise=0.25, random_state=1)
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=1, stratify=y)

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

models = {
    "linear": SVC(kernel="linear", C=1),
    "rbf": SVC(kernel="rbf", C=1, gamma="scale"),
}

for name, clf in models.items():
    clf.fit(X_train, y_train)
    acc = accuracy_score(y_test, clf.predict(X_test))
    print(f"{name:6s} kernel  test accuracy: {acc:.3f}   support vectors: {len(clf.support_vectors_)}")

# rbf bends the boundary around the interlocking moons; a straight line has no chance
x_min, x_max = X_train[:, 0].min() - 0.5, X_train[:, 0].max() + 0.5
y_min, y_max = X_train[:, 1].min() - 0.5, X_train[:, 1].max() + 0.5
XX, YY = np.meshgrid(np.linspace(x_min, x_max, 300),
                     np.linspace(y_min, y_max, 300))
grid = np.c_[XX.ravel(), YY.ravel()]

fig, axes = plt.subplots(1, 2, figsize=(12, 5), sharex=True, sharey=True)
for ax, (name, clf) in zip(axes, models.items()):
    Z = clf.predict(grid).reshape(XX.shape)
    ax.contourf(XX, YY, Z, alpha=0.25, cmap="coolwarm")
    ax.scatter(X_train[:, 0], X_train[:, 1], c=y_train, cmap="coolwarm",
               s=20, edgecolors="k", linewidths=0.3)
    acc = accuracy_score(y_test, clf.predict(X_test))
    ax.set_title(f"{name} kernel  —  test acc {acc:.2f}")
    ax.set_xlabel("x1 (scaled)")
axes[0].set_ylabel("x2 (scaled)")
fig.suptitle("SVM decision boundaries on two moons")
plt.savefig("svm.png", dpi=110, bbox_inches="tight")
