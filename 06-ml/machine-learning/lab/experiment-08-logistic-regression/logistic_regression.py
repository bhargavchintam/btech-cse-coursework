# logistic regression on breast_cancer — accuracy, confusion matrix, report, ROC curve

import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import (accuracy_score, confusion_matrix,
                             classification_report, roc_curve, auc)

np.random.seed(1)

data = load_breast_cancer()
X, y = data.data, data.target
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=1, stratify=y)

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

clf = LogisticRegression(max_iter=5000, random_state=1).fit(X_train, y_train)
y_pred = clf.predict(X_test)
probs = clf.predict_proba(X_test)[:, 1]   # P(benign) drives the ROC sweep

print(f"test accuracy: {accuracy_score(y_test, y_pred):.4f}")

print("\nconfusion matrix (rows = true, cols = predicted):")
print(confusion_matrix(y_test, y_pred))

print("\nclassification report:")
print(classification_report(y_test, y_pred, target_names=data.target_names))

fpr, tpr, _ = roc_curve(y_test, probs)
roc_auc = auc(fpr, tpr)
print(f"ROC AUC: {roc_auc:.4f}")

plt.figure(figsize=(6, 5))
plt.plot(fpr, tpr, color="#c0392b", lw=2, label=f"ROC (AUC = {roc_auc:.3f})")
plt.plot([0, 1], [0, 1], "--", color="grey", lw=1, label="random")
plt.xlabel("false positive rate")
plt.ylabel("true positive rate")
plt.title("Breast cancer — ROC curve")
plt.legend(loc="lower right")
plt.grid(alpha=0.3)
plt.savefig("roc.png", dpi=110, bbox_inches="tight")
