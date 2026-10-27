# A 2-layer neural net (one ReLU hidden layer, sigmoid output) written from scratch in numpy:
# forward pass + backprop by hand, trained on make_moons. Checked against sklearn's MLPClassifier.

import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import make_moons
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score

np.random.seed(1)

X, y = make_moons(n_samples=600, noise=0.2, random_state=1)
y = y.reshape(-1, 1).astype(float)
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25, random_state=1, stratify=y)


def relu(z):
    return np.maximum(0, z)


def sigmoid(z):
    return 1 / (1 + np.exp(-z))


class MLP:
    def __init__(self, n_in, n_hidden, seed=1):
        rng = np.random.default_rng(seed)
        # He initialisation: scale by sqrt(2/n_in) keeps ReLU activations from dying or blowing up
        self.W1 = rng.standard_normal((n_in, n_hidden)) * np.sqrt(2 / n_in)
        self.b1 = np.zeros((1, n_hidden))
        self.W2 = rng.standard_normal((n_hidden, 1)) * np.sqrt(2 / n_hidden)
        self.b2 = np.zeros((1, 1))

    def forward(self, X):
        self.Z1 = X @ self.W1 + self.b1
        self.A1 = relu(self.Z1)
        self.Z2 = self.A1 @ self.W2 + self.b2
        self.A2 = sigmoid(self.Z2)
        return self.A2

    def backward(self, X, y, lr):
        m = X.shape[0]
        # dZ2 is where the cross-entropy + sigmoid collapse to a clean (prediction - truth)
        dZ2 = (self.A2 - y) / m
        dW2 = self.A1.T @ dZ2
        db2 = dZ2.sum(axis=0, keepdims=True)
        dA1 = dZ2 @ self.W2.T
        dZ1 = dA1 * (self.Z1 > 0)          # ReLU derivative is 1 where the pre-activation was positive
        dW1 = X.T @ dZ1
        db1 = dZ1.sum(axis=0, keepdims=True)
        for param, grad in [(self.W1, dW1), (self.b1, db1), (self.W2, dW2), (self.b2, db2)]:
            param -= lr * grad


def bce(yhat, y):
    eps = 1e-9
    return -np.mean(y * np.log(yhat + eps) + (1 - y) * np.log(1 - yhat + eps))


net = MLP(n_in=2, n_hidden=16)
losses = []
for epoch in range(3000):
    yhat = net.forward(X_train)
    losses.append(bce(yhat, y_train))
    net.backward(X_train, y_train, lr=0.5)

for e in [0, 500, 1500, 2999]:
    print(f"epoch {e:4d}   loss {losses[e]:.4f}")

pred_train = (net.forward(X_train) >= 0.5).astype(int)
pred_test = (net.forward(X_test) >= 0.5).astype(int)
acc_train = accuracy_score(y_train, pred_train)
acc_test = accuracy_score(y_test, pred_test)
print(f"scratch   train acc {acc_train:.4f}   test acc {acc_test:.4f}")

clf = MLPClassifier(hidden_layer_sizes=(16,), activation="relu",
                    max_iter=3000, random_state=1)
clf.fit(X_train, y_train.ravel())
print(f"sklearn   test acc {accuracy_score(y_test, clf.predict(X_test)):.4f}")

fig, ax = plt.subplots(figsize=(6, 4))
ax.plot(losses, color="#2c3e50", lw=1.6)
ax.set_title("training loss — backprop driving the cross-entropy down")
ax.set_xlabel("epoch")
ax.set_ylabel("binary cross-entropy")
ax.grid(alpha=0.3)
plt.savefig("loss_curve.png", dpi=110, bbox_inches="tight")
plt.close()

xx, yy = np.meshgrid(np.linspace(X[:, 0].min() - 0.5, X[:, 0].max() + 0.5, 300),
                     np.linspace(X[:, 1].min() - 0.5, X[:, 1].max() + 0.5, 300))
grid = np.c_[xx.ravel(), yy.ravel()]
zz = net.forward(grid).reshape(xx.shape)

fig, ax = plt.subplots(figsize=(6.5, 5))
ax.contourf(xx, yy, zz, levels=20, cmap="RdBu_r", alpha=0.7)
ax.contour(xx, yy, zz, levels=[0.5], colors="black", linewidths=1.5)
ax.scatter(X[:, 0], X[:, 1], c=y.ravel(), cmap="RdBu", edgecolor="k", s=18, linewidth=0.3)
ax.set_title(f"MLP decision boundary on make_moons  (test acc {acc_test:.2f})")
ax.set_xlabel("x1")
ax.set_ylabel("x2")
plt.savefig("nn_boundary.png", dpi=110, bbox_inches="tight")
