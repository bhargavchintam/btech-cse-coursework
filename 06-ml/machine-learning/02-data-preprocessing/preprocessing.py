# preprocessing walkthrough: imputation, encoding, scaling, a stratified split
import numpy as np
import pandas as pd
from sklearn.datasets import load_wine
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler, MinMaxScaler, LabelEncoder, OneHotEncoder
from sklearn.model_selection import train_test_split

np.random.seed(1)
pd.set_option("display.width", 120)

# the classic small table: string categoricals + a couple of holes, the messy real-world shape
raw = pd.DataFrame({
    "country":   ["France", "Spain", "Germany", "Spain", "Germany", "France", "Spain", "France", "Germany", "France"],
    "age":       [44, 27, 30, 38, 40, 35, np.nan, 48, 50, 37],
    "salary":    [72000, 48000, 54000, 61000, np.nan, 58000, 52000, 79000, 83000, 67000],
    "purchased": ["No", "Yes", "No", "No", "Yes", "Yes", "No", "Yes", "No", "Yes"],
})
print(raw)
print("\nmissing per column:")
print(raw.isnull().sum())

num = ["age", "salary"]
raw[num] = SimpleImputer(strategy="mean").fit_transform(raw[num])
print("\nafter mean-imputation:")
print(raw.round(1))

# purchased is the target -> one 0/1 column; country is a feature -> one-hot so no fake ordering
y_small = LabelEncoder().fit_transform(raw["purchased"])
ohe = OneHotEncoder(sparse_output=False, dtype=int)
country = pd.DataFrame(ohe.fit_transform(raw[["country"]]), columns=ohe.get_feature_names_out())
X_small = pd.concat([country, raw[num]], axis=1)
print("\nencoded feature matrix:")
print(X_small)
print("labels:", y_small)

wine = load_wine(as_frame=True)
X, y = wine.data, wine.target
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25, stratify=y, random_state=1)
print("\nshapes  X_train:", X_train.shape, " X_test:", X_test.shape)
print("train class share:", y_train.value_counts(normalize=True).round(2).to_dict())
print("test  class share:", y_test.value_counts(normalize=True).round(2).to_dict())

# fit the scaler on train only -- touching test here leaks its mean/std into training
scaler = StandardScaler().fit(X_train)
X_train_std = scaler.transform(X_train)
X_test_std = scaler.transform(X_test)

feat = "proline"  # raw range in the thousands, dwarfs every other column before scaling
j = X.columns.get_loc(feat)
print(f"\n{feat} raw        train  mean {X_train[feat].mean():8.1f}  std {X_train[feat].std():8.1f}")
print(f"{feat} standardized train  mean {X_train_std[:, j].mean():8.2f}  std {X_train_std[:, j].std():8.2f}")
print(f"{feat} standardized test   mean {X_test_std[:, j].mean():8.2f}  std {X_test_std[:, j].std():8.2f}")

mm = MinMaxScaler().fit(X_train)
X_train_mm = mm.transform(X_train)
print(f"{feat} min-max      train  min  {X_train_mm[:, j].min():8.2f}  max {X_train_mm[:, j].max():8.2f}")
