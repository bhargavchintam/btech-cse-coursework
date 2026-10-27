# Experiment 6 — 8:1 Multiplexer using 74151

**Date:** 11/10/2018

## Aim
Verify the 74151 8:1 multiplexer and use it to implement a 3-variable boolean function.

## Components / ICs
74151 (8:1 mux, 16-pin), breadboard, 5 V, LEDs, wires.

## Pin diagram
```
 D0=4  D1=3  D2=2  D3=1  D4=15 D5=14 D6=13 D7=12
 Select:  A=11  B=10  C=9
 Y(output)=5   W(inverted output)=6
 Strobe/Enable G (active low)=7
 VCC=16   GND=8
```

## Theory
The mux routes the data input selected by CBA to Y. With the strobe G low (enabled): Y = D(CBA). Any 3-variable function F(A,B,C) is implemented by tying A,B,C to the selects and each data input Dn to the function's value (0 or 1) for that minterm.

## Truth table — implement F(A,B,C) = Σm(1,2,6,7)
Set the data inputs to the minterm values:
| Minterm | C B A | Dn | value |
|---|---|-----|-------|
| 0 | 000 | D0 | 0 |
| 1 | 001 | D1 | 1 |
| 2 | 010 | D2 | 1 |
| 3 | 011 | D3 | 0 |
| 4 | 100 | D4 | 0 |
| 5 | 101 | D5 | 0 |
| 6 | 110 | D6 | 1 |
| 7 | 111 | D7 | 1 |

Selecting each combination gives Y = F.

## Procedure
1. Power: pin 16 = +5 V, pin 8 = GND, strobe (pin 7) = 0.
2. Tie D0–D7 to 0/1 as per the function table.
3. Step the selects A,B,C through 000–111 and read Y on an LED.
4. Confirm Y matches Σm(1,2,6,7).

## Result
The 74151 mux was verified and F = Σm(1,2,6,7) implemented; output matched the truth table.
