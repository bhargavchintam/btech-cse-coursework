# Experiment 9 — JK Flip-Flop using 7476

**Date:** 08/11/2018

## Aim
Verify the JK flip-flop using the 7476 (dual JK with preset and clear).

## Components / ICs
7476 (dual JK flip-flop, 16-pin), breadboard, 5 V, clock/switch, LEDs, wires.

## Pin diagram
The 7476 has VCC and GND in unusual positions:
```
 Flip-flop 1: CLK=1  PR=2  CLR=3  J=4  K=16  Q=15  Q'=14
 Flip-flop 2: CLK=6  PR=7  CLR=8  J=9  K=12  Q=11  Q'=10
 VCC=5   GND=13
 PR (preset) and CLR (clear) are active LOW.
```

## Theory
On the clock, the JK flip-flop follows: 00 hold, 01 reset, 10 set, 11 toggle. Preset and clear are asynchronous and active low — keep both HIGH for normal clocked operation; PR=0 forces Q=1, CLR=0 forces Q=0.

## Truth table (function table, PR = CLR = 1)
| J | K | Q(next) |
|---|---|---------|
| 0 | 0 | Q (no change) |
| 0 | 1 | 0 |
| 1 | 0 | 1 |
| 1 | 1 | Q' (toggle) |

Async: PR=0 → Q=1; CLR=0 → Q=0.

## Procedure
1. Power: pin 5 = +5 V, pin 13 = GND; tie PR and CLR HIGH.
2. Apply J and K, give a clock pulse on pin 1, read Q on pin 15.
3. Verify all four cases; confirm J=K=1 toggles Q on each pulse.
4. Test preset/clear by pulling PR or CLR low.

## Result
The JK flip-flop was verified on the 7476, including the toggle at J=K=1 and the active-low preset/clear. (A D flip-flop can be shown similarly on the 7474: 1CLK=3, 1D=2, 1Q=5, VCC=14, GND=7.)
