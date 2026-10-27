# EDA for the breast-cancer project: class balance, which features separate the
# two diagnoses, and how heavily the 30 features correlate with each other.

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import seaborn as sns
from dataset import load_frame

df, features = load_frame()

n = len(df)
counts = df["diagnosis"].value_counts().sort_index()
benign, malignant = counts[0], counts[1]
print(f"samples: {n},  features: {len(features)}")
print(f"benign (0):    {benign}  ({benign / n:.1%})")
print(f"malignant (1): {malignant}  ({malignant / n:.1%})")
print(f"no missing values: {df.isna().sum().sum() == 0}\n")

# rank features by how far apart the two class means sit, in pooled-std units.
# this is basically the signal-to-noise of each feature on its own.
means = df.groupby("diagnosis")[features].mean()
stds = df.groupby("diagnosis")[features].std()
sep = (means.loc[1] - means.loc[0]).abs() / ((stds.loc[0] + stds.loc[1]) / 2)
sep = sep.sort_values(ascending=False)
print("most separating features (|mean gap| / avg std):")
for f in sep.head(8).index:
    print(f"  {f:24s} {sep[f]:.2f}")

top6 = sep.head(6).index

fig, axes = plt.subplots(2, 3, figsize=(13, 7.5))
for ax, f in zip(axes.ravel(), top6):
    ax.hist(df[df.diagnosis == 0][f], bins=25, alpha=0.6, label="benign", color="#2c7fb8")
    ax.hist(df[df.diagnosis == 1][f], bins=25, alpha=0.6, label="malignant", color="#c0392b")
    ax.set_title(f)
    ax.set_ylabel("count")
    ax.legend(fontsize=8)
fig.suptitle("Class separation on the six most discriminative features", y=1.01)
plt.tight_layout()
plt.savefig("eda_features.png", dpi=110, bbox_inches="tight")
plt.close()

corr = df[features].corr()
plt.figure(figsize=(12, 10))
sns.heatmap(corr, cmap="coolwarm", center=0, square=True,
            xticklabels=True, yticklabels=True, cbar_kws={"shrink": 0.7})
plt.xticks(fontsize=7)
plt.yticks(fontsize=7)
plt.title("Feature correlation (30 features)")
plt.savefig("eda_corr.png", dpi=110, bbox_inches="tight")
plt.close()

# the radius/perimeter/area trio is basically one measurement three ways
pairs = []
cols = corr.columns
for i in range(len(cols)):
    for j in range(i + 1, len(cols)):
        pairs.append((corr.iloc[i, j], cols[i], cols[j]))
pairs.sort(reverse=True)
print("\nmost correlated feature pairs (a lot of redundancy here):")
for c, a, b in pairs[:5]:
    print(f"  {c:.3f}  {a}  <->  {b}")
