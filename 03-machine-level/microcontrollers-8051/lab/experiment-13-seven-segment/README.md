# Experiment 13 — Seven-Segment Display (0–9)

**Date:** 12/03/2019

## Aim
Interface a common-cathode seven-segment display to port 2 of the 8051 and
display the digits 0 through 9 in sequence using embedded C.

## Tools
Keil µVision 4 / SDCC.

## Algorithm
1. Work out the segment code for each digit. The display is common-cathode and a
   segment lights when its port line is high, with bit0=a, bit1=b, bit2=c,
   bit3=d, bit4=e, bit5=f, bit6=g.
2. Store the ten codes 0–9 in a ROM lookup table.
3. Write a `delay()` routine so each digit stays on long enough to be read.
4. In `main`, loop forever: step an index d from 0 to 9, write `seg[d]` to P2,
   and delay before the next digit.

## Program
`seven_segment.c` — drives a common-cathode seven-segment through 0–9 on P2 using
the verified segment-code table.

## Result
Port 2 outputs the segment pattern for each digit; the display counts 0, 1, 2 …
9 and repeats. The lookup codes used are:

| Digit | Segments lit    | Code |
| 0     | a b c d e f     | 3FH  |
| 1     | b c             | 06H  |
| 2     | a b d e g       | 5BH  |
| 3     | a b c d g       | 4FH  |
| 4     | b c f g         | 66H  |
| 5     | a c d f g       | 6DH  |
| 6     | a c d e f g     | 7DH  |
| 7     | a b c           | 07H  |
| 8     | a b c d e f g   | 7FH  |
| 9     | a b c d f g     | 6FH  |

Observed behaviour: the seven-segment display counts up 0–9 and rolls over.
