# logistic regression from scratch (sigmoid + cross-entropy + batch GD) on breast_cancer,
# checked against sklearn's LogisticRegression

import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

np.random.seed(1)


def sigmoid(z):
    return 1.0 / (1.0 + np.exp(-z))


def train(X, y, lr=0.1, epochs=2000):
    m, n = X.shape
    w = np.zeros(n)
    b = 0.0
    losses = []
    for _ in range(epochs):
        yhat = sigmoid(X @ w + b)
        # gradient of the cross-entropy wrt w is just X.T @ (yhat - y) / m
        err = yhat - y
        w -= lr * (X.T @ err) / m
        b -= lr * err.mean()
        eps = 1e-9
        losses.append(-np.mean(y * np.log(yhat + eps) + (1 - y) * np.log(1 - yhat + eps)))
    return w, b, losses


data = load_breast_cancer()
X, y = data.data, data.target
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=1, stratify=y)

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

w, b, losses = train(X_train, y_train, lr=0.1, epochs=2000)
y_pred = (sigmoid(X_test @ w + b) >= 0.5).astype(int)
acc = accuracy_score(y_test, y_pred)

clf = LogisticRegression(max_iter=5000, random_state=1)
clf.fit(X_train, y_train)
acc_sk = accuracy_score(y_test, clf.predict(X_test))

print(f"scratch test acc: {acc:.4f}")
print(f"sklearn test acc: {acc_sk:.4f}")
print(f"final cross-entropy loss: {losses[-1]:.4f}")
# weight vectors point the same way even though the two solvers regularise differently
cos = (w @ clf.coef_[0]) / (np.linalg.norm(w) * np.linalg.norm(clf.coef_[0]))
print(f"cosine(scratch w, sklearn w): {cos:.4f}")

z = np.linspace(-8, 8, 400)
fig, ax = plt.subplots(1, 2, figsize=(11, 4.2))
ax[0].plot(z, sigmoid(z), color="#c0392b", lw=2)
ax[0].axhline(0.5, color="gray", ls="--", lw=1)
ax[0].axvline(0, color="gray", ls="--", lw=1)
ax[0].set_title(r"$\sigma(z)=1/(1+e^{-z})$")
ax[0].set_xlabel("z = w·x + b")
ax[0].set_ylabel("P(y=1 | x)")
ax[0].grid(alpha=0.3)

ax[1].plot(losses, color="#2c3e50", lw=1.8)
ax[1].set_title("training loss (batch gradient descent)")
ax[1].set_xlabel("epoch")
ax[1].set_ylabel("binary cross-entropy")
ax[1].grid(alpha=0.3)

plt.savefig("sigmoid.png", dpi=110, bbox_inches="tight")
