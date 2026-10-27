# Experiment 8 — Counters

**Date:** 31/10/2018

## Aim
To design and simulate a 4-bit up/down counter with a mode input and a mod-10 (decade) counter, and verify their count sequences.

## Tools
ModelSim / Xilinx ISE in the lab. Simulated again at home with Icarus Verilog.

## Theory
A synchronous counter is a register whose next value is computed from the present value —
all flip-flops share one clock, so there is no ripple delay between stages. An up/down
counter adds a mode control: the same register either increments or decrements each edge.
Since the register is 4 bits wide, arithmetic is modulo 16 — counting down past 0000 wraps
to 1111. A mod-10 counter cuts the natural sequence short: when the count reaches 9 the
next edge forces it back to 0 instead of going to 10. Decade counters like this are what
digital clocks and frequency dividers by 10 are built from (7490 IC).

## Design
Up/down: one 4-bit register; mode = 1 → count+1, mode = 0 → count−1, on every rising edge.
Mod-10: same register, but if count == 1001 the next state is forced to 0000, else count+1.
Both have asynchronous reset to 0000.

## Code
- `up_down_counter.v` / `up_down_counter_tb.v` — counts up 6 clocks, then down through 0 to show the wrap to 15
- `mod10_counter.v` / `mod10_counter_tb.v` — 12 clocks, enough to see 9 → 0 and continue

## Observations
Up/down counter:
```
clk# mode count  dec
  1   1   0001   1
  2   1   0010   2
  3   1   0011   3
  4   1   0100   4
  5   1   0101   5
  6   1   0110   6
  7   0   0101   5
  8   0   0100   4
  9   0   0011   3
 10   0   0010   2
 11   0   0001   1
 12   0   0000   0
 13   0   1111  15
 14   0   1110  14
up_down_counter_tb.v:25: $finish called at 146 (1s)
```

Mod-10 counter:
```
clk# count  dec
  0   0000    0
  1   0001    1
  2   0010    2
  3   0011    3
  4   0100    4
  5   0101    5
  6   0110    6
  7   0111    7
  8   1000    8
  9   1001    9
 10   0000    0
 11   0001    1
 12   0010    2
mod10_counter_tb.v:20: $finish called at 126 (1s)
```

## Result
The up/down counter counts correctly in both modes and wraps 0 → 15 going down. The decade counter counts 0 to 9 and returns to 0 on the tenth clock.
