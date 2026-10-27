# Experiment 10 — Decade (Mod-10) Counter using 7490

**Date:** 15/11/2018

## Aim
Verify the 7490 as a BCD (mod-10) ripple counter.

## Components / ICs
7490 (decade counter, 14-pin), breadboard, 5 V, clock, LEDs, wires.

## Pin diagram
```
 CKA (clock A, ÷2)=14   CKB (clock B, ÷5)=1
 Reset-to-0: R0(1)=2  R0(2)=3
 Set-to-9:   R9(1)=6  R9(2)=7
 Outputs: QA=12  QB=9  QC=8  QD=11
 VCC=5   GND=10
```

## Theory
The 7490 is a ÷2 (flip-flop A) followed by a ÷5 section. For a **BCD/mod-10** count, connect **QA (pin 12) to CKB (pin 1)** and apply the clock to CKA (pin 14). The output QD QC QB QA then counts 0000 → 1001 and rolls over. The reset pins override the count: both R0 high → 0000; both R9 high → 1001.

## Truth table — count sequence and resets
Count (QD QC QB QA): 0000, 0001, 0010, 0011, 0100, 0101, 0110, 0111, 1000, 1001, back to 0000.

| R0(1) | R0(2) | R9(1) | R9(2) | Output |
|-------|-------|-------|-------|--------|
| 1 | 1 | 0 | 0 | 0000 (reset) |
| 0 | 0 | 1 | 1 | 1001 (set to 9) |
| 0 | X | 0 | X | counts |

## Procedure
1. Power: pin 5 = +5 V, pin 10 = GND.
2. Connect QA (12) → CKB (1); apply clock to CKA (14).
3. Tie the reset pins low to allow counting.
4. Observe QD–QA on LEDs through the ten states; confirm rollover after 1001.

## Result
The 7490 counted 0000 through 1001 in BCD and rolled over; reset and set-to-9 functions verified.
