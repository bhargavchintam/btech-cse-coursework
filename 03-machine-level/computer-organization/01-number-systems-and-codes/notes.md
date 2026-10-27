# Unit 1 — Number Systems and Codes

## Positional number systems

A number in base r is a string of digits where each position carries a weight
that is a power of r. The digit set runs from 0 to r-1.

    (d3 d2 d1 d0 . f1 f2)r  =  d3·r³ + d2·r² + d1·r¹ + d0·r⁰ + f1·r⁻¹ + f2·r⁻²

Bases we use: decimal (r=10), binary (r=2), octal (r=8), hexadecimal (r=16).
Hex digits above 9 are A=10, B=11, C=12, D=13, E=14, F=15. Octal and hex exist
because they pack binary neatly — one octal digit = 3 bits, one hex digit = 4 bits.

## Decimal to binary / octal / hex — repeated division

Divide by the target base, collect remainders, read them bottom to top.

Convert 156 to binary:

| division | quotient | remainder |
|----------|----------|-----------|
| 156 / 2  | 78       | 0         |
| 78 / 2   | 39       | 0         |
| 39 / 2   | 19       | 1         |
| 19 / 2   | 9        | 1         |
| 9 / 2    | 4        | 1         |
| 4 / 2    | 2        | 0         |
| 2 / 2    | 1        | 0         |
| 1 / 2    | 0        | 1         |

Reading up: 156 = 10011100₂. Same number by 8 and 16: 156/8 = 19 r 4, 19/8 = 2 r 3,
2/8 = 0 r 2 gives 234₈. 156/16 = 9 r 12(C), 9/16 = 0 r 9 gives 9C₁₆.

Going back is just weights: 101101₂ = 32+8+4+1 = 45. 745₈ = 7·64 + 4·8 + 5 = 485.
2F9₁₆ = 2·256 + 15·16 + 9 = 761.

## Fractional binary — repeated multiplication

For the part after the point, multiply by 2 and pull out the integer bit each time.
Convert 13.6875 to binary. Integer part: 13 = 1101₂. Fraction part:

| step       | result | bit |
|------------|--------|-----|
| 0.6875 × 2 | 1.375  | 1   |
| 0.375 × 2  | 0.75   | 0   |
| 0.75 × 2   | 1.5    | 1   |
| 0.5 × 2    | 1.0    | 1   |

Bits read top to bottom this time. So 13.6875 = 1101.1011₂.
Check: 8+4+1 + 0.5+0.125+0.0625 = 13.6875. Some fractions (0.1 decimal) never
terminate — that is why floats are approximate.

## Signed number representations

Three schemes for an n-bit signed number. Positive numbers look identical in all three.

- Sign-magnitude: MSB is the sign, rest is the plain magnitude.
- 1's complement: negate by flipping every bit.
- 2's complement: negate by flipping every bit and adding 1.

Example, -5 in 4 bits (+5 = 0101):

| form           | bits | how                |
|----------------|------|--------------------|
| sign-magnitude | 1101 | sign 1, mag 101    |
| 1's complement | 1010 | flip 0101          |
| 2's complement | 1011 | flip 0101, add 1   |

And -23 in 8 bits (+23 = 00010111): sign-magnitude 10010111,
1's complement 11101000, 2's complement 11101001.

Range table:

| n | sign-magnitude | 1's complement | 2's complement |
|---|----------------|----------------|----------------|
| 4 | -7 to +7       | -7 to +7       | -8 to +7       |
| 8 | -127 to +127   | -127 to +127   | -128 to +127   |

Sign-magnitude and 1's complement both waste a code on -0, so they cover one
value less on the negative side. 2's complement has a single zero and one extra
negative number. That, plus the fact that plain binary addition just works, is
why every real machine uses 2's complement.

> Sir kept asking this: why is the 2's complement range asymmetric? Because 0
> eats one of the non-negative codes. -(-8) does not exist in 4 bits.

## Subtraction via 2's complement

A - B = A + (2's complement of B). Add, then look at the carry out of the MSB.
Carry 1: result is positive (or zero), throw the carry away. Carry 0: result is
negative and is sitting in 2's complement form.

45 - 23 in 8 bits:

```
    00101101      45
  + 11101001      2's complement of 23
  ----------
  1 00010110      carry 1 -> discard, answer = 00010110 = +22
```

23 - 45 in 8 bits: 00010111 + 11010011 (2's comp of 45) = 11101010 with carry 0.
No carry, so the answer is negative: 2's complement of 11101010 is 00010110 = 22,
so the result is -22. Correct.

## BCD — binary coded decimal

Each decimal digit is coded separately in 4 bits: 39 = 0011 1001. Only codes
0000–1001 are legal; 1010 to 1111 (six codes) are never used.

BCD addition needs a correction because 4 bits count to 15 but a decimal digit
wraps at 9. If a digit sum exceeds 9 (or produces a carry), add 6 to skip over
the six illegal codes.

5 + 6 in BCD:

```
    0101      5
  + 0110      6
  ------
    1011      = 11, illegal code (> 9)
  + 0110      add 6 correction
  ------
  1 0001      carry 1 into the next digit
```

Result: 0001 0001 = 11 in BCD. Without the +6 you would be stuck on the illegal
code 1011 and no decimal carry would be generated.

## Excess-3

Add 3 to the digit, then code in binary: code(d) = d + 3.

| digit | XS-3 | digit | XS-3 |
|-------|------|-------|------|
| 0     | 0011 | 5     | 1000 |
| 1     | 0100 | 6     | 1001 |
| 2     | 0101 | 7     | 1010 |
| 3     | 0110 | 8     | 1011 |
| 4     | 0111 | 9     | 1100 |

It is self-complementing: flipping all bits of code(d) gives code(9-d).
Check: code(2) = 0101, flipped = 1010 = code(7). Handy for 9's complement
subtraction in old decimal machines.

## Gray code

A code where consecutive values differ in exactly one bit.

Binary to Gray: copy the MSB, then each Gray bit = XOR of adjacent binary bits.
g(i) = b(i) XOR b(i+1). For 1011: g3=1, g2=1⊕0=1, g1=0⊕1=1, g0=1⊕1=0, so
1011₂ → 1110 Gray.

Gray to binary: copy the MSB, then each binary bit = previous binary bit XOR
current Gray bit. For Gray 1110: b3=1, b2=1⊕1=0, b1=0⊕1=1, b0=1⊕0=1 → 1011. Back
where we started.

| dec | binary | gray |
|-----|--------|------|
| 0   | 000    | 000  |
| 1   | 001    | 001  |
| 2   | 010    | 011  |
| 3   | 011    | 010  |
| 4   | 100    | 110  |
| 5   | 101    | 111  |
| 6   | 110    | 101  |
| 7   | 111    | 100  |

Why it matters: going 7 → 8 in binary is 0111 → 1000, four bits flip. If a shaft
encoder's sensors are slightly misaligned you can momentarily read garbage like
1111. In Gray (0100 → 1100) only one bit ever changes, so the worst wrong reading
is off by one position.

## ASCII

7-bit code, 128 characters. The ones worth memorising:
'0'–'9' are 48–57 (0x30–0x39), 'A'–'Z' are 65–90 (0x41–0x5A), 'a'–'z' are
97–122 (0x61–0x7A). Lowercase = uppercase + 32, which is one bit (0x20), so case
conversion is a single bit flip. Digit to value is c - '0'.

## Parity

Append one bit so the total count of 1s is even (even parity) or odd (odd parity).
Data 1011001 has four 1s, so even parity bit = 0, odd parity bit = 1. A single
flipped bit breaks the parity and is detected — but you cannot tell which bit,
and two flips cancel out and pass. Detection only, no correction.

## Hamming SEC code (7,4)

7 bits carry 4 data bits and 3 parity bits. Parity bits sit at positions 1, 2, 4
(the powers of two). Each parity bit covers the positions whose binary index
contains that power: p1 covers 1,3,5,7; p2 covers 2,3,6,7; p4 covers 4,5,6,7.
Even parity over each group. 3 check bits give 8 syndromes: 000 for no error
plus one for each of the 7 positions.

Encode data 1011 (d1=1, d2=0, d3=1, d4=1):

- p1 = d1 ⊕ d2 ⊕ d4 = 1⊕0⊕1 = 0
- p2 = d1 ⊕ d3 ⊕ d4 = 1⊕1⊕1 = 1
- p4 = d2 ⊕ d3 ⊕ d4 = 0⊕1⊕1 = 0

| position | 1  | 2  | 3  | 4  | 5  | 6  | 7  |
|----------|----|----|----|----|----|----|----|
| name     | p1 | p2 | d1 | p4 | d2 | d3 | d4 |
| bit      | 0  | 1  | 1  | 0  | 0  | 1  | 1  |

Codeword transmitted: 0110011.

Now flip position 5 in transit — received 0110111. Recompute each parity check
over the received bits (s = 1 means that group has odd parity, i.e. failed):

| check | positions | received bits | s |
|-------|-----------|---------------|---|
| s1    | 1,3,5,7   | 0 1 1 1       | 1 |
| s2    | 2,3,6,7   | 1 1 1 1       | 0 |
| s4    | 4,5,6,7   | 0 1 1 1       | 1 |

Syndrome s4 s2 s1 = 101₂ = 5. The syndrome literally spells out the bad position.
Flip bit 5 back: 0110011, extract positions 3,5,6,7 → data 1011 recovered.

Remember: write the syndrome as s4 s2 s1, NOT s1 s2 s4 — got this backwards once
in a tutorial sheet and located the wrong bit.

## Solved numericals

**Q1.** Convert 429 to binary, octal and hexadecimal.

429/2 = 214 r 1, 214/2 = 107 r 0, 107/2 = 53 r 1, 53/2 = 26 r 1, 26/2 = 13 r 0,
13/2 = 6 r 1, 6/2 = 3 r 0, 3/2 = 1 r 1, 1/2 = 0 r 1. Reading up: 110101101₂.
Octal: 429/8 = 53 r 5, 53/8 = 6 r 5, 6/8 = 0 r 6 → 655₈.
Hex: 429/16 = 26 r 13(D), 26/16 = 1 r 10(A), 1/16 = 0 r 1 → 1AD₁₆.

**Ans:** 429 = 110101101₂ = 655₈ = 1AD₁₆

**Q2.** Perform 23 - 45 using 8-bit 2's complement arithmetic.

23 = 00010111. 45 = 00101101, its 2's complement = 11010011.
00010111 + 11010011 = 11101010, carry out = 0. No carry means negative result:
2's complement of 11101010 = 00010110 = 22, so the answer is -22.

**Ans:** 11101010₂ = -22

**Q3.** Add 27 and 48 in BCD.

27 = 0010 0111, 48 = 0100 1000.
Units digit: 0111 + 1000 = 1111 (15, illegal) → add 0110 → 1 0101, digit 0101,
carry 1 to the tens.
Tens digit: 0010 + 0100 + 1 = 0111 (7, legal, no correction).

**Ans:** 0111 0101 in BCD = 75
