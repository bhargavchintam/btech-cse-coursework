# Experiment 7 — Flip-Flops (SR, D, JK, T)

**Date:** 24/10/2018

## Aim
To design and simulate SR, D, JK and T flip-flops with asynchronous clear and verify each characteristic table.

## Tools
ModelSim / Xilinx ISE in the lab. Simulated again at home with Icarus Verilog.

## Theory
A flip-flop stores one bit and changes state only at the active clock edge, unlike a latch
which is transparent while its enable is high. The SR flip-flop sets on S=1, resets on R=1,
holds on 00, and S=R=1 is forbidden — the simulation shows x for that row. The JK flip-flop
fixes the forbidden state by making J=K=1 a toggle. The D flip-flop simply copies its input
at the edge (q+ = d), and the T flip-flop toggles when T=1, which divides the clock by two
and is the building block of ripple counters. All four here use an asynchronous clear so
the testbench can start from a known q = 0.

## Design
Characteristic equations:
```
SR: q+ = s + r'·q   (s·r = 0)
D:  q+ = d
JK: q+ = j·q' + k'·q
T:  q+ = t XOR q
```
Each is one behavioural always block, positive edge triggered, clear has priority.

## Code
- `sr_ff.v` / `sr_ff_tb.v` — case on {s,r}, forbidden input drives q to x
- `d_ff.v` / `d_ff_tb.v` — q follows d at each edge
- `jk_ff.v` / `jk_ff_tb.v` — if-else chain, toggle shown twice
- `t_ff.v` / `t_ff_tb.v` — t held at 1 for six clocks to show divide by two

## Observations
SR flip-flop:
```
s r | q -> q+  action
1 0 | 0 -> 1   set
0 0 | 1 -> 1   hold
0 1 | 1 -> 0   reset
0 0 | 0 -> 0   hold
1 1 | 0 -> x   forbidden
sr_ff_tb.v:25: $finish called at 111 (1s)
```

D flip-flop:
```
d | q -> q+
1 | 0 -> 1
0 | 1 -> 0
1 | 0 -> 1
1 | 1 -> 1
d_ff_tb.v:23: $finish called at 91 (1s)
```

JK flip-flop:
```
j k | q -> q+  action
0 0 | 0 -> 0   hold
1 0 | 0 -> 1   set
0 1 | 1 -> 0   reset
1 1 | 0 -> 1   toggle
1 1 | 1 -> 0   toggle
jk_ff_tb.v:25: $finish called at 111 (1s)
```

T flip-flop:
```
clk# t | q
  1  0 | 0
  2  0 | 0
  3  1 | 1
  4  1 | 0
  5  1 | 1
  6  1 | 0
  7  1 | 1
  8  1 | 0
t_ff_tb.v:25: $finish called at 171 (1s)
```

## Result
All four flip-flops were simulated and matched their characteristic tables. The JK toggles on J=K=1 (0→1 then 1→0) and the T flip-flop output is clk/2 when T is held high.
