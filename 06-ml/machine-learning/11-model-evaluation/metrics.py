# confusion matrix + precision/recall/F1 + ROC-AUC for a logistic model on breast_cancer.
# positive class = malignant (0 in sklearn's coding), the one we actually care about catching.

import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import (confusion_matrix, classification_report,
                             precision_score, recall_score, f1_score,
                             accuracy_score, roc_curve, auc)

np.random.seed(1)

data = load_breast_cancer()
X, y = data.data, data.target
# flip the labels so malignant=1 is the positive class — "did we catch the cancer?"
y = 1 - y

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25, random_state=1, stratify=y)

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

clf = LogisticRegression(max_iter=5000, random_state=1)
clf.fit(X_train, y_train)
y_pred = clf.predict(X_test)
y_score = clf.predict_proba(X_test)[:, 1]

cm = confusion_matrix(y_test, y_pred)
tn, fp, fn, tp = cm.ravel()
print("confusion matrix:")
print(cm)
print(f"TN={tn}  FP={fp}  FN={fn}  TP={tp}\n")

# precision/recall straight from the four counts — this is all the report is doing underneath
prec_hand = tp / (tp + fp)
rec_hand = tp / (tp + fn)
f1_hand = 2 * prec_hand * rec_hand / (prec_hand + rec_hand)
print(f"by hand   precision={prec_hand:.4f}  recall={rec_hand:.4f}  f1={f1_hand:.4f}")
print(f"sklearn   precision={precision_score(y_test, y_pred):.4f} "
      f" recall={recall_score(y_test, y_pred):.4f} "
      f" f1={f1_score(y_test, y_pred):.4f}")

assert np.isclose(prec_hand, precision_score(y_test, y_pred))
assert np.isclose(rec_hand, recall_score(y_test, y_pred))
assert np.isclose(f1_hand, f1_score(y_test, y_pred))

print(f"\naccuracy: {accuracy_score(y_test, y_pred):.4f}\n")
print(classification_report(y_test, y_pred, target_names=["benign", "malignant"]))

sns.heatmap(cm, annot=True, fmt="d", cmap="Blues", cbar=False,
            xticklabels=["benign", "malignant"],
            yticklabels=["benign", "malignant"])
plt.xlabel("predicted")
plt.ylabel("actual")
plt.title("Confusion matrix — logistic regression on breast cancer")
plt.savefig("confusion_matrix.png", dpi=110, bbox_inches="tight")
plt.close()

fpr, tpr, thr = roc_curve(y_test, y_score)
roc_auc = auc(fpr, tpr)
print(f"\nROC AUC: {roc_auc:.4f}")

plt.figure(figsize=(6, 5.5))
plt.plot(fpr, tpr, color="#c0392b", lw=2, label=f"logistic (AUC = {roc_auc:.3f})")
plt.plot([0, 1], [0, 1], color="gray", ls="--", lw=1, label="random (AUC = 0.5)")
plt.xlabel("false positive rate  (1 - specificity)")
plt.ylabel("true positive rate  (recall)")
plt.title("ROC curve")
plt.legend(loc="lower right")
plt.grid(alpha=0.3)
plt.savefig("roc_curve.png", dpi=110, bbox_inches="tight")
plt.close()
