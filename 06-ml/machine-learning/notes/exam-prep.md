# Exam prep — questions that keep coming up

Grouped by unit. Marks in brackets. A few tagged with where they showed up.

## Unit 1 — Introduction

1. Define machine learning. Give Mitchell's T/P/E definition with an example. (5 marks)
2. Differentiate supervised, unsupervised and reinforcement learning with examples. (10 marks) *(asked in IA1)*
3. Difference between classification and regression. (5 marks)
4. Draw and explain the machine learning pipeline. (10 marks)
5. What is overfitting? What is underfitting? How do you prevent overfitting? (10 marks) *(2019 paper)*
6. Explain the bias–variance tradeoff. Show the U-shaped error curve. (10 marks)
7. Why split data into train / validation / test? Why must the test set be touched only once? (5 marks)
8. Parametric vs non-parametric models — compare with examples. (5 marks)

## Unit 2 — Data preprocessing

9. Why does data need preprocessing before modelling? List the main steps. (5 marks)
10. Ways to handle missing values — deletion vs imputation, when each. (10 marks)
11. Label encoding vs one-hot encoding. When does label encoding mislead a model? (10 marks) *(asked in IA1)*
12. Standardisation vs normalisation (min-max). Give both formulas. (5 marks)
13. What is data leakage? How does fitting the scaler on the full data cause it? (5 marks)
14. What is EDA? What do you look for, and how do you detect outliers? (5 marks)

## Unit 3 — Linear regression

15. Derive the cost function (MSE) for linear regression. (5 marks)
16. Explain gradient descent. Write the update rule and the role of the learning rate. (10 marks) *(2019 paper)*
17. Batch vs stochastic vs mini-batch gradient descent. (5 marks)
18. Derive the normal equation θ = (XᵀX)⁻¹Xᵀy. When is it preferred over gradient descent? (10 marks)
19. What does R² measure? What do R²=1, 0, negative mean? (5 marks)
20. What is regularization? Compare Ridge (L2) and Lasso (L1). Which gives sparse weights and why? (10 marks) *(asked in IA2)*
21. What problem does a too-large / too-small learning rate cause? (5 marks)

## Unit 4 — Logistic regression

22. Why not use linear regression for classification? (5 marks)
23. Write the sigmoid function and sketch it. State its range and derivative. (5 marks)
24. Derive the cross-entropy (log) loss. Why not use MSE for logistic regression? (10 marks)
25. What is the decision boundary? Show it is linear in the features. (5 marks)
26. How is logistic regression extended to multiclass (softmax / one-vs-rest)? (5 marks)

## Unit 5 — KNN and Naive Bayes

27. Explain the KNN algorithm. How do you choose k? (10 marks)
28. Why must features be scaled for KNN but not for a decision tree? (5 marks) *(asked in IA1)*
29. Effect of k: what happens at k=1 vs very large k on bias/variance? (5 marks)
30. State Bayes' theorem and derive the Naive Bayes classifier. (10 marks)
31. What is the "naive" independence assumption? Why does NB work despite it being wrong? (5 marks)
32. What is Laplace (additive) smoothing and why is it needed? (5 marks)

## Unit 6 — Decision trees and ensembles

33. Explain the ID3 algorithm. Define entropy and information gain with formulas. (10 marks) *(2019 paper)*
34. Entropy vs Gini impurity — write both, state when they differ. (5 marks)
35. Work an information-gain calculation for one split. (10 marks)
36. How do decision trees overfit? How does pruning / max_depth help? (5 marks)
37. What is ensemble learning? Explain bagging. (5 marks)
38. Difference between bagging and boosting. (10 marks) *(asked in IA2)*
39. Explain Random Forest. How does it de-correlate the trees? (10 marks)

## Unit 7 — Support vector machines

40. What is the margin? Why maximise it? (5 marks)
41. Explain SVM as a constrained optimisation. What are support vectors? (10 marks)
42. What is the kernel trick? Why does it avoid explicit high-dimensional mapping? (10 marks) *(asked in IA2)*
43. Compare linear, polynomial and RBF kernels. When use each? (5 marks)
44. Role of C and gamma in an RBF SVM (bias/variance effect). (5 marks)

## Unit 8 — Clustering

45. Explain the k-means algorithm step by step. (10 marks) *(2019 paper)*
46. How do you choose k? Explain the elbow method and the silhouette score. (10 marks)
47. Limitations of k-means (shape, size, k, initialisation). What does k-means++ fix? (5 marks)
48. Explain agglomerative hierarchical clustering and the dendrogram. (10 marks)
49. Explain DBSCAN. What are core, border and noise points? When does it beat k-means? (10 marks)
50. Difference between k-means and hierarchical clustering. (5 marks)

## Unit 9 — Dimensionality reduction

51. What is the curse of dimensionality? (5 marks) *(asked in IA2)*
52. Explain PCA step by step. What do the principal components represent? (10 marks)
53. Role of eigenvalues and eigenvectors in PCA. How is explained variance computed? (10 marks)
54. Why standardise data before PCA? (5 marks)
55. PCA vs t-SNE — what is each good for? (5 marks)

## Unit 10 — Neural networks

56. Explain the perceptron. What can a single perceptron not learn (XOR)? (10 marks)
57. Why do we need activation functions? What if they were all linear? (5 marks)
58. Compare sigmoid, tanh and ReLU. State ranges and the vanishing-gradient issue. (10 marks) *(asked in IA2)*
59. Explain forward propagation and backpropagation. (10 marks)
60. Why is ReLU the default hidden-layer activation? What is dying ReLU? (5 marks)

## Unit 11 — Model evaluation

61. Draw a confusion matrix. Define TP, FP, FN, TN. (5 marks)
62. Define precision, recall, specificity and F1 with formulas. (10 marks) *(2019 paper)*
63. Precision vs recall — give a scenario where each is the priority. (10 marks) *(asked in IA1)*
64. Why is accuracy misleading on imbalanced data? Give the 99% example. (5 marks)
65. What is a ROC curve and AUC? What does the diagonal mean? (10 marks)
66. Explain k-fold cross-validation. Why is it better than a single split? (10 marks)
