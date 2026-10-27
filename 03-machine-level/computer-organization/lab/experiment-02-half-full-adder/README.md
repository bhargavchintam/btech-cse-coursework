# Experiment 2 — Half Adder and Full Adder

**Date:** 05/09/2018

## Aim
To design a half adder and a full adder in Verilog, build the full adder structurally from two half adders, and verify both truth tables by simulation.

## Tools
ModelSim / Xilinx ISE in the lab. Simulated again at home with Icarus Verilog.

## Theory
A half adder adds two bits and produces a sum and a carry. The sum is the XOR of the inputs and the carry is the AND. It cannot accept a carry from a previous stage, which is why it is only "half" an adder. A full adder adds three bits — a, b and a carry-in — and can be built from two half adders: the first adds a and b, the second adds that partial sum to cin, and the final carry is the OR of the two intermediate carries. Chaining full adders bit by bit gives a ripple carry adder, which is the basis of the next experiment.

## Design
```
Half adder:  s = a XOR b        c = a.b

Full adder:  s    = a XOR b XOR cin
             cout = a.b + cin.(a XOR b)

        a --+----[HA1]-- s1 --+----[HA2]-- s
        b --+         \       |         \
                       c1    cin         c2
                        \                /
                         +----[ OR ]----+---- cout
```

## Code
- `half_adder.v` — dataflow half adder
- `half_adder_tb.v` — walks the 4 input combinations with $monitor
- `full_adder.v` — structural, instantiates half_adder twice plus an OR
- `full_adder_tb.v` — loops all 8 combinations, prints the truth table

## Observations
Half adder (`vvp` output):
```
a b | s c
0 0 | 0 0
0 1 | 1 0
1 0 | 1 0
1 1 | 0 1
half_adder_tb.v:15: $finish called at 20 (1s)
```
Full adder (`vvp` output):
```
a b cin | s cout
0 0  0  | 0  0
0 0  1  | 1  0
0 1  0  | 1  0
0 1  1  | 0  1
1 0  0  | 1  0
1 0  1  | 0  1
1 1  0  | 0  1
1 1  1  | 1  1
full_adder_tb.v:16: $finish called at 40 (1s)
```

## Result
The half adder and the full adder built from two half adders were simulated and both truth tables match the theoretical values for all input combinations.
