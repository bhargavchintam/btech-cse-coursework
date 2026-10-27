# Experiment 6 — k-Nearest Neighbours Classifier

**Date:** 13/11/2020

## Aim
Classify iris flowers with k-NN, list the misclassified test points, and sweep k to find the best value.

## Dataset
The `iris` dataset built into scikit-learn — 150 samples, 4 features, 3 species. Split 70/30 with stratification; features standardised (k-NN measures distances, so the columns must be on the same scale).

## Program
`knn.py` — fits `KNeighborsClassifier` at k=5, prints accuracy and the true/predicted label of every misclassified test flower, then loops k from 1 to 20 and reports the best.

## Output
```
k=5 test accuracy: 0.9333  (42/45 correct)

misclassified test points:
  index   3: true = virginica   predicted = versicolor
  index   7: true = versicolor  predicted = virginica
  index  42: true = versicolor  predicted = virginica

 k : accuracy
 1 : 0.9333
 2 : 0.9333
 3 : 0.9556
 4 : 0.9556
 5 : 0.9333
 6 : 0.9556
 7 : 0.9556
 8 : 0.9333
 9 : 0.9556
10 : 0.9333
11 : 0.9556
12 : 0.9333
13 : 0.9556
14 : 0.9556
15 : 0.9333
16 : 0.9333
17 : 0.9111
18 : 0.9333
19 : 0.9556
20 : 0.9333

best k = 3  (accuracy 0.9556)
```

## Result
k=5 gives 93.33% accuracy with only 3 of 45 test points wrong, all on the versicolor/virginica boundary where the two species overlap. Sweeping k, the best score is 95.56% at k=3.
