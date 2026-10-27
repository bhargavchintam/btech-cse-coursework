# Dimensionality reduction

Real data has lots of columns and most of them are noise or repeats. Fewer, better features means faster
models, less overfitting, and plots you can actually see. Two ways to shrink the feature count:

- Feature SELECTION: keep a subset of the original columns, throw the rest away. Columns stay meaningful
  (StudyHours is still StudyHours). Info gain and chi-square below rank which ones to keep.
- Feature EXTRACTION: build NEW columns as combinations of the old ones. PCA does this — the principal
  components are mixes of all four iris measurements, so they're compact but no longer named things.

## Curse of dimensionality

As the number of dimensions d grows, the space blows up exponentially and the data gets sparse — points that
felt close in 2D are all roughly equidistant in 50D, so distance-based methods (KNN, k-means from the earlier
folders) stop meaning much. You'd need exponentially more rows to fill the space. So reducing d isn't just for
speed, it's to keep "nearest" actually near.

## PCA

Principal Component Analysis finds the directions in which the data varies the most and re-expresses the data
along them. Steps:

1. Mean-centre every column (subtract the column mean) so the cloud sits at the origin.
2. Covariance matrix C = (1/(n-1)) X^T X of the centred data — d x d, symmetric.
3. Eigen-decompose C: eigenvectors = the principal component DIRECTIONS, eigenvalues = the variance ALONG
   each one. `numpy.linalg.eig` gives both; sort them by eigenvalue descending.
4. Project: Z = X @ V, where V's columns are the top-k eigenvectors. Keep 2 columns -> a 2D view of 4D data.

Explained variance ratio = eigenvalue_i / sum(eigenvalues) — how much of the total spread each PC carries.
On iris_subset the eigenvalues are [3.270, 0.255, 0.036, 0.005], so PC1 alone explains 0.917 of the variance
and PC1+PC2 together 0.989. Four columns basically live on a 2D plane. My hand-rolled top ratio 0.9173
matches sklearn's PCA exactly (the projected PC2 can come out sign-flipped vs sklearn — eigenvectors are only
defined up to sign, that's fine).

> The eigenvector with the biggest eigenvalue is the axis the data is most stretched along. Reducing to k
> dims = keeping the top-k of those axes and dropping the flat ones.

Note PCA is unsupervised — it never looks at the label, it just chases variance. Scale matters: a column
measured in big units will dominate the covariance, so people often standardise first.

## Attribute subset selection

For picking among the ORIGINAL (categorical) columns, score each one against the target and keep the best.

Information gain — same entropy/info-gain as the decision tree in 06-classification:

    H(S) = - sum p_i log2(p_i)
    Gain(S, A) = H(S) - sum_v (|S_v|/|S|) H(S_v)

Rank the play_tennis attributes by gain and you get Outlook 0.247, Humidity 0.152, Wind 0.048,
Temperature 0.029 — Outlook is the most informative about PlayTennis, Temperature the least. So for selection
you'd keep Outlook and Humidity, drop Temperature. (Same reason ID3 splits on Outlook at the root.)

Chi-square test of independence — build the contingency table of the two categoricals, compare observed
counts O with the expected counts E you'd get if they were independent:

    E_ij = (row_i total * col_j total) / grand total
    chi2 = sum (O - E)^2 / E ,  dof = (rows-1)(cols-1)

Big chi2 (small p) means the attribute and the target are related, so the attribute is worth keeping. For
Outlook vs PlayTennis chi2 = 3.55 with dof = 2 (p = 0.17), matching scipy.stats.chi2_contingency. On only 14
rows p isn't tiny, so we can't call them significantly dependent here — small samples make chi-square shaky,
which is a real limitation of the test.

Info gain vs chi-square: both score one attribute against the target, info gain in bits of entropy removed,
chi-square as a deviation-from-independence statistic. They usually agree on the ranking.
