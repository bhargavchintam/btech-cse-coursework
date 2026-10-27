# Unit 9 — Memory and Programmable Logic

## Memory terms
- **RAM** — read/write, **volatile** (loses data on power-off). Static RAM = flip-flops (fast); Dynamic RAM = capacitors, needs refresh (dense, cheap).
- **ROM** — read-only, **non-volatile**. Types: mask ROM, PROM, EPROM, EEPROM.
- Capacity = words × bits. A 1K×8 memory has 1024 locations of 8 bits, so 10 address lines and 8 data lines.

## ROM for combinational logic
A ROM stores a truth table: address = inputs, stored word = outputs. So any set of combinational functions of n inputs = a 2ⁿ-word ROM. Internally it's a fixed decoder (all minterms) + a programmable OR array.

## Programmable logic devices

| Device | AND array | OR array |
|---|---|---|
| **PROM** | fixed (all minterms) | programmable |
| **PLA** | programmable | programmable |
| **PAL** | programmable | fixed |

- **PLA** is the most flexible — you program which product terms exist and where they go, so you implement the minimized SOP directly (shared terms save gates).
- **PAL** is cheaper/faster to program (only the AND array), the usual practical choice.

## Solved
**1. Address & data lines for 4K×8 ROM.** 4K = 4096 = 2¹² → **12 address lines, 8 data lines.**
**2. Implement F1=Σm(0,1,3), F2=Σm(1,2,3) of two vars with a PLA.** Share the product terms (A'B', A'B, AB) across both OR outputs.
