# Unit 2 — Binary Codes

## Weighted vs non-weighted
- **Weighted:** each bit position has a fixed weight. BCD (8421), 2421.
- **Non-weighted:** no positional weight. Excess-3, Gray.

## BCD (8421)
Each decimal digit is coded by its own 4 bits. 69 → **0110 1001**. Wastes the six combinations 1010–1111 (invalid BCD). Note this is NOT the same as the pure binary of the whole number (69 = 1000101₂).

## Excess-3
Add 3 to the digit, then take 4-bit binary. Excess-3 of 5 = 5+3 = 8 = **1000**. It is a self-complementing code, which is why it was used in old adders.

## Gray code
Only **one bit changes** between successive values — reflected/unit-distance code. Used in shaft encoders and K-maps so a single-step change can't produce a spurious reading.

Binary → Gray: MSB same; each next Gray bit = XOR of two adjacent binary bits.
1010₂ → G = 1, 1⊕0=1, 0⊕1=1, 1⊕0=1 → **1111**
Gray → Binary: MSB same; each next binary bit = previous binary bit XOR current Gray bit.

## ASCII
7-bit code for characters. 'A' = 65 = 100 0001, '0' = 48. Not examinable in depth but know it's 7-bit.

## Error detection — parity
Add one **parity bit** so the total number of 1s is even (even parity) or odd (odd parity). Detects any single-bit error. Cannot correct, and misses even-number errors.

## Solved

**1. Convert (1001)₂ BCD-add check.** 1001 = 9, valid BCD digit.

**2. Even parity for 1011001.** Number of 1s = 4 (even) → parity bit = **0**, transmitted word 1011001**0**.

**3. Gray code of decimal 6.** 6 = 0110₂ → 0, 0⊕1=1, 1⊕1=0, 1⊕0=1 → **0101**.
