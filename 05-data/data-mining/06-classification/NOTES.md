# Classification

Classification is supervised: every training row already has a class label and we learn a model that
labels new rows. Clustering (next folder) is unsupervised — no labels, we group by similarity and hope the
groups mean something. So the big difference is the label: classification predicts a known class, clustering
discovers structure.

Datasets used here: play_tennis.csv (14 rows, all categorical, target PlayTennis) and iris_subset.csv
(setosa + versicolor, 4 numeric features). The play_tennis one is nice because the answer is known from the
textbook, so I can check my code against it.

## Decision trees

Greedily pick the attribute that best separates the classes, split on it, recurse on each branch. Stop when a
node is pure (one class) or there are no attributes left (then take the majority).

Entropy of a set S with class probabilities p_i:

    H(S) = - sum p_i * log2(p_i)

Pure set -> H = 0, 50/50 split -> H = 1. For play_tennis the whole set is 9 Yes / 5 No so H = 0.940.

Information gain of splitting S on attribute A:

    Gain(S, A) = H(S) - sum_v (|S_v| / |S|) * H(S_v)

ID3 picks the attribute with the highest gain. On play_tennis the gains at the root are:

    Outlook      0.247
    Humidity     0.152
    Wind         0.048
    Temperature  0.029

so the root split is Outlook. (Got asked this in the internal — the root is Outlook, not Humidity.)

Gini index is the other impurity measure, used by CART:

    Gini(S) = 1 - sum p_i^2

Instead of maximising gain we minimise the weighted gini of the split. Same idea, different number. On
play_tennis Outlook also gives the lowest weighted gini (~0.343) so the root comes out the same.

ID3 vs CART:
- ID3: entropy + info gain, multiway splits (one branch per value), categorical attributes.
- CART: gini, strictly binary splits, handles numeric attributes too, and it's what sklearn uses.

> A pure node is a leaf — you stop there, there's nothing left to gain.

## Naive Bayes

Bayes rule:  P(c | x) = P(x | c) * P(c) / P(x).  The P(x) is the same for every class so we drop it and just
compare P(c) * P(x | c) across classes, pick the biggest.

"Naive" = we assume the features are conditionally independent given the class, so

    P(x | c) = prod_i P(x_i | c)

which is wrong in general but works surprisingly well. Problem: if a value never appears with a class the
product goes to zero. Fix with Laplace (add-one) smoothing:

    P(x_i | c) = (count(x_i, c) + 1) / (count(c) + k_i)

where k_i is the number of distinct values of attribute i. For the test day
{Sunny, Cool, High, Strong} the normalized posteriors come out No ~0.72, Yes ~0.28, so the prediction is No.

## KNN

Lazy learner — no training, it just stores the data. To classify a point, find the k nearest training points
and take the majority vote. Distance here is euclidean:

    d(a, b) = sqrt( sum_i (a_i - b_i)^2 )

Choice of k matters: k too small is noisy (overfits), k too big smooths over the real classes. Odd k avoids
ties in 2-class problems. Features should be on the same scale first, else the big-range feature dominates the
distance (the min-max scaling from 02-preprocessing). On iris_subset a clearly-setosa point like
[5.0, 3.4, 1.5, 0.2] comes back setosa, as it should.

## Evaluation

Confusion matrix (2-class), rows = actual, cols = predicted:

    |            pred Yes   pred No
    | actual Yes    TP        FN
    | actual No     FP        TN

From those four counts:

    accuracy  = (TP + TN) / all
    precision = TP / (TP + FP)      how many predicted-positive were right
    recall    = TP / (TP + FN)      how many actual-positive we caught
    F1        = 2 * P * R / (P + R) harmonic mean of the two

Accuracy alone lies on imbalanced data (predict the majority everywhere and it still looks good), so precision
/ recall / F1 matter.

k-fold cross validation: split the data into k folds, train on k-1 and test on the held-out one, rotate so
every fold is the test set once, average the k accuracies. Uses the data better than a single train/test split
and the mean is a steadier estimate. Here 5-fold KNN on the (easy, separable) iris subset gives mean accuracy
around 1.0.
