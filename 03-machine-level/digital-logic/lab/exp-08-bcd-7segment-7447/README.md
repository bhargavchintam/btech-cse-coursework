# Experiment 8 — BCD to 7-Segment Decoder using 7447

**Date:** 25/10/2018

## Aim
Display decimal digits 0–9 on a seven-segment display using the 7447 BCD-to-7-segment decoder/driver.

## Components / ICs
7447 (BCD to 7-segment decoder/driver, 16-pin), common-anode 7-segment display, 7×330 Ω resistors, 5 V, wires.

## Pin diagram
```
 Inputs (BCD):  A=7  B=1  C=2  D=6
 Control: LT(lamp test)=3, RBI(ripple blank in)=5, BI/RBO=4  (all active low)
 Outputs (active low, to segments): a=13 b=12 c=11 d=10 e=9 f=15 g=14
 VCC=16   GND=8
```

## Theory
The 7447 takes a 4-bit BCD input DCBA and drives the seven segments. Outputs are **active low** — a segment lights when its output is 0 — which suits a **common-anode** display (segment anodes to +5 V through resistors, cathodes driven low by the IC). Keep LT and BI/RBO high (inactive) for normal operation.

## Truth table (segments that light, a–g)
| D C B A | Digit | Segments ON |
|---|---|---|
| 0000 | 0 | a b c d e f |
| 0001 | 1 | b c |
| 0010 | 2 | a b g e d |
| 0011 | 3 | a b g c d |
| 0100 | 4 | f g b c |
| 0101 | 5 | a f g c d |
| 0110 | 6 | a f g c d e |
| 0111 | 7 | a b c |
| 1000 | 8 | a b c d e f g |
| 1001 | 9 | a b c d f g |

## Procedure
1. Power: pin 16 = +5 V, pin 8 = GND; tie LT, RBI, BI/RBO high.
2. Connect segment outputs a–g through 330 Ω resistors to the display, anode to +5 V.
3. Apply BCD 0000–1001 on DCBA and read the displayed digit.

## Result
Digits 0–9 displayed correctly for their BCD inputs, verifying the 7447 decoder/driver.
