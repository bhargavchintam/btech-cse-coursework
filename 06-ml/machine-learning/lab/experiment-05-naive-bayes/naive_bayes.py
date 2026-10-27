# gaussian naive bayes on the wine dataset — accuracy, confusion matrix, per-class report

import numpy as np
from sklearn.datasets import load_wine
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report

np.random.seed(1)

data = load_wine()
X, y = data.data, data.target
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=1, stratify=y)

gnb = GaussianNB().fit(X_train, y_train)
y_pred = gnb.predict(X_test)

print("classes:", data.target_names.tolist())
print("class priors:", np.round(gnb.class_prior_, 3))
print(f"\ntest accuracy: {accuracy_score(y_test, y_pred):.4f}")

print("\nconfusion matrix (rows = true, cols = predicted):")
print(confusion_matrix(y_test, y_pred))

print("\nclassification report:")
print(classification_report(y_test, y_pred, target_names=data.target_names))
