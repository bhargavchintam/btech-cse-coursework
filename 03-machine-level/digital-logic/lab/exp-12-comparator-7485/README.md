# Experiment 12 — 4-bit Magnitude Comparator using 7485

**Date:** 29/11/2018

## Aim
Compare two 4-bit numbers using the 7485 magnitude comparator.

## Components / ICs
7485 (4-bit comparator, 16-pin), breadboard, 5 V, LEDs, wires.

## Pin diagram
```
 A inputs: A0=10 A1=12 A2=13 A3=15
 B inputs: B0=9  B1=11 B2=14 B3=1
 Cascade inputs: (A<B)in=2  (A=B)in=3  (A>B)in=4
 Outputs: (A>B)=5  (A=B)=6  (A<B)=7
 VCC=16   GND=8
```

## Theory
The 7485 compares A3..A0 with B3..B0 from the MSB down and asserts one of A>B, A=B, A<B. The cascade inputs let several 7485s chain for wider numbers — for a single 4-bit stage tie (A=B)in HIGH and (A>B)in, (A<B)in LOW.

## Truth table (examples, single stage)
| A | B | A>B | A=B | A<B |
|---|---|-----|-----|-----|
| 1001 | 0110 | 1 | 0 | 0 | (9 > 6) |
| 0101 | 0101 | 0 | 1 | 0 | (5 = 5) |
| 0011 | 1000 | 0 | 0 | 1 | (3 < 8) |

## Procedure
1. Power: pin 16 = +5 V, pin 8 = GND.
2. Tie (A=B)in HIGH, (A>B)in and (A<B)in LOW.
3. Apply the two 4-bit numbers on A0–A3 and B0–B3.
4. Read the three outputs on LEDs and tabulate for several pairs.

## Result
The 7485 correctly flagged greater-than, equal and less-than for the tested 4-bit pairs.
