# Unit 3 — Combinational Circuits

Output depends only on the present inputs — no memory, no clock. Adders and
subtractors first, then the routing blocks (mux, demux, decoder, encoder),
then comparators and the BCD display driver.

## Half adder

Adds two bits. Two outputs because 1+1 = 10 needs two bits.

| A | B | S | C |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 0 |
| 1 | 0 | 1 | 0 |
| 1 | 1 | 0 | 1 |

Straight off the table: S = A'B + AB' = **A ⊕ B**, C = **AB**. One XOR, one
AND. No carry input, so it cannot be chained — the full adder fixes that.

## Full adder

Three inputs (A, B, Cin), so 8 rows.

| A | B | Cin | S | Cout |
|---|---|-----|---|------|
| 0 | 0 | 0   | 0 | 0    |
| 0 | 0 | 1   | 1 | 0    |
| 0 | 1 | 0   | 1 | 0    |
| 0 | 1 | 1   | 0 | 1    |
| 1 | 0 | 0   | 1 | 0    |
| 1 | 0 | 1   | 0 | 1    |
| 1 | 1 | 0   | 0 | 1    |
| 1 | 1 | 1   | 1 | 1    |

S = 1 when an odd number of inputs are 1: **S = A ⊕ B ⊕ Cin**.
Cout = Σm(3,5,6,7) simplifies to **Cout = AB + BCin + ACin** (any two inputs
high). Factored as Cout = AB + Cin(A ⊕ B) it builds from two half adders:

```
a ---+------+  s1 = a^b  +------+
b ---+ HA1  |----------->+ HA2  |----> s = a^b^cin
     +------+     cin -->+------+
        |c1 = ab            |c2 = cin(a^b)
        +-------[ OR ]------+--------> cout
```

At most one of c1, c2 is ever 1, so the OR never loses information.

## Ripple carry adder

Chain n full adders, carry out of stage i into carry in of stage i+1.

```
     b3 a3     b2 a2     b1 a1     b0 a0
      |  |      |  |      |  |      |  |
cout<-[FA3]<-c3-[FA2]<-c2-[FA1]<-c1-[FA0]<- cin
        |         |         |         |
        s3        s2        s1        s0
```

The problem is delay: FA3 waits on c3, which waits on c2, which waits on c1.
Counting the carry path through one full adder as 2 gate delays (the AND–OR
making Cout), worst case is about **2n gate delays** — 8 for 4-bit, 32 for
16-bit. Linear in width, hopeless for a 32-bit ALU.

## Carry lookahead adder

Stop waiting for the carry to ripple — *compute* every carry directly. Per bit:

- **Pi = Ai ⊕ Bi** (propagate — the stage passes an incoming carry along)
- **Gi = Ai · Bi** (generate — the stage creates a carry no matter what)

Then Ci+1 = Gi + Pi·Ci. Substituting repeatedly, every carry depends only on
P, G and C0:

- C1 = G0 + P0C0
- C2 = G1 + P1G0 + P1P0C0
- C3 = G2 + P2G1 + P2P1G0 + P2P1P0C0
- C4 = G3 + P3G2 + P3P2G1 + P3P2P1G0 + P3P2P1P0C0

Each carry is a two-level AND–OR of the inputs. Total: 1 gate delay for all
P/G, 2 for the carries, 1 XOR for the sums = **4 gate delays, fixed** —
against 8 for a 4-bit ripple and 32 for 16-bit. The cost is gate count and
fan-in (C4 needs a 5-input OR), so wide adders use 4-bit CLA blocks with a
second lookahead level between blocks.

> Sir's one-liner: ripple trades time for hardware, lookahead trades hardware for time.

## Half and full subtractor

Half subtractor computes A − B: difference D, borrow Bout.

| A | B | D | Bout |
|---|---|---|------|
| 0 | 0 | 0 | 0    |
| 0 | 1 | 1 | 1    |
| 1 | 0 | 1 | 0    |
| 1 | 1 | 0 | 0    |

D = **A ⊕ B** (same as the adder sum), Bout = **A'B** (borrow only when
subtracting 1 from 0). Full subtractor adds a borrow-in:

| A | B | Bin | D | Bout |
|---|---|-----|---|------|
| 0 | 0 | 0   | 0 | 0    |
| 0 | 0 | 1   | 1 | 1    |
| 0 | 1 | 0   | 1 | 1    |
| 0 | 1 | 1   | 0 | 1    |
| 1 | 0 | 0   | 1 | 0    |
| 1 | 0 | 1   | 0 | 0    |
| 1 | 1 | 0   | 0 | 0    |
| 1 | 1 | 1   | 1 | 1    |

D = **A ⊕ B ⊕ Bin**, Bout = **A'B + Bin(A ⊕ B)'** (SOP: A'B + A'Bin + B·Bin).
Only the complemented A distinguishes it from the adder — and nobody builds
separate subtractor hardware anyway, see next section.

## Adder-subtractor (the XOR trick)

One 4-bit adder does both. Each Bi passes through an XOR whose other input is
the mode line M, and M also feeds Cin.

```
b3 b2 b1 b0          a[3:0]        M = 0: add
 |  |  |  |            |           M = 1: subtract
[X][X][X][X]<--- M     |
 |  |  |  |            |
 +--4-bit ripple adder-+
      cin <----- M
```

- M = 0: B ⊕ 0 = B, Cin = 0 → A + B.
- M = 1: B ⊕ 1 = B', Cin = 1 → A + B' + 1 = A + (2's comp of B) = A − B.

**Overflow (signed):** V = C3 ⊕ C4 — carry *into* the sign bit XOR carry
*out* of it. If they differ, the true result fell outside −8..+7. For
unsigned subtraction, Cout = 1 means no borrow (result valid).

Remember: discard the final carry in 2's complement subtraction — lost a mark on this in IA1.

## Multiplexer

2^n data inputs, n select lines, one output. A data switch.

- 2:1 — Y = **S'I0 + SI1**
- 4:1 — Y = **S1'S0'I0 + S1'S0·I1 + S1S0'I2 + S1S0·I3**

**Mux as universal logic:** a 2^n:1 mux implements any function of n+1
variables. Put n variables on the selects; for each select combination the
function collapses to 0, 1, C or C' in the last variable — wire that residue
to the data input. Numerical 2 does a full example. Standard exam question.

## Demultiplexer

The reverse: one input D, n selects, 2^n outputs, input routed to exactly one
output. For 1:4 — Y0 = S1'S0'D, Y1 = S1'S0·D, Y2 = S1S0'D, Y3 = S1S0·D.
A decoder with an enable pin *is* a demux: feed the data into the enable.

## Decoder

n inputs, 2^n outputs, exactly one output high — a minterm generator.

- 2:4 — Y0 = A1'A0', Y1 = A1'A0, Y2 = A1A0', Y3 = A1A0
- 3:8 — same idea, Yi = minterm i of A2A1A0 (all 8 verified in decoder3to8.v)

Since each output is one minterm, a decoder plus OR gates realises any set of
functions of the same inputs — this is how small ROMs and control units work.

## Encoder and priority encoder

Decoder reversed: 2^n inputs, n-bit code out. 4:2 — Y1 = D2 + D3,
Y0 = D1 + D3. Two problems: two inputs high gives garbage (D1 and D2 together
output 11, which claims D3), and all-zero looks the same as D0 alone.

The **priority encoder** fixes both — highest active input wins, valid bit V
flags "at least one input". For 4 inputs, D3 highest:

- Y1 = **D3 + D2**
- Y0 = **D3 + D2'D1**
- V = D3 + D2 + D1 + D0

## Magnitude comparator

1-bit: (A > B) = AB', (A < B) = A'B, (A = B) = A ⊙ B (XNOR).

2-bit (A = A1A0, B = B1B0), with x1 = A1 ⊙ B1 and x0 = A0 ⊙ B0:

- (A > B) = **A1B1' + x1·A0B0'** — win on the MSB, or tie it and win on the LSB
- (A = B) = **x1·x0**
- (A < B) = **A1'B1 + x1·A0'B0**

The pattern extends to any width: MSB first, each lower bit ANDed with "all
higher bits equal". The 7485 4-bit comparator cascades exactly this way.

## BCD to seven segment

Input BCD digit DCBA (D = 8), outputs a–g, one 4-variable function per
segment. Inputs 1010–1111 never occur → don't-cares, which is what makes the
K-maps collapse. Segment a is lit for 0,2,3,5,6,7,8,9 (off for 1 and 4):

```
          BA
        00  01  11  10
  DC 00  1   0   1   1
     01  0   1   1   1
     11  X   X   X   X
     10  1   1   X   X
```

Bottom rows via D, right columns via B, four corners C'A', centre square CA:

**a = D + B + CA + C'A'**

Check the zeros: digit 1 (0001) and digit 4 (0100) make every term 0. ✓
Segments b–g are found the same way, one K-map each.

## Solved numericals

**1. Add A = 1010, B = 0110 (C0 = 0) with a 4-bit CLA. Show P, G, carries.**

| i | Ai | Bi | Pi = Ai⊕Bi | Gi = AiBi | Ci+1 = Gi + PiCi |
|---|----|----|------------|-----------|-------------------|
| 0 | 0  | 0  | 0          | 0         | C1 = 0 + 0·0 = 0  |
| 1 | 1  | 1  | 0          | 1         | C2 = 1 + 0·0 = 1  |
| 2 | 0  | 1  | 1          | 0         | C3 = 0 + 1·1 = 1  |
| 3 | 1  | 0  | 1          | 0         | C4 = 0 + 1·1 = 1  |

Si = Pi ⊕ Ci: S0 = 0⊕0 = 0, S1 = 0⊕0 = 0, S2 = 1⊕1 = 0, S3 = 1⊕1 = 0.

**Ans:** S = 0000, C4 = 1 → 10000 = 16. Check: 10 + 6 = 16. ✓

**2. Implement F(A,B,C) = Σm(1,2,6,7) with a 4:1 mux, selects S1 = A, S0 = B.**

Group minterms by AB and watch what F does as C varies:

| A B | minterms | F at C=0 | F at C=1 | data input |
|-----|----------|----------|----------|------------|
| 0 0 | m0, m1   | 0        | 1        | I0 = C     |
| 0 1 | m2, m3   | 1        | 0        | I1 = C'    |
| 1 0 | m4, m5   | 0        | 0        | I2 = 0     |
| 1 1 | m6, m7   | 1        | 1        | I3 = 1     |

**Ans:** I0 = C, I1 = C', I2 = 0, I3 = 1 — one mux and one inverter.

**3. Compute 9 − 5 on a 4-bit adder-subtractor, then show why 5 + 6
overflows in 4-bit signed.**

9 − 5, M = 1: B ⊕ M = 0101 ⊕ 1111 = 1010, Cin = 1.
1001 + 1010 + 1 = 1 0100. Carry out = 1, discarded (for unsigned it means
"no borrow"). **Ans:** 0100 = 4. ✓

5 + 6, M = 0: 0101 + 0110 → carries c1 = 0, c2 = 0, c3 = 1, c4 = 0, sum =
1011. Signed 4-bit reads that as −5 — wrong, true answer 11 > +7.
V = C3 ⊕ C4 = 1 ⊕ 0 = **1 → overflow**. The carry into the sign bit flipped
the sign with no matching carry out.
