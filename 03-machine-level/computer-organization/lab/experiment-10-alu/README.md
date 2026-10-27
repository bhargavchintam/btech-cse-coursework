# Experiment 10 — Arithmetic Logic Unit

**Date:** 28/11/2018

## Aim
To design and simulate a 4-bit ALU performing eight operations selected by a 3-bit
function code, with carry and zero flags.

## Tools
ModelSim / Xilinx ISE in the lab. Simulated again at home with Icarus Verilog.

## Theory
The ALU is the part of the processor datapath that actually computes. It takes two
operands and a function select code; the select lines act like a multiplexer choosing
which computed result reaches the output. Arithmetic is done on 5 bits internally so
the extra bit becomes the carry flag — for subtraction the same bit reads as a borrow,
and for shifts it catches the bit that falls off the end. The zero flag is just a NOR
of the result bits and is what conditional branch instructions test.

## Design
Function table:
```
sel   operation        cout means
000   y = a + b        carry out
001   y = a - b        borrow
010   y = a AND b      0
011   y = a OR b       0
100   y = a XOR b      0
101   y = NOT a        0
110   y = a << 1       bit shifted out (a3)
111   y = a >> 1       bit shifted out (a0)
```
zero = 1 when y = 0000. One always block with a case on sel, result computed in a
5-bit temporary.

## Code
- `alu4.v` — behavioural ALU, case on sel, 5-bit internal result
- `alu4_tb.v` — holds a = 10, b = 6 and steps sel through all eight codes

## Observations
```
a = 1010 (10), b = 0110 (6)
 sel  op    y        cout  zero
 000  ADD   0000( 0)   1     1
 001  SUB   0100( 4)   0     0
 010  AND   0010( 2)   0     0
 011  OR    1110(14)   0     0
 100  XOR   1100(12)   0     0
 101  NOTA  0101( 5)   0     0
 110  SHL   0100( 4)   1     0
 111  SHR   0101( 5)   0     0
alu4_tb.v:31: $finish called at 40 (1s)
```

## Result
All eight operations are correct for a = 10, b = 6. The ADD row shows both flags at
once: 10 + 6 = 16 overflows 4 bits, so y = 0000 with cout = 1 and zero = 1. SHL also
sets cout because the MSB of 1010 falls off.
