# exploratory analysis of the iris data: class balance, correlations, feature distributions
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns
from sklearn.datasets import load_iris

np.random.seed(1)
sns.set_style("whitegrid")
pd.set_option("display.width", 120)

iris = load_iris(as_frame=True)
df = iris.frame
df["species"] = df["target"].map(dict(enumerate(iris.target_names)))
cols = iris.feature_names

print(df.head())
print("\n", df[cols].describe().round(2), sep="")
print("\nclass balance:")
print(df["species"].value_counts())

corr = df[cols].corr()
print("\ncorrelations:")
print(corr.round(2))

fig, ax = plt.subplots(figsize=(6, 5))
sns.heatmap(corr, annot=True, fmt=".2f", cmap="coolwarm", vmin=-1, vmax=1, square=True, ax=ax)
ax.set_title("iris feature correlations")
plt.savefig("corr_heatmap.png", dpi=110, bbox_inches="tight")
plt.close(fig)

df[cols].hist(bins=20, figsize=(8, 6), color="steelblue", edgecolor="white")
plt.suptitle("feature distributions")
plt.savefig("histograms.png", dpi=110, bbox_inches="tight")
plt.close("all")

# petal length/width pull the three species apart; sepal width barely separates anything
g = sns.pairplot(df, vars=cols, hue="species", diag_kind="hist", height=1.8)
g.figure.suptitle("iris pairplot by species", y=1.02)
g.savefig("pairplot.png", dpi=110, bbox_inches="tight")

print("\nsaved: corr_heatmap.png, histograms.png, pairplot.png")
