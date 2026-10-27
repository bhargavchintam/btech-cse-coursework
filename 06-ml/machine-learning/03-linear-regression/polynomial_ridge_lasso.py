# polynomial regression: underfit vs overfit, then Ridge/Lasso taming the degree-15 fit
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import PolynomialFeatures, StandardScaler
from sklearn.linear_model import LinearRegression, Ridge, Lasso
from sklearn.metrics import r2_score
from sklearn.model_selection import train_test_split

np.random.seed(1)

f = lambda x: np.cos(1.5 * np.pi * x)
x = np.sort(np.random.uniform(0, 1, 40))
y = f(x) + np.random.normal(0, 0.35, x.size)
X = x.reshape(-1, 1)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.35, random_state=1)

grid = np.linspace(0, 1, 300).reshape(-1, 1)


def poly_model(degree, estimator=None):
    return make_pipeline(
        PolynomialFeatures(degree), StandardScaler(),
        estimator if estimator is not None else LinearRegression(),
    )


plt.figure(figsize=(6.5, 4.8))
plt.scatter(X_train, y_train, s=22, alpha=0.6, color="gray", label="train data")
plt.plot(grid, f(grid), color="black", ls="--", lw=1, label="true f(x)")
for degree, colour in [(1, "seagreen"), (4, "royalblue"), (15, "crimson")]:
    model = poly_model(degree).fit(X_train, y_train)
    r2_tr = r2_score(y_train, model.predict(X_train))
    r2_te = r2_score(y_test, model.predict(X_test))
    print(f"degree {degree:>2}:  train R2 = {r2_tr:.3f}   test R2 = {r2_te:.3f}")
    plt.plot(grid, model.predict(grid), color=colour, lw=2, label=f"deg {degree}")
plt.ylim(y.min() - 0.6, y.max() + 0.6)
plt.xlabel("x")
plt.ylabel("y")
plt.title("Polynomial degree: under- vs over-fitting")
plt.legend(fontsize=8)
plt.grid(alpha=0.3)
plt.savefig("poly_fits.png", dpi=110, bbox_inches="tight")

print()
# same degree-15 basis, three ways of handling the weights
fits = {
    "OLS (no penalty)": ("crimson", poly_model(15)),
    "Ridge (L2, a=1.0)": ("darkorange", poly_model(15, Ridge(alpha=1.0))),
    "Lasso (L1, a=0.02)": ("purple", poly_model(15, Lasso(alpha=0.02, max_iter=200000))),
}
plt.figure(figsize=(6.5, 4.8))
plt.scatter(X_train, y_train, s=22, alpha=0.6, color="gray", label="train data")
plt.plot(grid, f(grid), color="black", ls="--", lw=1, label="true f(x)")
for name, (colour, model) in fits.items():
    model.fit(X_train, y_train)
    r2_te = r2_score(y_test, model.predict(X_test))
    nonzero = int(np.sum(np.abs(model[-1].coef_) > 1e-4))
    print(f"{name:<20} test R2 = {r2_te:.3f}   nonzero coefs = {nonzero}/15")
    plt.plot(grid, model.predict(grid), color=colour, lw=2, label=name)
plt.ylim(y.min() - 0.6, y.max() + 0.6)
plt.xlabel("x")
plt.ylabel("y")
plt.title("Regularizing the degree-15 fit")
plt.legend(fontsize=8)
plt.grid(alpha=0.3)
plt.savefig("regularization.png", dpi=110, bbox_inches="tight")
