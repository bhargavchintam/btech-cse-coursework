# linear regression on one feature: gradient descent vs the normal equation vs sklearn
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import make_regression
from sklearn.linear_model import LinearRegression

np.random.seed(1)

X, y = make_regression(n_samples=120, n_features=1, noise=18.0, bias=40.0, random_state=1)
x = X.ravel()
m = len(y)


def cost(w, b):
    err = w * x + b - y
    return (err @ err) / (2 * m)


w, b, lr, n_iter = 0.0, 0.0, 0.1, 2000
history = []
for _ in range(n_iter):
    err = w * x + b - y
    dw = (x @ err) / m
    db = err.sum() / m
    w -= lr * dw
    b -= lr * db
    history.append(cost(w, b))

# normal equation on the design matrix [1, x]; theta = (XᵀX)⁻¹ Xᵀy
Xb = np.column_stack([np.ones(m), x])
theta = np.linalg.inv(Xb.T @ Xb) @ Xb.T @ y
b_ne, w_ne = theta

reg = LinearRegression().fit(X, y)
w_sk, b_sk = reg.coef_[0], reg.intercept_

print(f"gradient descent   w={w:.4f}  b={b:.4f}  cost={history[-1]:.4f}")
print(f"normal equation    w={w_ne:.4f}  b={b_ne:.4f}")
print(f"sklearn            w={w_sk:.4f}  b={b_sk:.4f}")

assert np.allclose([w, b], [w_ne, b_ne], atol=1e-3)
assert np.allclose([w_ne, b_ne], [w_sk, b_sk], atol=1e-6)

grid = np.linspace(x.min(), x.max(), 100)
plt.figure(figsize=(6, 4.5))
plt.scatter(x, y, s=18, alpha=0.6, label="data")
plt.plot(grid, w * grid + b, color="crimson", lw=2, label=f"fit  y = {w:.1f}x + {b:.1f}")
plt.xlabel("x")
plt.ylabel("y")
plt.title("Linear regression fit (gradient descent)")
plt.legend()
plt.grid(alpha=0.3)
plt.savefig("regression_fit.png", dpi=110, bbox_inches="tight")

plt.figure(figsize=(6, 4.5))
plt.plot(history, color="steelblue")
plt.xlabel("iteration")
plt.ylabel("cost  J(w, b)")
plt.title("Cost vs iteration")
plt.grid(alpha=0.3)
plt.savefig("cost_curve.png", dpi=110, bbox_inches="tight")
