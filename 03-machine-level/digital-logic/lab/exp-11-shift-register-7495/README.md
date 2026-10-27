# Experiment 11 — 4-bit Shift Register using 7495

**Date:** 22/11/2018

## Aim
Verify serial data shifting through the 7495 4-bit shift register.

## Components / ICs
7495 (4-bit shift register, 14-pin), breadboard, 5 V, clock, LEDs, wires.

## Pin diagram
```
 Serial in=1   Parallel in: A=2 B=3 C=4 D=5
 Mode control S=6
 Clock 2 (CP2, shift right)=8    Clock 1 (CP1, parallel load)=9
 Outputs: QA=13 QB=12 QC=11 QD=10
 VCC=14   GND=7
```

## Theory
Mode S = 0 → serial **shift right** on the CP2 clock: the serial-input bit enters QA and each stored bit moves QA→QB→QC→QD, leaving at QD. Mode S = 1 → **parallel load** of A–D on CP1. So serial-in-serial-out data appears at QD after four clocks.

## Truth table — shifting in 1 0 1 1 (S = 0, serial mode)
| Clock | Serial in | QA | QB | QC | QD |
|-------|-----------|----|----|----|----|
| 0 (start) | – | 0 | 0 | 0 | 0 |
| 1 | 1 | 1 | 0 | 0 | 0 |
| 2 | 0 | 0 | 1 | 0 | 0 |
| 3 | 1 | 1 | 0 | 1 | 0 |
| 4 | 1 | 1 | 1 | 0 | 1 |

The first bit reaches QD after 4 clocks.

## Procedure
1. Power: pin 14 = +5 V, pin 7 = GND; set mode S = 0.
2. Apply the serial bit on pin 1 and pulse CP2 (pin 8).
3. After each clock, read QA–QD and tabulate the shift.

## Result
Serial data shifted right through the register and appeared at QD after four clocks, verifying the 7495.
