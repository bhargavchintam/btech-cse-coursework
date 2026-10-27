# gaussian naive bayes from scratch on iris, checked against sklearn's GaussianNB

import numpy as np
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score

np.random.seed(1)

X, y = load_iris(return_X_y=True)
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=1, stratify=y)

classes = np.unique(y_train)
priors, means, variances = {}, {}, {}
for c in classes:
    Xc = X_train[y_train == c]
    priors[c] = len(Xc) / len(X_train)
    means[c] = Xc.mean(axis=0)
    variances[c] = Xc.var(axis=0) + 1e-9   # a floor on the variance, like sklearn's var_smoothing


def log_gaussian(x, mean, var):
    return -0.5 * np.log(2 * np.pi * var) - (x - mean) ** 2 / (2 * var)


def predict(X):
    out = []
    for x in X:
        # everything in log-space: log P(c) + sum_j log P(x_j | c), then take the biggest
        scores = [np.log(priors[c]) + log_gaussian(x, means[c], variances[c]).sum()
                  for c in classes]
        out.append(classes[int(np.argmax(scores))])
    return np.array(out)


acc_scratch = accuracy_score(y_test, predict(X_test))

gnb = GaussianNB().fit(X_train, y_train)
acc_sklearn = accuracy_score(y_test, gnb.predict(X_test))

print(f"scratch GaussianNB acc: {acc_scratch:.4f}")
print(f"sklearn GaussianNB acc: {acc_sklearn:.4f}")
assert np.isclose(acc_scratch, acc_sklearn), "scratch NB disagrees with sklearn"
