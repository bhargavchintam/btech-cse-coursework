# full evaluation of a classifier on breast_cancer:
# cross-validation, confusion matrix, precision/recall/F1, ROC-AUC
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split, cross_val_score, StratifiedKFold
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import (confusion_matrix, classification_report,
                             roc_curve, auc, accuracy_score)

np.random.seed(1)

data = load_breast_cancer()
X, y = data.data, data.target
y = 1 - y   # malignant = 1 so it counts as the positive class we want to catch

pipe = make_pipeline(StandardScaler(), LogisticRegression(max_iter=5000, random_state=1))

cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=1)
scores = cross_val_score(pipe, X, y, cv=cv, scoring="accuracy")
print(f"5-fold CV accuracy: {np.round(scores, 3)}")
print(f"                    {scores.mean():.4f} +/- {scores.std():.4f}\n")

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25, random_state=1, stratify=y)
pipe.fit(X_train, y_train)
y_pred = pipe.predict(X_test)
y_score = pipe.predict_proba(X_test)[:, 1]

cm = confusion_matrix(y_test, y_pred)
print("confusion matrix:")
print(cm)
print(f"\nhold-out accuracy: {accuracy_score(y_test, y_pred):.4f}\n")
print(classification_report(y_test, y_pred, target_names=["benign", "malignant"]))

fpr, tpr, _ = roc_curve(y_test, y_score)
roc_auc = auc(fpr, tpr)
print(f"ROC AUC: {roc_auc:.4f}")

fig, ax = plt.subplots(1, 2, figsize=(12, 5))
sns.heatmap(cm, annot=True, fmt="d", cmap="Blues", cbar=False, ax=ax[0],
            xticklabels=["benign", "malignant"],
            yticklabels=["benign", "malignant"])
ax[0].set_xlabel("predicted")
ax[0].set_ylabel("actual")
ax[0].set_title("confusion matrix")

ax[1].plot(fpr, tpr, color="#c0392b", lw=2, label=f"logistic (AUC = {roc_auc:.3f})")
ax[1].plot([0, 1], [0, 1], color="gray", ls="--", lw=1, label="random")
ax[1].set_xlabel("false positive rate")
ax[1].set_ylabel("true positive rate")
ax[1].set_title("ROC curve")
ax[1].legend(loc="lower right")
ax[1].grid(alpha=0.3)
plt.savefig("evaluation.png", dpi=110, bbox_inches="tight")
