# The same idea at scale: sklearn's MLPClassifier on the digits data (10-class, 64 pixels).
# This is the tool you'd actually reach for once the mechanics from mlp_scratch.py are clear.

import numpy as np
from sklearn.datasets import load_digits
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score, confusion_matrix

np.random.seed(1)

X, y = load_digits(return_X_y=True)
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=1, stratify=y)

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

clf = MLPClassifier(hidden_layer_sizes=(64, 32), activation="relu",
                    solver="adam", max_iter=400, random_state=1)
clf.fit(X_train, y_train)

acc = accuracy_score(y_test, clf.predict(X_test))
print(f"digits test acc: {acc:.4f}")
print(f"layers: 64 -> 64 -> 32 -> 10   ({clf.n_iter_} iters to converge)")

cm = confusion_matrix(y_test, clf.predict(X_test))
true, pred = np.unravel_index(np.argmax(cm - np.diag(np.diag(cm))), cm.shape)
print(f"most-confused pair: a {true} misread as a {pred}")
