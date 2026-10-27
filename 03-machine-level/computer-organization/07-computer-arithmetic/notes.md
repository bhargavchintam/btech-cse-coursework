# Unit 7 — Computer Arithmetic

## Fixed point addition, subtraction and overflow

Signed integers are stored in 2's complement. With n bits the range is
-2^(n-1) to 2^(n-1) - 1, so 4 bits hold -8 to +7.

Addition is plain binary addition; any carry out of the MSB is thrown away.
Subtraction A - B is done as A + (2's complement of B) on the same adder,
so one adder does both jobs.

Overflow can only happen when both operands have the same sign. The rule the
hardware actually uses:

    overflow = (carry INTO the sign bit) XOR (carry OUT of the sign bit)

If the two carries agree, the answer is fine. A carry out of the MSB by
itself means nothing — it just gets discarded.

4-bit examples:

| sum       | binary             | carry into/out of sign | result | verdict  |
|-----------|--------------------|------------------------|--------|----------|
| 5 + 6     | 0101 + 0110 = 1011 | in 1, out 0            | -5     | overflow |
| -5 + (-6) | 1011 + 1010 = 0101 | in 0, out 1            | +5     | overflow |
| -3 + (-2) | 1101 + 1110 = 1011 | in 1, out 1            | -5     | correct  |
| 5 + (-3)  | 0101 + 1101 = 0010 | in 1, out 1            | +2     | correct  |

The last row produced a carry out but no overflow — discard the carry, keep
the answer. Opposite-sign operands can never overflow.

## Booth's multiplication algorithm

Plain shift-and-add needs one addition for every 1 in the multiplier. Booth's
observation: a run of 1s from bit j up to bit k is worth 2^(k+1) - 2^j.
Example: 01110 = 14 = 16 - 2 = 2^4 - 2^1. So instead of adding M three times,
subtract M×2^1 where the run begins and add M×2^4 where it ends — two
operations no matter how long the run is.

The real payoff: a negative multiplier in 2's complement ends in a run of 1s
that never terminates, so the closing addition simply never happens. Booth
multiplies by negative Q with no special case at all.

The recoding looks at the current multiplier bit Q0 and the bit that just
fell off, Q-1 (starts at 0):

| Q0 | Q-1 | means                | action                 |
|----|-----|----------------------|------------------------|
| 0  | 0   | inside a run of 0s   | shift only             |
| 1  | 0   | start of a run of 1s | A = A - M, then shift  |
| 1  | 1   | inside a run of 1s   | shift only             |
| 0  | 1   | end of a run of 1s   | A = A + M, then shift  |

Setup: A = 0 (n bits), Q = multiplier, Q-1 = 0, M = multiplicand. Run n
cycles. Every cycle ends with an ARITHMETIC right shift of the combined
A, Q, Q-1 — the sign bit of A is copied in, not a zero. Answer is A:Q,
2n bits.

Worked: 7 × (-3) in 4 bits. M = 0111, -M = 1001, Q = -3 = 1101.

| step | A    | Q    | Q-1 | operation               |
|------|------|------|-----|-------------------------|
| 0    | 0000 | 1101 | 0   | initial values          |
| 1    | 1001 | 1101 | 0   | Q0 Q-1 = 10 : A = A - M |
|      | 1100 | 1110 | 1   | ASR(A, Q, Q-1)          |
| 2    | 0011 | 1110 | 1   | Q0 Q-1 = 01 : A = A + M |
|      | 0001 | 1111 | 0   | ASR                     |
| 3    | 1010 | 1111 | 0   | Q0 Q-1 = 10 : A = A - M |
|      | 1101 | 0111 | 1   | ASR                     |
| 4    | 1110 | 1011 | 1   | Q0 Q-1 = 11 : shift only|

Product = A:Q = 1110 1011 = -21. Correct.

> One trap sir pointed out: with 4-bit registers the multiplicand -8 breaks
> Booth, because -(-8) = +8 does not fit in 4 bits. Multiplier -8 is fine.

## Restoring division

Unsigned division, the way you do long division by hand: try to subtract the
divisor, and if it doesn't go, put it back.

Setup: A = 0 with n+1 bits (the extra bit is so we can see the sign of A - M),
Q = dividend (n bits), M = divisor. Repeat n times:

1. Shift A:Q left by 1.
2. A = A - M.
3. If A < 0: restore A = A + M and set Q0 = 0. Else keep A, set Q0 = 1.

Quotient ends up in Q, remainder in A.

Worked: 7 ÷ 3, n = 4. Q = 0111, M = 00011.

| step | A     | Q    | operation                |
|------|-------|------|--------------------------|
| 0    | 00000 | 0111 | initial values           |
| 1    | 00000 | 1110 | shift left AQ            |
|      | 11101 | 1110 | A = A - M                |
|      | 00000 | 1110 | A < 0 : restore, Q0 = 0  |
| 2    | 00001 | 1100 | shift left AQ            |
|      | 11110 | 1100 | A = A - M                |
|      | 00001 | 1100 | A < 0 : restore, Q0 = 0  |
| 3    | 00011 | 1000 | shift left AQ            |
|      | 00000 | 1000 | A = A - M                |
|      | 00000 | 1001 | A >= 0 : keep, Q0 = 1    |
| 4    | 00001 | 0010 | shift left AQ            |
|      | 11110 | 0010 | A = A - M                |
|      | 00001 | 0010 | A < 0 : restore, Q0 = 0  |

Q = 0010 = 2, R = 00001 = 1. Check: 3 × 2 + 1 = 7.

## Non-restoring division

The restore step wastes an addition. Non-restoring skips it: if A went
negative, leave it negative, and in the NEXT cycle add M after the shift
instead of subtracting. The algebra: restoring would compute 2(A + M) - M
= 2A + M, which is exactly shift-then-add — same value, one operation per
cycle instead of two.

Per cycle: if A >= 0, shift left AQ then A = A - M; if A < 0, shift left AQ
then A = A + M. Then Q0 = 1 if A >= 0 else 0. After the last cycle, if A is
still negative, one final fix-up: A = A + M.

Worked: 7 ÷ 3 again. Q = 0111, M = 00011.

| step | A     | Q    | operation                        |
|------|-------|------|----------------------------------|
| 0    | 00000 | 0111 | initial values                   |
| 1    | 00000 | 1110 | A >= 0 : shift left AQ           |
|      | 11101 | 1110 | A = A - M ; A < 0 so Q0 = 0      |
| 2    | 11011 | 1100 | A < 0 : shift left AQ            |
|      | 11110 | 1100 | A = A + M ; A < 0 so Q0 = 0      |
| 3    | 11101 | 1000 | A < 0 : shift left AQ            |
|      | 00000 | 1001 | A = A + M ; A >= 0 so Q0 = 1     |
| 4    | 00001 | 0010 | A >= 0 : shift left AQ           |
|      | 11110 | 0010 | A = A - M ; A < 0 so Q0 = 0      |
| end  | 00001 | 0010 | A < 0 : A = A + M, final restore |

Q = 0010 = 2, R = 00001 = 1. Same answer, but count the add/subtracts:
restoring did 7 (4 subtracts + 3 restores), non-restoring did 5 (4 + 1 final
fix). Worst case restoring is 2n operations, non-restoring is n + 1.

## IEEE 754 floating point

Single precision, 32 bits:

    | s |  exponent  |        fraction        |
    | 1 |     8      |           23           |

    value = (-1)^s × 1.fraction × 2^(E - 127)

The exponent is stored with a BIAS of 127: stored E = real exponent + 127.
A normalised mantissa always looks like 1.xxxx, so the leading 1 is not
stored (hidden bit) — 23 stored bits give 24 bits of precision.

> Bias is 127, not 128. Sir repeated it three times before IA2 — exam trap.

Converting -12.625 to its bit pattern:

1. Negative, so s = 1.
2. 12 = 1100, 0.625 = 0.5 + 0.125 = 0.101, so 12.625 = 1100.101.
3. Normalise: 1100.101 = 1.100101 × 2^3.
4. Stored exponent = 3 + 127 = 130 = 10000010.
5. Fraction = 100101 padded right to 23 bits: 10010100000000000000000.
6. Assemble and regroup in 4s:
   1 10000010 10010100000000000000000
   = 1100 0001 0100 1010 0000 0000 0000 0000 = **C14A0000**.

Exponent field all 0s or all 1s is reserved for the special values:

| E field  | fraction | meaning                                      |
|----------|----------|----------------------------------------------|
| 00000000 | 0        | ±0 (sign bit survives, so +0 and -0 exist)   |
| 00000000 | ≠ 0      | denormal: 0.fraction × 2^-126, no hidden 1   |
| 11111111 | 0        | ±infinity                                    |
| 11111111 | ≠ 0      | NaN                                          |

Ranges: smallest denormal 2^-149 ≈ 1.4 × 10^-45, smallest normal
2^-126 ≈ 1.18 × 10^-38, largest (2 - 2^-23) × 2^127 ≈ 3.4 × 10^38.

Double precision is the same idea, wider: 1 sign, 11 exponent, 52 fraction,
bias 1023, value = (-1)^s × 1.fraction × 2^(E - 1023).

Not every decimal terminates in binary: 0.1 stored as a float is actually
0.100000001490116119384765625. This is why comparing floats with == was a
bad idea in first year C, and now I know exactly why.

## Floating point addition

Four steps, always in this order:

1. Align: compare exponents, shift the mantissa of the SMALLER one right by
   the difference (its exponent goes up to match).
2. Add (or subtract) the mantissas.
3. Normalise: if the sum is ≥ 2, shift right once and bump the exponent; if
   it is < 1 (can happen after subtraction), shift left and drop the exponent.
4. Round back to 23 fraction bits (hardware keeps guard, round and sticky
   bits during the shift so rounding is still correct).

Example: 2.5 + 4.75. 2.5 = 1.01 × 2^1 and 4.75 = 1.0011 × 2^2.
Align: 1.01 × 2^1 → 0.101 × 2^2. Add: 0.1010 + 1.0011 = 1.1101, so the sum
is 1.1101 × 2^2 = 111.01 = 7.25. Already normalised, nothing to round.

Normalisation case: 1.75 + 1.75 = 1.11 + 1.11 = 11.10 × 2^0 → shift right →
1.110 × 2^1 = 3.5.

## Solved numericals

**Q1.** Multiply -5 by -3 using Booth's algorithm (4 bits).

M = -5 = 1011, -M = 0101, Q = -3 = 1101.

| step | A    | Q    | Q-1 | operation               |
|------|------|------|-----|-------------------------|
| 0    | 0000 | 1101 | 0   | initial values          |
| 1    | 0101 | 1101 | 0   | Q0 Q-1 = 10 : A = A - M |
|      | 0010 | 1110 | 1   | ASR                     |
| 2    | 1101 | 1110 | 1   | Q0 Q-1 = 01 : A = A + M |
|      | 1110 | 1111 | 0   | ASR                     |
| 3    | 0011 | 1111 | 0   | Q0 Q-1 = 10 : A = A - M |
|      | 0001 | 1111 | 1   | ASR                     |
| 4    | 0000 | 1111 | 1   | Q0 Q-1 = 11 : shift only|

**Ans:** A:Q = 0000 1111 = +15. Negative × negative came out positive with
no sign fix-up anywhere — that is Booth working as designed.

**Q2.** Divide 13 by 4 with restoring division (4 bits).

Q = 1101, M = 00100.

| step | A     | Q    | operation               |
|------|-------|------|-------------------------|
| 0    | 00000 | 1101 | initial values          |
| 1    | 00001 | 1010 | shift left AQ           |
|      | 11101 | 1010 | A = A - M               |
|      | 00001 | 1010 | A < 0 : restore, Q0 = 0 |
| 2    | 00011 | 0100 | shift left AQ           |
|      | 11111 | 0100 | A = A - M               |
|      | 00011 | 0100 | A < 0 : restore, Q0 = 0 |
| 3    | 00110 | 1000 | shift left AQ           |
|      | 00010 | 1000 | A = A - M               |
|      | 00010 | 1001 | A >= 0 : keep, Q0 = 1   |
| 4    | 00101 | 0010 | shift left AQ           |
|      | 00001 | 0010 | A = A - M               |
|      | 00001 | 0011 | A >= 0 : keep, Q0 = 1   |

**Ans:** Q = 0011 = 3, R = 00001 = 1. Check: 4 × 3 + 1 = 13.

**Q3.** (a) Convert 9.6875 to IEEE 754 single precision.
(b) What decimal value is 0x41C80000?

(a) 9 = 1001, 0.6875 = 0.5 + 0.125 + 0.0625 = 0.1011, so 9.6875 = 1001.1011
= 1.0011011 × 2^3. s = 0, E = 3 + 127 = 130 = 10000010, fraction =
0011011 padded to 23 bits.
0 10000010 00110110000000000000000 = 0100 0001 0001 1011 0000 ... 0000
**Ans:** 0x411B0000.

(b) 0x41C80000 = 0100 0001 1100 1000 0000 0000 0000 0000.
s = 0, E = 10000011 = 131, real exponent = 131 - 127 = 4, fraction = 1001...
Value = +1.1001 × 2^4 = 11001.0 = **Ans:** 25.0.
