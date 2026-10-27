#!/usr/bin/env python3
import numpy as np
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score

y = np.array([78, 85, 55, 80, 62, 45, 92, 40, 88, 58], dtype=float)
pred = np.array([75, 83, 58, 79, 60, 48, 90, 43, 86, 60], dtype=float)

mse = ((y - pred) ** 2).mean()
rmse = np.sqrt(mse)
mae = np.abs(y - pred).mean()
ss_res = ((y - pred) ** 2).sum()
ss_tot = ((y - y.mean()) ** 2).sum()
r2 = 1 - ss_res / ss_tot

print("from scratch:")
print(f"  MSE  {mse:.4f}")
print(f"  RMSE {rmse:.4f}")
print(f"  MAE  {mae:.4f}")
print(f"  R2   {r2:.4f}")

print("sklearn.metrics:")
print(f"  MSE  {mean_squared_error(y, pred):.4f}")
print(f"  RMSE {np.sqrt(mean_squared_error(y, pred)):.4f}")
print(f"  MAE  {mean_absolute_error(y, pred):.4f}")
print(f"  R2   {r2_score(y, pred):.4f}")
