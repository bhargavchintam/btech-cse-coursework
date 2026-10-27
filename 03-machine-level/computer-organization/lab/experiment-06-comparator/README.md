# Experiment 6 — Magnitude Comparator

**Date:** 10/10/2018

## Aim
To design and simulate a 2-bit magnitude comparator and verify all 16 input combinations.

## Tools
ModelSim / Xilinx ISE in the lab. Simulated again at home with Icarus Verilog.

## Theory
A magnitude comparator takes two unsigned numbers A and B and produces three outputs:
A > B, A = B and A < B. Exactly one of the three is high for any input pair. Equality is
built bit by bit — two bits are equal when their XNOR is 1, and the words are equal when
every bit position is equal. For the greater-than output the comparison starts at the MSB:
A > B if a1 > b1, or if the MSBs are equal and a0 > b0. Less-than is the mirror of the
same argument. The 7485 IC does exactly this for 4 bits.

## Design
With e1 = (a1 XNOR b1) and e0 = (a0 XNOR b0):
```
eq = e1·e0
gt = a1·b1' + e1·a0·b0'
lt = a1'·b1 + e1·a0'·b0
```

## Code
- `comparator2.v` — dataflow, the three equations above
- `comparator2_tb.v` — two nested loops, all 16 combinations

## Observations
```
 a  b | a>b a=b a<b
00 00 |  0   1   0
00 01 |  0   0   1
00 10 |  0   0   1
00 11 |  0   0   1
01 00 |  1   0   0
01 01 |  0   1   0
01 10 |  0   0   1
01 11 |  0   0   1
10 00 |  1   0   0
10 01 |  1   0   0
10 10 |  0   1   0
10 11 |  0   0   1
11 00 |  1   0   0
11 01 |  1   0   0
11 10 |  1   0   0
11 11 |  0   1   0
comparator2_tb.v:16: $finish called at 80 (1s)
```
Exactly one output is high in every row, and the four a=b diagonal rows all give eq = 1.

## Result
The 2-bit magnitude comparator was designed from boolean equations and simulated. All 16 combinations produced the correct gt/eq/lt outputs.
