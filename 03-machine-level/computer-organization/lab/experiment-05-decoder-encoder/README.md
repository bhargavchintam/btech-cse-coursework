# Experiment 5 — Decoders and Encoders

**Date:** 03/10/2018

## Aim
To design and simulate a 2:4 decoder with enable and an 8:3 priority encoder with a valid output, and verify their truth tables.

## Tools
ModelSim / Xilinx ISE in the lab. Simulated again at home with Icarus Verilog.

## Theory
A decoder converts an n-bit binary code into 2^n output lines, of which exactly one is
active for each input combination. The enable input gates all outputs — when en = 0 every
output stays low regardless of the address. An encoder does the reverse: it converts an
active input line back into its binary index. A plain encoder fails when two inputs are
high at once, so the practical circuit is a priority encoder — the highest numbered active
input wins and the lower ones are ignored. The valid bit v distinguishes "input d0 active"
from "no input active", since both would otherwise give the code 000.

## Design
Decoder (active high enable):
```
y0 = en·a1'·a0'    y1 = en·a1'·a0
y2 = en·a1·a0'     y3 = en·a1·a0
```
Priority encoder: checked from d7 down to d0 with a casez; first 1 found sets y to that
index. v = 1 if any input is 1, else v = 0 and y is don't care (kept 000 here).

## Code
- `decoder2to4.v` — 2:4 decoder, dataflow assigns
- `decoder2to4_tb.v` — enable off case then all four input codes
- `encoder8to3.v` — 8:3 priority encoder with valid, casez inside always @(*)
- `encoder8to3_tb.v` — all zeros, each line alone, then two multi-input cases

## Observations
Decoder:
```
en a1 a0 | y3 y2 y1 y0
 0  0  0 |  0  0  0  0
 1  0  0 |  0  0  0  1
 1  0  1 |  0  0  1  0
 1  1  0 |  0  1  0  0
 1  1  1 |  1  0  0  0
decoder2to4_tb.v:19: $finish called at 50 (1s)
```

Priority encoder:
```
d7......d0 | y2 y1 y0  v
  00000000 |  0  0  0  0
  00000001 |  0  0  0  1
  00000010 |  0  0  1  1
  00000100 |  0  1  0  1
  00001000 |  0  1  1  1
  00010000 |  1  0  0  1
  00100000 |  1  0  1  1
  01000000 |  1  1  0  1
  10000000 |  1  1  1  1
  00101000 |  1  0  1  1
  00000110 |  0  1  0  1
encoder8to3_tb.v:23: $finish called at 110 (1s)
```
With d5 and d3 both high the output is 101 (5), and with d2 and d1 both high it is
010 (2) — the higher index wins. All zeros gives v = 0.

## Result
The 2:4 decoder and 8:3 priority encoder were designed and simulated. Outputs matched the expected truth tables, including the priority and valid behaviour.
