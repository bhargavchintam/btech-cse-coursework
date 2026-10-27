# polynomials of degree 1, 4, 15 on a noisy sine sample — underfit / good fit / overfit
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
from sklearn.pipeline import make_pipeline
from sklearn.metrics import mean_squared_error

np.random.seed(1)


def true_f(x):
    return np.sin(2 * np.pi * x)


n = 30
x = np.sort(np.random.rand(n))
y = true_f(x) + np.random.normal(0, 0.15, n)

idx = np.random.permutation(n)
cut = int(0.7 * n)
train, test = idx[:cut], idx[cut:]
X = x.reshape(-1, 1)

xx = np.linspace(0, 1, 400).reshape(-1, 1)
degrees = [1, 4, 15]
labels = ["underfit", "good fit", "overfit"]

fig, axes = plt.subplots(1, 3, figsize=(15, 4.5), sharey=True)
for ax, d, lab in zip(axes, degrees, labels):
    model = make_pipeline(PolynomialFeatures(d), LinearRegression())
    model.fit(X[train], y[train])
    tr = mean_squared_error(y[train], model.predict(X[train]))
    te = mean_squared_error(y[test], model.predict(X[test]))

    ax.plot(xx, true_f(xx), "g--", lw=1.5, label="true sine")
    ax.plot(xx, model.predict(xx), "b-", lw=2, label=f"degree {d}")
    ax.scatter(x[train], y[train], c="k", s=25, label="train")
    ax.scatter(x[test], y[test], c="r", s=45, marker="x", label="test")
    ax.set_ylim(-1.6, 1.6)
    ax.set_title(f"{lab}  (deg {d})\ntrain MSE {tr:.3f}   test MSE {te:.3f}")
    ax.set_xlabel("x")
    ax.legend(loc="upper right", fontsize=8)
    print(f"degree {d:2d}: train MSE {tr:.4f}   test MSE {te:.4f}")

axes[0].set_ylabel("y")
plt.savefig("overfitting.png", dpi=110, bbox_inches="tight")
