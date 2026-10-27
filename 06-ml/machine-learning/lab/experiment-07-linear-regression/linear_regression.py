# Bindu Bhargava  27-11-20
# linear regression on the diabetes data — coefficients, MSE, R2, predicted-vs-actual fit

import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import load_diabetes
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score

np.random.seed(1)

data = load_diabetes()
X, y = data.data, data.target
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=1)

reg = LinearRegression().fit(X_train, y_train)
y_pred = reg.predict(X_test)

print("coefficients:")
for name, c in zip(data.feature_names, reg.coef_):
    print(f"  {name:<4} {c:9.2f}")
print(f"intercept: {reg.intercept_:.2f}")

mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)
print(f"\nMSE:  {mse:.2f}")
print(f"RMSE: {np.sqrt(mse):.2f}")
print(f"R2:   {r2:.4f}")

lo, hi = y_test.min(), y_test.max()
plt.figure(figsize=(5.5, 5.5))
plt.scatter(y_test, y_pred, s=25, alpha=0.7, color="#3b7dd8", edgecolor="k", linewidth=0.3)
plt.plot([lo, hi], [lo, hi], "--", color="crimson", lw=1.5, label="perfect prediction")
plt.xlabel("actual disease progression")
plt.ylabel("predicted")
plt.title(f"Diabetes — predicted vs actual  (R² = {r2:.2f})")
plt.legend()
plt.grid(alpha=0.3)
plt.savefig("fit.png", dpi=110, bbox_inches="tight")
