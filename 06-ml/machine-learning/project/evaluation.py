# final evaluation of the tuned SVM (params from tuning.py) on the held-out test set:
# confusion matrix, the full classification report, and the ROC curve with AUC.
# positive class = malignant, so recall here is "fraction of cancers we caught".

import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.metrics import (confusion_matrix, classification_report,
                             accuracy_score, roc_curve, auc)
from dataset import get_split, TARGET_NAMES

np.random.seed(1)

X_train, X_test, y_train, y_test = get_split()

clf = make_pipeline(StandardScaler(), SVC(kernel="rbf", C=100, gamma=0.001, random_state=1))
clf.fit(X_train, y_train)
y_pred = clf.predict(X_test)
y_score = clf.decision_function(X_test)

cm = confusion_matrix(y_test, y_pred)
tn, fp, fn, tp = cm.ravel()
print(f"test accuracy: {accuracy_score(y_test, y_pred):.4f}\n")
print("confusion matrix:")
print(cm)
print(f"TN={tn}  FP={fp}  FN={fn}  TP={tp}")
print(f"{fn} malignant case(s) missed, {fp} benign case(s) flagged as malignant\n")
print(classification_report(y_test, y_pred, target_names=TARGET_NAMES, digits=4))

sns.heatmap(cm, annot=True, fmt="d", cmap="Blues", cbar=False,
            xticklabels=TARGET_NAMES, yticklabels=TARGET_NAMES)
plt.xlabel("predicted")
plt.ylabel("actual")
plt.title("Confusion matrix — tuned SVM (test set)")
plt.savefig("confusion_matrix.png", dpi=110, bbox_inches="tight")
plt.close()

fpr, tpr, thr = roc_curve(y_test, y_score)
roc_auc = auc(fpr, tpr)
print(f"ROC AUC: {roc_auc:.4f}")

plt.figure(figsize=(6, 5.5))
plt.plot(fpr, tpr, color="#c0392b", lw=2, label=f"tuned SVM (AUC = {roc_auc:.3f})")
plt.plot([0, 1], [0, 1], color="gray", ls="--", lw=1, label="random (AUC = 0.5)")
plt.xlabel("false positive rate  (1 - specificity)")
plt.ylabel("true positive rate  (recall / sensitivity)")
plt.title("ROC curve — tuned SVM")
plt.legend(loc="lower right")
plt.grid(alpha=0.3)
plt.savefig("roc_curve.png", dpi=110, bbox_inches="tight")
plt.close()
