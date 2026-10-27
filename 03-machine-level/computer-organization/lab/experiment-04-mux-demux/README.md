# Experiment 4 — Multiplexers and Demultiplexers

**Date:** 19/09/2018

## Aim
To design a 4:1 multiplexer and a 1:4 demultiplexer in Verilog and verify their operation for all select combinations.

## Tools
ModelSim / Xilinx ISE in the lab. Simulated again at home with Icarus Verilog.

## Theory
A multiplexer is a data selector: 2^n data inputs, n select lines, one output. The select lines choose which input is connected through to the output — the rest are ignored. A demultiplexer does the opposite: one data input is routed to exactly one of 2^n output lines, the others stay 0. Together they form the basis of data routing inside a CPU — buses, register file read ports and memory addressing all reduce to mux/demux trees. A 4:1 mux needs 2 select lines; each output of the demux is simply din ANDed with the minterm of sel for that line.

## Design
```
Mux:    y = s1'.s0'.d0 + s1'.s0.d1 + s1.s0'.d2 + s1.s0.d3

Demux:  y0 = din.s1'.s0'    y1 = din.s1'.s0
        y2 = din.s1.s0'     y3 = din.s1.s0
```

## Code
- `mux4to1.v` — 4:1 mux as a chained conditional assign
- `mux4to1_tb.v` — sweeps sel for two different data patterns (1010 and 0110)
- `demux1to4.v` — 1:4 demux, one conditional assign per output line
- `demux1to4_tb.v` — sweeps sel with din = 1, then repeats with din = 0

## Observations
Mux 4:1 (`vvp` output):
```
 d3 d2 d1 d0  sel | y
 -----------------+--
  1  0  1  0   00 | 0
  1  0  1  0   01 | 1
  1  0  1  0   10 | 0
  1  0  1  0   11 | 1
  0  1  1  0   00 | 0
  0  1  1  0   01 | 1
  0  1  1  0   10 | 1
  0  1  1  0   11 | 0
mux4to1_tb.v:25: $finish called at 40 (1s)
```
Demux 1:4 (`vvp` output):
```
 din sel | y3 y2 y1 y0
 --------+------------
  1   00 |  0  0  0  1
  1   01 |  0  0  1  0
  1   10 |  0  1  0  0
  1   11 |  1  0  0  0
  0   00 |  0  0  0  0
  0   01 |  0  0  0  0
  0   10 |  0  0  0  0
  0   11 |  0  0  0  0
demux1to4_tb.v:25: $finish called at 80 (1s)
```

## Result
The 4:1 multiplexer selects the correct data input for every select combination and pattern, and the 1:4 demultiplexer routes din to exactly one output line, with all lines 0 when din = 0.
