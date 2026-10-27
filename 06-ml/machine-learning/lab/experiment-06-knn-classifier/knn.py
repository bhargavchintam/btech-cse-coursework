# k-nearest neighbours on iris: accuracy, the misclassified test points, and a sweep over k

import numpy as np
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score

np.random.seed(1)

iris = load_iris()
X, y = iris.data, iris.target
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=1, stratify=y)

scaler = StandardScaler().fit(X_train)
X_train = scaler.transform(X_train)
X_test = scaler.transform(X_test)   # knn is distance-based, so scale first

clf = KNeighborsClassifier(n_neighbors=5).fit(X_train, y_train)
y_pred = clf.predict(X_test)
correct = int((y_pred == y_test).sum())
print(f"k=5 test accuracy: {accuracy_score(y_test, y_pred):.4f}  ({correct}/{len(y_test)} correct)")

wrong = np.where(y_pred != y_test)[0]
if len(wrong):
    print("\nmisclassified test points:")
    for i in wrong:
        print(f"  index {i:3d}: true = {iris.target_names[y_test[i]]:<11} predicted = {iris.target_names[y_pred[i]]}")
else:
    print("\nno misclassified test points")

print("\n k : accuracy")
best_k, best_acc = 1, 0.0
for k in range(1, 21):
    a = accuracy_score(y_test, KNeighborsClassifier(n_neighbors=k).fit(X_train, y_train).predict(X_test))
    print(f"{k:2d} : {a:.4f}")
    if a > best_acc:
        best_k, best_acc = k, a
print(f"\nbest k = {best_k}  (accuracy {best_acc:.4f})")
