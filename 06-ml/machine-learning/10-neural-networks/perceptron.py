# Rosenblatt's perceptron from scratch: it learns AND and OR, but can't learn XOR.
# Also draws the three activation functions used later in the MLP.

import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

np.random.seed(1)

X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
AND = np.array([0, 0, 0, 1])
OR = np.array([0, 1, 1, 1])
XOR = np.array([0, 1, 1, 0])


def train_perceptron(X, y, lr=0.1, epochs=20):
    w = np.zeros(X.shape[1])
    b = 0.0
    for _ in range(epochs):
        for xi, target in zip(X, y):
            pred = 1 if xi @ w + b >= 0 else 0
            # the perceptron rule: nudge weights only on a mistake, toward the input
            w += lr * (target - pred) * xi
            b += lr * (target - pred)
    return w, b


def accuracy(X, y, w, b):
    pred = (X @ w + b >= 0).astype(int)
    return (pred == y).mean()


for name, y in [("AND", AND), ("OR", OR), ("XOR", XOR)]:
    w, b = train_perceptron(X, y)
    acc = accuracy(X, y, w, b)
    print(f"{name}:  w={np.round(w, 2)}  b={b:+.2f}   acc={acc:.2f}")

# AND and OR hit 1.00 — they're linearly separable, one line splits the 0s from the 1s.
# XOR sticks at 0.50: no straight line can do it, so Rosenblatt's rule oscillates forever.

z = np.linspace(-6, 6, 400)
sigmoid = 1 / (1 + np.exp(-z))
tanh = np.tanh(z)
relu = np.maximum(0, z)

fig, ax = plt.subplots(1, 3, figsize=(12, 4), constrained_layout=True)
for a, (curve, ttl, formula) in zip(ax, [
    (sigmoid, "sigmoid", r"$\sigma(z)=\frac{1}{1+e^{-z}}$"),
    (tanh, "tanh", r"$\tanh(z)$"),
    (relu, "ReLU", r"$\max(0,\,z)$"),
]):
    a.plot(z, curve, color="#c0392b", lw=2)
    a.axhline(0, color="gray", lw=0.8)
    a.axvline(0, color="gray", lw=0.8)
    a.set_title(f"{ttl}   {formula}")
    a.set_xlabel("z")
    a.grid(alpha=0.3)
ax[0].set_ylim(-0.1, 1.1)
ax[1].set_ylim(-1.1, 1.1)
fig.suptitle("Activation functions — the non-linearity a neuron applies to its weighted sum")
plt.savefig("activations.png", dpi=110, bbox_inches="tight")
