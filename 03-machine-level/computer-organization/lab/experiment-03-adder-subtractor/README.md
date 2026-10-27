# Experiment 3 — 4-bit Adder-Subtractor

**Date:** 12/09/2018

## Aim
To design a 4-bit ripple carry adder-subtractor with a single mode input in Verilog and verify addition, subtraction, a negative result in 2's complement form, and signed overflow detection.

## Tools
ModelSim / Xilinx ISE in the lab. Simulated again at home with Icarus Verilog.

## Theory
Subtraction in 2's complement is addition: a − b = a + b' + 1. So one ripple adder does both jobs. Each bit of b passes through an XOR gate whose other input is the mode bit m. When m = 0 the XOR passes b unchanged and cin = 0, giving a + b. When m = 1 the XOR inverts every bit of b and cin = 1 supplies the +1, giving a + b' + 1 = a − b. For unsigned subtraction cout = 1 means no borrow and cout = 0 means the result wrapped (a < b), in which case s holds the 2's complement of the true difference. For signed numbers cout is meaningless; overflow is instead v = c3 XOR c4, the carry into the sign bit XOR the carry out of it.

## Design
```
x[i] = b[i] XOR m          (i = 0..3)
c[0] = m
s[i], c[i+1] = FA(a[i], x[i], c[i])
cout = c[4]
v    = c[3] XOR c[4]

  b3 m  b2 m  b1 m  b0 m
   \ /   \ /   \ /   \ /
   XOR   XOR   XOR   XOR
    |     |     |     |
a3-[FA]-a2-[FA]-a1-[FA]-a0-[FA]-- cin = m
    |c4    |c3    |c2    |c1
    s3     s2     s1     s0
```
One full adder per bit, carries ripple right to left.

## Code
- `adder_subtractor.v` — full adder module `fa` plus the 4-bit adder-subtractor with the b-XOR-m trick
- `adder_subtractor_tb.v` — three additions and three subtractions covering a negative result and both overflow directions

## Observations
```
 op   a         b         s     uns  signed  cout  v
 -----------------------------------------------------
 ADD  0100( 4)  0011( 3)   0111   7    7     0    0
 ADD  0110( 6)  0101( 5)   1011  11   -5     0    1
 ADD  1100(12)  1110(14)   1010  10   -6     1    0
 SUB  0111( 7)  0011( 3)   0100   4    4     1    0
 SUB  0010( 2)  0101( 5)   1101  13   -3     0    0
 SUB  1000( 8)  0001( 1)   0111   7    7     1    1
adder_subtractor_tb.v:32: $finish called at 60 (1s)
```
Row 2: 6 + 5 = 11 does not fit in 4-bit signed range, v = 1 and the sum reads −5.
Row 3: 1100 is −4 and 1110 is −2. Carry out is 1 but v = 0, so the signed answer −6 is correct; cout is ignored for signed numbers.
Row 5: 2 − 5 gives 1101, which is −3 in 2's complement. cout = 0 flags the borrow for unsigned interpretation.
Row 6: (−8) − 1 = −9 underflows, v = 1 and the result wraps to +7.

## Result
The 4-bit adder-subtractor works in both modes with one adder and four XOR gates. Negative results appear in 2's complement form and the overflow flag v = c3 XOR c4 correctly detects both overflow cases.
