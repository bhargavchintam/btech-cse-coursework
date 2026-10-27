# Unit 4 — Logic Gates

## The gates

| Gate | Expression | Note |
|---|---|---|
| AND | Y = A·B | 1 only if all inputs 1 |
| OR | Y = A+B | 0 only if all inputs 0 |
| NOT | Y = A' | inverter |
| NAND | Y = (A·B)' | AND then invert |
| NOR | Y = (A+B)' | OR then invert |
| XOR | Y = A⊕B = A'B + AB' | 1 when inputs differ |
| XNOR | Y = (A⊕B)' | 1 when inputs equal |

## Universal gates
NAND and NOR are **universal** — any function can be built from either alone.

Using NAND:
- NOT: tie both inputs together, A NAND A = A'
- AND: (A NAND B) NAND (A NAND B) — i.e. NAND then invert
- OR: (A NAND A) NAND (B NAND B) — invert both, then NAND (DeMorgan)

NOR realizations are the dual (swap the roles).

> If they ask "why universal", the answer is DeMorgan: NAND = OR of complements, NOR = AND of complements.

## XOR properties
A⊕0 = A, A⊕1 = A', A⊕A = 0, A⊕A' = 1. XOR of an odd number of 1s = 1 → this is exactly a parity function.

## Positive vs negative logic
Positive logic: HIGH = 1. Negative logic: LOW = 1. A positive-logic AND is a negative-logic OR — same hardware, different convention.

## Solved

**1. Realize Y = AB using only NOR gates.** AB = ((AB)')' = (A'+B')' → invert A and B with NORs, then NOR them: Y = (A' NOR B')... using AND = NOR of the inverted inputs' NOR. Two inverters + one NOR of the complements gives AB.

**2. How many 2-input NAND gates for a 3-input AND?** A·B·C = (AB)·C → NAND(A,B)→invert→NAND with C→invert. **3 NANDs + 2 as inverters** (a compact answer: AND-AND then a shared inverter).
