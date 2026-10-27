# Experiment 7 — 3:8 Decoder using 74138

**Date:** 18/10/2018

## Aim
Verify the 74138 3-to-8 line decoder and note its use as a demultiplexer.

## Components / ICs
74138 (3:8 decoder, 16-pin), breadboard, 5 V, LEDs, wires.

## Pin diagram
```
 Select: A0=1  A1=2  A2=3
 Enables: E1(G2A)=4 (active low), E2(G2B)=5 (active low), E3(G1)=6 (active high)
 Outputs (active low): Y0=15 Y1=14 Y2=13 Y3=12 Y4=11 Y5=10 Y6=9 Y7=7
 VCC=16   GND=8
```

## Theory
When enabled (E1=0, E2=0, E3=1) the selected output (address A2A1A0) goes LOW and all others stay HIGH — outputs are **active low**. Each output corresponds to one minterm, so a decoder + NAND gates implements functions. Feeding data into an enable pin turns it into a 1:8 demultiplexer.

## Truth table (enabled)
| A2 | A1 | A0 | Low output |
|----|----|----|-----------|
| 0 | 0 | 0 | Y0 |
| 0 | 0 | 1 | Y1 |
| 0 | 1 | 0 | Y2 |
| 0 | 1 | 1 | Y3 |
| 1 | 0 | 0 | Y4 |
| 1 | 0 | 1 | Y5 |
| 1 | 1 | 0 | Y6 |
| 1 | 1 | 1 | Y7 |

If any enable is wrong (E1 or E2 high, or E3 low) all outputs are HIGH.

## Procedure
1. Power: pin 16 = +5 V, pin 8 = GND.
2. Set E1=0, E2=0, E3=1 to enable.
3. Step A2A1A0 through 000–111; confirm exactly one output goes LOW each time.
4. Verify the disabled condition holds all outputs HIGH.

## Result
The 74138 decoder was verified; the addressed output went low with all others high, matching the function table.
