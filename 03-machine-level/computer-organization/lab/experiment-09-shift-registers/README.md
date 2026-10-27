# Experiment 9 — Shift Registers

**Date:** 21/11/2018

## Aim
To design and simulate a 4-bit universal shift register and demonstrate all four data
transfer types — SISO, SIPO, PISO and PIPO — with a single circuit.

## Tools
ModelSim / Xilinx ISE in the lab. Simulated again at home with Icarus Verilog.

## Theory
A shift register is a chain of D flip-flops where each output feeds the next input, so
the stored word moves one position per clock. The four register types are just four ways
of using the same chain: serial-in serial-out (SISO) watches only the last bit, serial-in
parallel-out (SIPO) reads all four outputs after shifting in, parallel-in serial-out
(PISO) loads all four bits at once and shifts them out one per clock, and parallel-in
parallel-out (PIPO) is a plain load-and-read register. A universal shift register
(the 74194 IC) puts a mode select in front of each flip-flop input so one circuit does
hold, shift right, shift left and parallel load.

## Design
Mode select on a 4-bit register, positive edge triggered, asynchronous reset:
```
mode 00 : q+ = q                 (hold)
mode 01 : q+ = {sin_r, q[3:1]}   (shift right, serial in at MSB, serial out = q0)
mode 10 : q+ = {q[2:0], sin_l}   (shift left, serial in at LSB)
mode 11 : q+ = pin               (parallel load)
```
One behavioural always block with a case on mode, nonblocking assignments.

## Code
- `shift_register.v` — universal shift register, case on mode
- `shift_register_tb.v` — loads 1001 (PIPO), holds, shifts it out serially LSB first (PISO/SISO), then shifts 1011 in serially (SIPO)

## Observations
```
clk#  mode  op    sin | q     sout(q0 before shift)
  1    11   load   -  | 1001    -
  2    00   hold   -  | 1001    -
  3    01   shr    0  | 0100    1
  4    01   shr    0  | 0010    0
  5    01   shr    0  | 0001    0
  6    01   shr    0  | 0000    1
  7    10   shl    1  | 0001    -
  8    10   shl    0  | 0010    -
  9    10   shl    1  | 0101    -
 10    10   shl    1  | 1011    -
shift_register_tb.v:40: $finish called at 106 (1s)
```

## Result
The register holds, loads and shifts in both directions. The loaded word 1001 comes out
of q0 serially as 1,0,0,1 (PISO), and serially feeding 1011 fills the register in four
clocks (SIPO). One circuit demonstrates all four shift register types.
