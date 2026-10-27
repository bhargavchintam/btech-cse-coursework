# a 2-4-1 neural net trained by backpropagation to learn XOR — the problem a
# single perceptron can't crack, because one hidden layer bends the decision surface.
import numpy as np

np.random.seed(1)

X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]], dtype=float)
y = np.array([[0], [1], [1], [0]], dtype=float)


def sigmoid(z):
    return 1 / (1 + np.exp(-z))


def dsigmoid(a):
    return a * (1 - a)          # derivative in terms of the activation, not z


n_in, n_hid, n_out = 2, 4, 1
W1 = np.random.uniform(-1, 1, (n_in, n_hid))
b1 = np.zeros((1, n_hid))
W2 = np.random.uniform(-1, 1, (n_hid, n_out))
b2 = np.zeros((1, n_out))

lr, epochs = 0.5, 10000
for epoch in range(epochs):
    a1 = sigmoid(X @ W1 + b1)
    a2 = sigmoid(a1 @ W2 + b2)

    error = a2 - y
    d2 = error * dsigmoid(a2)            # delta at the output layer
    d1 = (d2 @ W2.T) * dsigmoid(a1)      # push the error back through W2

    W2 -= lr * a1.T @ d2
    b2 -= lr * d2.sum(axis=0, keepdims=True)
    W1 -= lr * X.T @ d1
    b1 -= lr * d1.sum(axis=0, keepdims=True)

    if epoch % 1000 == 0:
        loss = np.mean(error ** 2)
        print(f"epoch {epoch:5d}   loss = {loss:.5f}")

a1 = sigmoid(X @ W1 + b1)
out = sigmoid(a1 @ W2 + b2)
print(f"epoch {epochs:5d}   loss = {np.mean((out - y) ** 2):.5f}\n")

print("final predictions:")
for xi, o in zip(X, out.ravel()):
    print(f"  {xi.astype(int)} -> {o:.3f}  (rounded {int(round(o))})")

assert np.array_equal(np.round(out).astype(int), y.astype(int)), "XOR not learned"
print("\nall four XOR cases correct")
