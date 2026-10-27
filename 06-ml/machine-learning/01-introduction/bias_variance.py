# bias-variance decomposition — resample many training sets, watch bias^2 fall and variance rise with degree
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.preprocessing import PolynomialFeatures, StandardScaler
from sklearn.linear_model import LinearRegression
from sklearn.pipeline import make_pipeline

np.random.seed(1)


def true_f(x):
    return np.sin(2 * np.pi * x)


noise = 0.15
n_train = 30
n_sets = 300
degrees = list(range(1, 10))

x_test = np.linspace(0, 1, 100)
f_test = true_f(x_test)
Xt = x_test.reshape(-1, 1)

bias2, variance, total = [], [], []
for d in degrees:
    # each row is one model's prediction curve, fit on its own fresh noisy sample
    preds = np.zeros((n_sets, len(x_test)))
    for s in range(n_sets):
        x = np.random.rand(n_train)
        y = true_f(x) + np.random.normal(0, noise, n_train)
        # scale the powers or the high-degree design matrix is hopelessly ill-conditioned
        model = make_pipeline(PolynomialFeatures(d), StandardScaler(), LinearRegression())
        model.fit(x.reshape(-1, 1), y)
        preds[s] = model.predict(Xt)

    mean_pred = preds.mean(axis=0)
    b2 = np.mean((mean_pred - f_test) ** 2)          # how far the average model is from truth
    var = np.mean(preds.var(axis=0))                 # how much the models scatter around their average
    bias2.append(b2)
    variance.append(var)
    total.append(b2 + var + noise ** 2)
    print(f"degree {d:2d}: bias^2 {b2:.4f}   variance {var:.4f}   total {b2 + var + noise ** 2:.4f}")

best = degrees[int(np.argmin(total))]

plt.figure(figsize=(8, 5))
plt.plot(degrees, bias2, "o-", label="bias$^2$")
plt.plot(degrees, variance, "s-", label="variance")
plt.plot(degrees, total, "^-", lw=2, color="crimson", label="total test error")
plt.axhline(noise ** 2, ls=":", color="gray", label="irreducible noise")
plt.axvline(best, ls="--", color="crimson", alpha=0.5)
plt.xlabel("polynomial degree  (model capacity)")
plt.ylabel("error")
plt.title(f"bias-variance tradeoff — U-shaped test error, minimum at degree {best}")
plt.legend()
plt.grid(alpha=0.3)
plt.ylim(0, min(0.6, max(total) * 1.1))
plt.savefig("bias_variance.png", dpi=110, bbox_inches="tight")
