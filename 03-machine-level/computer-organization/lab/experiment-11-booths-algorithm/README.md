# Experiment 11 — Booth's Multiplication Algorithm

**Date:** 05/12/2018

## Aim
To implement Booth's algorithm for 4-bit signed multiplication in C, print the step
table for one product and verify the routine against several signed operand pairs.

## Tools
gcc (C program, no HDL simulation this week). Compiled with `gcc -std=c99 -Wall booth.c -o booth`.

## Theory
Booth's algorithm multiplies 2's complement numbers directly. It recodes runs of 1s in
the multiplier: a run from bit j to bit k is worth 2^(k+1) − 2^j, so the machine
subtracts M where a run begins (Q0 Q-1 = 10) and adds M where it ends (Q0 Q-1 = 01),
shifting otherwise. Every cycle ends with an arithmetic right shift of the combined
A:Q:Q-1 register — the sign bit of A is copied in, not a zero, which is what makes
negative accumulators come out right. A negative multiplier ends in a run of 1s that
never terminates, so the closing addition never happens and no correction step is
needed. The product is A:Q, 2n bits.

## Design
Registers: A (4 bits, starts 0), Q = multiplier, Q-1 = 0, M = multiplicand. Four
cycles of: inspect Q0 Q-1, add/subtract M into A if 01/10, then ASR A:Q:Q-1. All
register arithmetic is masked to 4 bits; the sign of the 8-bit product A:Q is fixed
up at the end.

## Code
- `booth.c` — `booth()` routine traces the A/Q/Q-1 table for −6 × 7, then runs four more pairs through the same routine and tabulates the products against m*q

## Observations
```
trace of -6 x 7:

M = 1010, -M = 0110

step   A     Q    Q-1  operation
  0   0000  0111   0   initial values
  1   0110  0111   0   Q0 Q-1 = 10 : A = A - M
  1   0011  0011   1   ASR
  2   0001  1001   1   ASR
  3   0000  1100   1   ASR
  4   1010  1100   1   Q0 Q-1 = 01 : A = A + M
  4   1101  0110   0   ASR

product A:Q = -42   check: -6 x 7 = -42

more products through the same routine:
   m    q   booth   m*q
   5   -3    -15   -15
  -7   -8     56    56
  -4    6    -24   -24
   7    7     49    49
```

## Result
The traced product A:Q = 1101 0110 = −42 matches −6 × 7. All checked pairs agree with
direct multiplication, including negative × negative (−7 × −8 = 56), confirming the
algorithm needs no special cases for signs.
