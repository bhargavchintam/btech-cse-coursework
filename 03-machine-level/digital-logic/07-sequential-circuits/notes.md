# Unit 7 — Sequential Circuits

Output depends on present inputs **and** past state. Needs memory (flip-flops) and usually a clock.

## Latch vs flip-flop
- **Latch:** level-triggered (transparent while the enable is active).
- **Flip-flop:** edge-triggered (state changes only on the clock edge). Edge triggering avoids the transparency problem.

## The four flip-flops

**SR:** S=1 sets, R=1 resets, 00 holds, **11 is invalid**.
**D:** Q follows D on the edge. Q(next) = D. No invalid state — a gated SR with S=D, R=D'.
**JK:** like SR but 11 **toggles**. Q(next) = JQ' + K'Q.
**T:** T=1 toggles, T=0 holds. Q(next) = T⊕Q.

## Characteristic tables (Q⁺ = next state)

| FF | inputs | Q⁺ |
|---|---|---|
| SR | 00 / 01 / 10 / 11 | Q / 0 / 1 / — |
| JK | 00 / 01 / 10 / 11 | Q / 0 / 1 / Q' |
| D | 0 / 1 | 0 / 1 |
| T | 0 / 1 | Q / Q' |

## Excitation tables (what input gives a required Q→Q⁺)

| Q→Q⁺ | SR | JK | D | T |
|---|---|---|---|---|
| 0→0 | 0× | 0× | 0 | 0 |
| 0→1 | 10 | 1× | 1 | 1 |
| 1→0 | 01 | ×1 | 0 | 1 |
| 1→1 | ×0 | ×0 | 1 | 0 |

## Race-around & master-slave
In a level-triggered JK with J=K=1, the output can toggle many times while the clock is high (race-around). Fix: **master-slave** (two latches in series) or edge triggering, so exactly one toggle per clock.

## Flip-flop conversion
Put the required FF's characteristic table beside the available FF's excitation table, then derive the input logic (K-map). e.g. JK→D: D = JQ' + K'Q.

## Solved
**1. Characteristic equation of JK.** Q⁺ = JQ' + K'Q.
**2. Convert D to T.** D = T⊕Q.
