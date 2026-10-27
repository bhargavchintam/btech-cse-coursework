# Experiment 2 — Verification of DeMorgan's Theorems

**Date:** 06/09/2018

## Aim
Verify DeMorgan's two theorems: (A·B)' = A' + B' and (A + B)' = A' · B'.

## Components / ICs
7400 (NAND), 7402 (NOR), 7404 (NOT), 7408 (AND), 7432 (OR), breadboard, 5 V, LEDs, wires.

## Pin diagram
Standard quad-gate layout (1,2→3 / 4,5→6 / 9,10→8 / 12,13→11; VCC=14, GND=7) for 7408/7432/7400; 7404 inverter 1→2, 3→4, 5→6; 7402 NOR out-first (out 1, in 2,3).

## Theory
- **First theorem:** the complement of a product = the sum of complements. LHS built with an AND (7408) + inverter (7404) → NAND. RHS built with two inverters + an OR (7432).
- **Second theorem:** the complement of a sum = the product of complements. LHS = OR + inverter → NOR. RHS = two inverters + AND.

## Truth table
| A | B | (A·B)' | A'+B' | (A+B)' | A'·B' |
|---|---|--------|-------|--------|-------|
| 0 | 0 | 1 | 1 | 1 | 1 |
| 0 | 1 | 1 | 1 | 0 | 0 |
| 1 | 0 | 1 | 1 | 0 | 0 |
| 1 | 1 | 0 | 0 | 0 | 0 |

Columns 3=4 and 5=6 for every row → both theorems hold.

## Procedure
1. Build the LHS and RHS of the first theorem separately.
2. Apply all four input combinations and compare the two outputs — they must be equal.
3. Repeat for the second theorem.

## Result
Both theorems verified; LHS and RHS outputs matched for all input combinations.
