# Experiment 14 — DAC Waveform Generation

**Date:** 19/03/2019

## Aim
Interface an 8-bit DAC (R-2R ladder) to port 1 of the 8051 and generate a ramp
(sawtooth) and a triangular waveform at the DAC output using embedded C.

## Tools
Keil µVision 4 / SDCC.

## Algorithm
1. Connect the eight DAC data lines to P1. An input of 00H gives 0 V at the
   output and FFH gives full scale.
2. For the ramp, count a value from 0 to 255 and write each step to P1; when it
   wraps the output snaps back to 0 V, giving a sawtooth.
3. For the triangle, count up 0 to 255 (rising slope) and then back down 255 to 0
   (falling slope).
4. In `main`, call the ramp routine and the triangle routine forever.

## Program
`dac_waveform.c` — outputs a ramp and a triangular wave on an R-2R DAC wired to P1.

## Result
Writing successive values to P1 drives the DAC output through the corresponding
voltage steps. The ramp routine produces a rising sawtooth that resets to 0 V at
the FFH → 00H wrap; the triangle routine produces a symmetric rise-and-fall.

| Routine  | P1 sequence         | Output at DAC        |
| ramp     | 00H → FFH, repeat   | rising sawtooth      |
| triangle | 00H → FFH → 00H     | triangular wave      |

Observed behaviour: on a CRO the DAC output shows a sawtooth followed by a
triangular waveform; the period is set by how fast P1 is updated.
