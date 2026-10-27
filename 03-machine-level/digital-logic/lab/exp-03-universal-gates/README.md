# Experiment 3 — Realization of Gates using Universal Gates

**Date:** 13/09/2018

## Aim
Realize the basic gates (NOT, AND, OR, XOR) using only NAND (7400), and separately using only NOR (7402).

## Components / ICs
7400 (Quad NAND), 7402 (Quad NOR), breadboard, 5 V, LEDs, wires.

## Pin diagram
7400: 1,2→3 / 4,5→6 / 9,10→8 / 12,13→11, VCC=14, GND=7.
7402: out-first — out 1 (in 2,3) / out 4 (in 5,6) / out 10 (in 8,9) / out 13 (in 11,12), VCC=14, GND=7.

## Theory — NAND realizations
- NOT: A NAND A = A'
- AND: (A NAND B) then invert = (A NAND B) NAND (A NAND B)
- OR: invert both inputs, then NAND → (A NAND A) NAND (B NAND B) = A + B  (DeMorgan)
- XOR: A⊕B with four NANDs.

NOR realizations are the dual: NOT = A NOR A; OR = (A NOR B) NOR (A NOR B); AND = (A NOR A) NOR (B NOR B).

## Truth table
Each realized gate is checked against the gate it should equal, e.g. NAND-built AND:
| A | B | AND |
|---|---|-----|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

## Procedure
1. Realize NOT, AND, OR, XOR using only 7400 as per the expressions.
2. Verify each output against the standard truth table.
3. Repeat using only 7402.

## Result
AND, OR, NOT and XOR were realized from NAND alone and from NOR alone; all outputs matched the standard gate truth tables, confirming NAND and NOR are universal.
