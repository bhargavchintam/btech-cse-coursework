# Unit 1 — Number Systems

## Positional number systems
A number in base r uses digits 0 .. r-1. The value is the weighted sum of digits, weight = r^position.

| System | Base | Digits |
|---|---|---|
| Binary | 2 | 0 1 |
| Octal | 8 | 0–7 |
| Decimal | 10 | 0–9 |
| Hexadecimal | 16 | 0–9, A–F |

## Conversions

**Any base → decimal:** multiply each digit by its weight and add.
(1101.101)₂ = 8+4+0+1 + 0.5+0+0.125 = **13.625**
(347)₈ = 3·64 + 4·8 + 7 = **231**
(2AF.C)₁₆ = 2·256 + 10·16 + 15 + 12/16 = **687.75**

**Decimal → any base:** integer part by repeated division (read remainders bottom-up); fractional part by repeated multiplication (read the carries top-down).

**Binary ↔ octal / hex:** group binary bits in 3s (octal) or 4s (hex) from the binary point.
1 011 010 = (132)₈ ,  0101 1010 = (5A)₁₆

## Signed numbers
Three schemes for an n-bit signed number: sign-magnitude, 1's complement, 2's complement. MSB is the sign bit.

- **1's complement:** invert all bits.
- **2's complement:** 1's complement + 1. This is the one used in practice — one representation of zero, and subtraction becomes addition.

## Complement subtraction
A − B = A + (2's complement of B); ignore the final carry if it appears (result is positive).

> Subtraction by 2's complement is the whole reason computers don't need a separate subtractor.

## r's and (r-1)'s complement (decimal)
9's complement of 456 = 999 − 456 = **543**. 10's complement = 543 + 1 = **544**.

## Solved

**1. (10110)₂ to decimal.** 16+0+4+2+0 = **22**.

**2. 13 − 6 using 5-bit 2's complement.**
13 = 01101, 6 = 00110. 2's comp of 6 = 11010.
01101 + 11010 = 1 00111. Drop the carry → **00111 = 7**. ✔

**3. (0.6875)₁₀ to binary.** 0.6875×2=1.375→1, 0.375×2=0.75→0, 0.75×2=1.5→1, 0.5×2=1.0→1.
**Ans:** 0.1011
