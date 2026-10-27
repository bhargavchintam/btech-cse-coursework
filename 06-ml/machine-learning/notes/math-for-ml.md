# Math for ML — the refresher

The math this course actually leans on, kept simple, with tiny examples you can check by hand.
Three topics: linear algebra, calculus, probability. Every number here is verified.

## Linear algebra

### Vectors

A vector is an ordered list of numbers — one instance's features, a set of weights, a direction
in space. Write it **x** = [x₁, …, xₙ]; geometrically it is an arrow from the origin. Its
**length** (L2 norm) is √(x₁² + … + xₙ²) — for [3, 4] that is √(9+16) = √25 = 5.

### Dot product

The dot product multiplies two vectors element-wise and sums:

```
a · b = Σ aᵢbᵢ = a₁b₁ + a₂b₂ + … + aₙbₙ
```

Example: a = [1, 2, 3], b = [4, 5, 6].

```
a · b = 1·4 + 2·5 + 3·6 = 4 + 10 + 18 = 32
```

It is everywhere: a linear model's prediction is just **w · x + b**, one dot product. It also
measures alignment (`|a||b|cosθ`) — 0 when the vectors are perpendicular, positive when they
point the same way, negative when opposite.

### Matrix multiplication

A matrix is a grid of numbers, shape (rows, cols). To multiply A (m×n) by B (n×p) you take the
dot product of each **row of A** with each **column of B**. The result is (m×p). The inner
dimensions must match.

Example, both 2×2:

```
A = [1 2]      B = [5 6]
    [3 4]          [7 8]

AB = [1·5+2·7   1·6+2·8]  = [19 22]
     [3·5+4·7   3·6+4·8]    [43 50]
```

Every entry is one row·column dot product. A whole batch of predictions is one matrix multiply
**X W**, features times weights. Order matters: AB ≠ BA in general.

### Transpose

The transpose Aᵀ flips rows and columns — entry (i, j) becomes (j, i).

```
A = [1 2]      Aᵀ = [1 3]
    [3 4]           [2 4]
```

A (2×3) transposes to (3×2). You meet it in the normal equation θ = (XᵀX)⁻¹Xᵀy and in every
gradient written **Xᵀ(ŷ − y)**.

### Inverse

The inverse A⁻¹ is the matrix that undoes A: A A⁻¹ = I, the identity (1s on the diagonal, 0s
elsewhere). It is the matrix version of dividing. Only square, non-singular (det ≠ 0) matrices
have one.

For a 2×2, A = [[a, b], [c, d]], the inverse is (1/det)·[[d, −b], [−c, a]] where det = ad − bc.

Example, A = [[4, 7], [2, 6]]: det = 4·6 − 7·2 = 24 − 14 = 10.

```
A⁻¹ = (1/10) [ 6  −7]  = [ 0.6  −0.7]
             [−2   4]    [−0.2   0.4]
```

Check: A A⁻¹ = I (verified). The normal equation needs (XᵀX)⁻¹ — this is why an (almost)
singular XᵀX, from collinear features, makes linear regression blow up, and why Ridge adds λI to
make it invertible again.

### Eigenvalues and eigenvectors

For a square matrix A, an **eigenvector** v is a special direction that A only **stretches**, it
does not rotate it:

```
A v = λ v
```

The scalar λ is the **eigenvalue** — the stretch factor. Most vectors get knocked off their line
when you apply A; eigenvectors stay on their own line, only lengthening, shrinking, or flipping
(λ < 0).

Example: A = [[2, 1], [1, 2]] has eigenvalues **3 and 1**. Its λ=3 eigenvector is [1, 1] (the
45° line) — A stretches anything along it by 3×; the λ=1 eigenvector [1, −1] is left unchanged.

**PCA** is exactly this. Eigen-decompose the data's covariance matrix: the eigenvectors are the
directions the cloud spreads along (the principal components), each eigenvalue is how much
variance lies along it. Keep the few biggest-λ eigenvectors and you keep most of the spread while
dropping dimensions. Big λ = important direction.

## Calculus

### Derivative — the slope

The derivative f′(x) is the slope of f at x: how fast the output changes as you nudge the input.
Positive slope, rising; negative, falling; zero, a flat spot (min, max, or saddle). Training a
model = finding where the slope of the loss is zero. Rules you use constantly: d/dx[xⁿ] = n·xⁿ⁻¹,
d/dx[eˣ] = eˣ, and the derivative of a sum is the sum of derivatives.

### Partial derivative

When a function has several inputs, the **partial derivative** ∂f/∂x is the slope in the x
direction with the others held fixed. A loss depends on many weights; the partial w.r.t. one
weight says how the loss moves if you tweak just that weight.

Example: f(x, y) = x² + 3xy + y².

```
∂f/∂x = 2x + 3y        (treat y as a constant)
∂f/∂y = 3x + 2y        (treat x as a constant)
```

### The gradient

The **gradient** ∇f is the vector of all the partial derivatives:

```
∇f = [ ∂f/∂x ,  ∂f/∂y ,  … ]
```

It points in the direction of **steepest ascent** — the uphill direction of the function. For
the f above, at the point (1, 2):

```
∇f = [2x + 3y, 3x + 2y] = [2·1 + 3·2, 3·1 + 2·2] = [8, 7]
```

To *minimise* a loss you step the opposite way, downhill: **−∇f**. That is the whole idea of
gradient descent.

### Gradient descent

Repeatedly step downhill by a small amount:

```
θ := θ − α ∇J(θ)
```

θ are the parameters, J the cost, ∇J its gradient, α the **learning rate** (step size). Small α
crawls; too-large α overshoots and diverges.

One step by hand on J(θ) = θ², whose gradient is 2θ. Start θ = 3, α = 0.1:

```
θ := 3 − 0.1 · (2·3) = 3 − 0.6 = 2.4
```

Next step moves toward 0, the minimum — exactly where the slope is zero. Every model in this
course that "trains" (linear/logistic regression, neural nets) is running this loop.

### The chain rule

To differentiate a function of a function, multiply the derivatives of each layer:

```
d/dx f(g(x)) = f′(g(x)) · g′(x)
```

Example: y = (3x + 1)². Let g = 3x + 1, so y = g². Then dy/dg = 2g and dg/dx = 3, so

```
dy/dx = 2(3x + 1) · 3 = 6(3x + 1)
```

At x = 1 that is 6·4 = 24.

The chain rule **is** backpropagation. A neural net is functions nested inside functions (layer
after layer); backprop applies the chain rule from the loss backward through every layer to get
∂loss/∂weight for each weight, then gradient descent uses those to update.

## Probability

### Random variable, mean, variance

A **random variable** X is a quantity whose value depends on chance (a dice roll, a
measurement). Its **mean** (expected value) μ is the long-run average; its **variance** σ² is
the average squared distance from the mean — the spread. The **standard deviation** σ = √σ² is
back in the original units.

```
μ  = (1/n) Σ xᵢ
σ² = (1/n) Σ (xᵢ − μ)²
```

Example: data = [2, 4, 4, 4, 5, 5, 7, 9].

```
μ  = (2+4+4+4+5+5+7+9) / 8 = 40 / 8 = 5
σ² = [(2−5)² + (4−5)²·3 + (5−5)²·2 + (7−5)² + (9−5)²] / 8
   = [9 + 3 + 0 + 4 + 16] / 8 = 32 / 8 = 4
σ  = √4 = 2
```

Feature scaling (standardisation) uses exactly these: z = (x − μ) / σ turns any feature into
mean 0, variance 1.

### Bayes' theorem

Bayes flips a conditional probability — it turns P(evidence | cause) into P(cause | evidence):

```
P(A | B) = P(B | A) · P(A) / P(B)
```

P(A) is the **prior** (belief before evidence), P(B | A) the **likelihood**, P(A | B) the
**posterior** (updated belief). This is the engine of the Naive Bayes classifier.

Worked example — the classic disease test. A disease affects 1% of people. A test catches 99%
of sick people (sensitivity) but also flags 5% of healthy people (false positive rate). You test
positive. What is the chance you actually have it?

```
P(D) = 0.01        P(+|D) = 0.99        P(+|not D) = 0.05

P(+) = P(+|D)P(D) + P(+|not D)P(not D)
     = 0.99·0.01 + 0.05·0.99
     = 0.0099 + 0.0495 = 0.0594

P(D|+) = P(+|D)P(D) / P(+) = 0.0099 / 0.0594 = 0.1667
```

So about **17%**, not 99%. The disease is rare, so even a good test throws up far more false
positives than true ones. This base-rate effect is the single most counter-intuitive result in
the whole subject — worth remembering.

### The Gaussian (normal) distribution

The bell curve. A continuous random variable with mean μ and standard deviation σ has density:

```
f(x) = 1 / (σ√(2π)) · exp( −(x − μ)² / (2σ²) )
```

Symmetric, peaked at μ, width set by σ. About 68% of the mass lies within 1σ of the mean, 95%
within 2σ, 99.7% within 3σ (the 68–95–99.7 rule); at μ=0, σ=1 the peak height is 1/√(2π) ≈ 0.399.

It is everywhere because of the **central limit theorem**: sums and averages of many small
independent effects tend to a Gaussian whatever the pieces looked like — which is why
measurement noise, heights, and errors are so often bell-shaped, and why Gaussian Naive Bayes
models each feature as a normal distribution per class.
