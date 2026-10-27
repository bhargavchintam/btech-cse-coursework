# Experiment 5 — Naive Bayes Classifier

**Date:** 06/11/2020

## Aim
Train a Gaussian Naive Bayes classifier and report its accuracy and confusion matrix.

## Dataset
The `wine` dataset built into scikit-learn — 178 samples, 13 chemical features, 3 cultivar classes. Split 70/30 with stratification so each class keeps its proportion in both halves.

## Program
`naive_bayes.py` — fits `GaussianNB` (each feature modelled as a per-class Gaussian, classes combined through Bayes' rule), then prints accuracy, the confusion matrix, and a per-class precision/recall report.

## Output
```
classes: ['class_0', 'class_1', 'class_2']
class priors: [0.331 0.403 0.266]

test accuracy: 0.9815

confusion matrix (rows = true, cols = predicted):
[[17  1  0]
 [ 0 21  0]
 [ 0  0 15]]

classification report:
              precision    recall  f1-score   support

     class_0       1.00      0.94      0.97        18
     class_1       0.95      1.00      0.98        21
     class_2       1.00      1.00      1.00        15

    accuracy                           0.98        54
   macro avg       0.98      0.98      0.98        54
weighted avg       0.98      0.98      0.98        54
```

## Result
Gaussian Naive Bayes reaches 98.15% test accuracy; the confusion matrix shows a single class_0 sample misread as class_1, everything else correct.
