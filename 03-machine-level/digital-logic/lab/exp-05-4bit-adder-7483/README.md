# Experiment 5 — 4-bit Binary Adder using 7483

**Date:** 27/09/2018

## Aim
Add two 4-bit binary numbers using the 7483 4-bit binary full-adder IC.

## Components / ICs
7483 (4-bit binary full adder, 16-pin), breadboard, 5 V, LEDs, wires.

## Pin diagram
The 7483 pinout is scrambled — note VCC and GND are NOT on the corners:
```
 A1=10  A2=8   A3=3   A4=1
 B1=11  B2=7   B3=4   B4=16
 S1=9   S2=6   S3=2   S4=15
 C0(carry in)=13   C4(carry out)=14
 VCC=5   GND=12
```

## Theory
Each stage is a full adder; the carry ripples from S1 (LSB) to S4 (MSB). Result is S4 S3 S2 S1 with final carry C4. Set C0 = 0 for a plain add. Two 7483s cascade by feeding C4 of the first into C0 of the second → 8-bit adder.

## Truth table (worked examples)
| A (A4..A1) | B | C0 | Sum (C4 S4..S1) | Decimal |
|---|---|----|-----|---------|
| 0111 | 0101 | 0 | 0 1100 | 7 + 5 = 12 |
| 1001 | 0111 | 0 | 1 0000 | 9 + 7 = 16 |
| 0011 | 0001 | 1 | 0 0101 | 3 + 1 + 1 = 5 |

## Procedure
1. Power the IC: pin 5 = +5 V, pin 12 = GND.
2. Apply A1–A4 and B1–B4 on their pins, set C0 (pin 13) = 0.
3. Read the sum on S1–S4 and the carry on C4 (pin 14) via LEDs.
4. Repeat for the example numbers and tabulate.

## Result
4-bit addition verified on the 7483; sums and carry-out match the expected binary results.
