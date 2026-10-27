# t-SNE 2D embedding of the digits, coloured by digit
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import load_digits
from sklearn.decomposition import PCA
from sklearn.manifold import TSNE

np.random.seed(1)

X, y = load_digits(return_X_y=True)

# PCA down to 30 dims first — the standard t-SNE recipe: denoises and speeds the run up
X30 = PCA(n_components=30, random_state=1).fit_transform(X)

ts = TSNE(n_components=2, perplexity=30, init="pca", random_state=1)
Z = ts.fit_transform(X30)
print(f"embedded {X.shape[0]} digits from {X.shape[1]}-D to 2-D")
print(f"final KL divergence: {ts.kl_divergence_:.3f}")

fig, ax = plt.subplots(figsize=(8, 7))
sc = ax.scatter(Z[:, 0], Z[:, 1], c=y, cmap="tab10", s=14, alpha=0.85)
ax.set_title("t-SNE of the digits — ten clusters emerge, no labels used to place them")
ax.set_xlabel("t-SNE 1")
ax.set_ylabel("t-SNE 2")
cbar = fig.colorbar(sc, ax=ax, ticks=range(10))
cbar.set_label("digit")
plt.savefig("tsne_digits.png", dpi=110, bbox_inches="tight")
