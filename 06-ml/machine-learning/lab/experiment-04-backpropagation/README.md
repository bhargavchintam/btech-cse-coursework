# Experiment 4 — Backpropagation

**Date:** 23/10/2020

## Aim
Train a feed-forward neural network with one hidden layer using the backpropagation algorithm, and have it learn the XOR function.

## Dataset
The four XOR patterns — `[0,0]→0, [0,1]→1, [1,0]→1, [1,1]→0`. XOR is not linearly separable, so it needs a hidden layer.

## Program
`backpropagation.py` — a 2-4-1 network with sigmoid activations, built in plain numpy. Each epoch does a forward pass, computes the output delta, backpropagates it through the second layer, and updates all weights and biases by gradient descent.

## Output
```
epoch     0   loss = 0.24973
epoch  1000   loss = 0.01722
epoch  2000   loss = 0.00277
epoch  3000   loss = 0.00137
epoch  4000   loss = 0.00089
epoch  5000   loss = 0.00066
epoch  6000   loss = 0.00052
epoch  7000   loss = 0.00042
epoch  8000   loss = 0.00036
epoch  9000   loss = 0.00031
epoch 10000   loss = 0.00027

final predictions:
  [0 0] -> 0.015  (rounded 0)
  [0 1] -> 0.981  (rounded 1)
  [1 0] -> 0.988  (rounded 1)
  [1 1] -> 0.020  (rounded 0)

all four XOR cases correct
```

## Result
The mean-squared error falls from 0.25 to about 0.0003 over 10000 epochs and all four XOR cases are classified correctly. The hidden layer supplies the non-linearity that a single perceptron lacks.
