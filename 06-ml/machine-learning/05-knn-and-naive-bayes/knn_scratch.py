# k-nearest neighbours from scratch on iris, checked against sklearn, then a sweep over k

import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score

np.random.seed(1)

X, y = load_iris(return_X_y=True)
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=1, stratify=y)

scaler = StandardScaler().fit(X_train)
X_train = scaler.transform(X_train)
X_test = scaler.transform(X_test)
# without the scaler petal-length (the wide-range column) would swamp the distance


def knn_predict(X_tr, y_tr, X_te, k):
    # ||a-b||^2 = ||a||^2 + ||b||^2 - 2 a.b  -> the whole test-vs-train distance matrix at once
    d2 = (X_te ** 2).sum(1)[:, None] + (X_tr ** 2).sum(1)[None, :] - 2 * X_te @ X_tr.T
    nn = np.argsort(d2, axis=1)[:, :k]
    return np.array([np.bincount(y_tr[row]).argmax() for row in nn])


y_pred = knn_predict(X_train, y_train, X_test, k=5)
acc_scratch = accuracy_score(y_test, y_pred)

clf = KNeighborsClassifier(n_neighbors=5).fit(X_train, y_train)
acc_sklearn = accuracy_score(y_test, clf.predict(X_test))

print(f"k=5   scratch acc: {acc_scratch:.4f}   sklearn acc: {acc_sklearn:.4f}")
assert np.isclose(acc_scratch, acc_sklearn), "scratch k-NN disagrees with sklearn"

ks = range(1, 21)
accs = [accuracy_score(y_test, knn_predict(X_train, y_train, X_test, k)) for k in ks]
best_k = int(np.argmax(accs)) + 1
print(f"best k = {best_k}   (test acc {max(accs):.4f})")

plt.figure(figsize=(7, 4.5))
plt.plot(list(ks), accs, marker="o", color="#2C6FB5")
plt.axvline(best_k, color="grey", ls="--", lw=1)
plt.xlabel("k (number of neighbours)")
plt.ylabel("test accuracy")
plt.title("iris — accuracy vs k")
plt.xticks(list(ks))
plt.grid(alpha=0.3)
plt.savefig("k_vs_accuracy.png", dpi=110, bbox_inches="tight")
