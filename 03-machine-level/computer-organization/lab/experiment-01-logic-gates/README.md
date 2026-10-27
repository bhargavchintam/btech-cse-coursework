# Experiment 1 — Realization of Basic Logic Gates

**Date:** 29/08/2018

## Aim
To design and simulate all seven basic logic gates (AND, OR, NOT, NAND, NOR, XOR, XNOR) in Verilog and verify their truth tables.

## Tools
ModelSim / Xilinx ISE in the lab. Simulated again at home with Icarus Verilog.

## Theory
A logic gate implements a boolean function of one or two inputs. AND gives 1 only when both inputs are 1, OR gives 1 when at least one input is 1, and NOT inverts its input. NAND and NOR are the complements of AND and OR — they are called universal gates because any boolean function can be built from either one alone. XOR outputs 1 when the inputs differ, XNOR when they are equal. In Verilog all seven can be written as single dataflow `assign` statements using the operators `&`, `|`, `~`, `^`.

## Design
```
y_and  = a.b          y_nand = (a.b)'
y_or   = a+b          y_nor  = (a+b)'
y_not  = a'           y_xor  = a.b' + a'.b
                      y_xnor = a.b + a'.b'
```
NOT takes only input a; the other six take a and b.

## Code
- `gates.v` — all seven gates as dataflow assigns in one module
- `gates_tb.v` — loops through the four input combinations and prints one combined truth table

## Observations
```
 a b | AND OR NOT NAND NOR XOR XNOR
 ----+-----------------------------
 0 0 |  0   0   1    1   1   0   1
 0 1 |  0   1   1    1   0   1   0
 1 0 |  0   1   0    1   0   1   0
 1 1 |  1   1   0    0   0   0   1
gates_tb.v:18: $finish called at 40 (1s)
```

## Result
All seven gates were designed in Verilog and simulated. The simulated outputs match the standard truth tables for every input combination.
