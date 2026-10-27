# Experiment 4 — Half Adder and Full Adder

**Date:** 20/09/2018

## Aim
Design and verify a half adder and a full adder using logic gates.

## Components / ICs
7486 (XOR), 7408 (AND), 7432 (OR), breadboard, 5 V, LEDs, wires.

## Pin diagram
7486 / 7408 / 7432 all: 1,2→3 / 4,5→6 / 9,10→8 / 12,13→11, VCC=14, GND=7.

## Theory
Half adder adds two bits:
Sum = A ⊕ B, Carry = A · B.
Full adder adds three bits (A, B and a carry-in):
Sum = A ⊕ B ⊕ Cin, Cout = A·B + B·Cin + A·Cin.
A full adder is two half adders plus an OR gate.

## Truth table
Half adder:
| A | B | Sum | Carry |
|---|---|-----|-------|
| 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 0 |
| 1 | 0 | 1 | 0 |
| 1 | 1 | 0 | 1 |

Full adder:
| A | B | Cin | Sum | Cout |
|---|---|-----|-----|------|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 | 0 |
| 0 | 1 | 0 | 1 | 0 |
| 0 | 1 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 0 | 1 | 0 | 1 |
| 1 | 1 | 0 | 0 | 1 |
| 1 | 1 | 1 | 1 | 1 |

## Procedure
1. For the half adder wire one XOR (Sum) and one AND (Carry) to the same inputs.
2. Verify against the truth table.
3. For the full adder use two XORs for Sum and combine AB, BCin, ACin through ANDs and an OR for Cout.

## Result
Half adder and full adder built and verified; outputs match the truth tables.
