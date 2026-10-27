# Regression

Classification predicts a class label (Yes/No, setosa/versicolor). Regression predicts a NUMBER — marks,
price, temperature. Same supervised setup (rows have a known answer), the difference is the target is
continuous, so we can't count "how many right", we measure how FAR off we are.

Data here is students.csv: StudyHours vs Marks is an almost-straight line, which makes it a good first
example. A few rows have blanks, so drop the ones missing StudyHours or Marks before fitting.

## Simple linear regression

One feature x, one target y, fit a line y = a + b*x. Least squares picks a and b that minimise the sum of
squared residuals sum (y_i - (a + b*x_i))^2. Setting the derivatives to zero gives the closed form:

    b = sum (x_i - xbar)(y_i - ybar) / sum (x_i - xbar)^2
    a = ybar - b * xbar

On StudyHours -> Marks this comes out b = 10.40, a = 34.00, so Marks ~= 34 + 10.4 * StudyHours. One extra
hour of study is worth about 10 marks. Predicting StudyHours=4 gives ~75.6.

## Normal equations (multiple regression)

More than one feature, write it as a matrix. X has a column of 1s (for the intercept) then the features, y
is the column of targets. The least-squares solution in one shot:

    theta = (X^T X)^-1 X^T y

This is the normal equation — same minimisation, just linear algebra instead of the two scalar formulas.
On StudyHours + Attendance -> Marks the coefficients are intercept -6.92, StudyHours 4.30, Attendance 0.79,
and the fit R2 is 0.991. (X^T X)^-1 only exists if the features aren't collinear, else use the pseudo-inverse.

## Gradient descent

When X^T X is huge or singular, don't invert — walk downhill. Start w, b at 0, and repeatedly step against
the gradient of the MSE:

    dw = (2/n) sum (pred - y) * x
    db = (2/n) sum (pred - y)
    w = w - lr * dw ,  b = b - lr * db

lr too big and it diverges, too small and it crawls. On the students data lr=0.02 for 20000 steps lands on
w = 10.395, b = 33.996 — the SAME as the closed form, which is the whole point: gradient descent is just
another route to the least-squares answer. (Un-centered x is badly conditioned so it needs a fair few steps.)

> Closed form is exact but O(d^3) to invert; gradient descent scales to big d and big n. That trade-off is
> why real libraries use iterative solvers.

## Logistic regression

Despite the name it's a CLASSIFIER. Instead of a line we squash w.x + b through the sigmoid to get a
probability in (0,1):

    sigmoid(z) = 1 / (1 + e^-z)

Predict class 1 if the probability >= 0.5. We don't minimise squared error here (non-convex for this), we
minimise log loss (cross-entropy):

    L = -(1/n) sum [ y*log(p) + (1-y)*log(1-p) ]

Its gradient is beautifully simple, same shape as linear regression: (1/n) X^T (p - y). Train with gradient
descent. On iris_subset (setosa vs versicolor, standardised features) it separates them perfectly — accuracy
1.0, log loss ~0.001 — because the two species don't overlap. Standardising first keeps the sigmoid from
saturating so gd converges fast.

## Evaluation

Residual = actual - predicted. The usual error numbers:

    MSE  = (1/n) sum (y - pred)^2          squared, punishes big misses hard
    RMSE = sqrt(MSE)                        back in the original units (marks)
    MAE  = (1/n) sum |y - pred|            plain average miss, robust to outliers
    R2   = 1 - SS_res / SS_tot             fraction of variance the model explains

where SS_res = sum (y - pred)^2 and SS_tot = sum (y - ybar)^2. R2 = 1 is perfect, R2 = 0 is no better than
just predicting the mean, and it can go negative if the model is worse than the mean line. On a small
made-up prediction set my from-scratch MSE/RMSE/MAE/R2 (5.70 / 2.39 / 2.30 / 0.982) match sklearn.metrics
to 4 decimals, so the formulas are right.

MSE vs MAE: squaring in MSE means one big outlier dominates, MAE treats all misses linearly. Report RMSE when
you want the error in real units, R2 when you want a "how good, roughly" score between 0 and 1.
