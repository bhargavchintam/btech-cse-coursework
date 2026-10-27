# Unit 8 — Registers and Counters

## Registers
A register is a group of flip-flops storing a word. A buffer register just holds it; a shift register moves it.

## Shift registers
Data moves one position per clock. Four types by how data enters/leaves:
- **SISO** — serial in, serial out
- **SIPO** — serial in, parallel out
- **PISO** — parallel in, serial out
- **PIPO** — parallel in, parallel out

A **universal shift register** does all of these plus left/right, controlled by mode select lines (e.g. 74194/7495).

## Counters
- **Asynchronous (ripple):** each FF clocked by the previous FF's output. Simple, but the delays add up so it's slow.
- **Synchronous:** all FFs share the same clock, decode logic decides which toggle. Faster, no ripple delay.

## Mod-N counter
Counts N states (0 … N−1) then resets. A mod-N counter needs ⌈log₂N⌉ flip-flops. A decade (mod-10) counter uses 4 FFs and resets at count 1010.

## Ring and Johnson counters
- **Ring:** a single 1 circulates. 4 bits → 4 states: 1000→0100→0010→0001→…
- **Johnson (twisted ring):** feed back the **inverted** last bit. 4 bits → **8 states**: 0000→1000→1100→1110→1111→0111→0011→0001→0000.

A Johnson counter gives 2n states from n flip-flops — twice a ring counter.

## Counter design steps
State diagram → state table → pick a flip-flop → excitation table → K-map for each FF input → circuit.

## Solved
**1. Flip-flops for a mod-12 counter?** 2³=8 < 12 ≤ 16 = 2⁴ → **4 flip-flops.**
**2. Ring counter states with 4 FFs?** 4. Johnson with 4 FFs? 8.
