# Experiment 1 — Study and Verification of Basic Logic Gates

**Date:** 30/08/2018

## Aim
Verify the truth tables of the basic logic gates using 74-series ICs.

## Components / ICs
| IC | Name |
|----|------|
| 7408 | Quad 2-input AND |
| 7432 | Quad 2-input OR |
| 7404 | Hex inverter (NOT) |
| 7400 | Quad 2-input NAND |
| 7402 | Quad 2-input NOR |
| 7486 | Quad 2-input XOR |

Also: breadboard, 5 V supply, LEDs with 330 Ω resistors, connecting wires.

## Pin diagram
All the quad 2-input gates (7408/7432/7400/7486) share the same layout:
```
 pin 1,2  -> gate1 in     pin 3  -> gate1 out
 pin 4,5  -> gate2 in     pin 6  -> gate2 out
 pin 9,10 -> gate3 in     pin 8  -> gate3 out
 pin 12,13-> gate4 in     pin 11 -> gate4 out
 pin 14 = VCC             pin 7  = GND
```
7402 (NOR) is different — output comes first: gate1 out=1, in=2,3; gate2 out=4, in=5,6; gate3 out=10, in=8,9; gate4 out=13, in=11,12. VCC=14, GND=7.
7404 (NOT): 1->2, 3->4, 5->6, 9->8, 11->10, 13->12. VCC=14, GND=7.

## Theory
Each gate implements a boolean function: AND = A·B, OR = A+B, NOT = A', NAND = (A·B)', NOR = (A+B)', XOR = A⊕B.

## Truth table
| A | B | AND | OR | NAND | NOR | XOR |
|---|---|-----|----|------|-----|-----|
| 0 | 0 | 0 | 0 | 1 | 1 | 0 |
| 0 | 1 | 0 | 1 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 1 | 0 | 0 | 0 |

NOT: A=0 → 1, A=1 → 0.

## Procedure
1. Fix the IC on the breadboard, connect pin 14 to +5 V and pin 7 to ground.
2. Apply the input combinations to a gate's input pins using logic switches.
3. Connect the output pin to an LED.
4. Note the LED state for each input combination and tabulate.

## Result
All six gates were verified; the observed outputs match the truth tables.
