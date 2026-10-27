# Unit 2 — Boolean Algebra and Logic Gates

## Postulates

Boolean algebra works on two values {0,1} with three operations: AND (·), OR (+)
and NOT ('). Everything else in this unit is proved from Huntington's postulates:

| postulate    | OR form              | AND form              |
|--------------|----------------------|-----------------------|
| identity     | A + 0 = A            | A · 1 = A             |
| commutative  | A + B = B + A        | AB = BA               |
| distributive | A(B + C) = AB + AC   | A + BC = (A+B)(A+C)   |
| complement   | A + A' = 1           | A · A' = 0            |

The second distributive law A + BC = (A+B)(A+C) has no counterpart in ordinary
algebra. It looks wrong but it holds, and it is the one used for POS form.

## Basic theorems

| theorem      | OR form             | AND form         |
|--------------|---------------------|------------------|
| idempotent   | A + A = A           | A · A = A        |
| null element | A + 1 = 1           | A · 0 = 0        |
| involution   | (A')' = A           |                  |
| absorption   | A + AB = A          | A(A + B) = A     |
| absorption 2 | A + A'B = A + B     | A(A' + B) = AB   |
| associative  | A + (B+C) = (A+B)+C | A(BC) = (AB)C    |

Absorption is a two line proof: A + AB = A(1 + B) = A · 1 = A.
The second form needs the odd distributive law:
A + A'B = (A + A')(A + B) = 1 · (A + B) = A + B.

### Consensus theorem

    AB + A'C + BC = AB + A'C

The consensus term BC is redundant: whenever B and C are both 1, either A = 1
and AB already covers it, or A = 0 and A'C already covers it. Proof by perfect
induction (all 8 rows):

| A | B | C | AB | A'C | BC | AB + A'C + BC | AB + A'C |
|---|---|---|----|-----|----|---------------|----------|
| 0 | 0 | 0 | 0  | 0   | 0  | 0             | 0        |
| 0 | 0 | 1 | 0  | 1   | 0  | 1             | 1        |
| 0 | 1 | 0 | 0  | 0   | 0  | 0             | 0        |
| 0 | 1 | 1 | 0  | 1   | 1  | 1             | 1        |
| 1 | 0 | 0 | 0  | 0   | 0  | 0             | 0        |
| 1 | 0 | 1 | 0  | 0   | 0  | 0             | 0        |
| 1 | 1 | 0 | 1  | 0   | 0  | 1             | 1        |
| 1 | 1 | 1 | 1  | 0   | 1  | 1             | 1        |

The last two columns are identical, so the theorem holds. The consensus term
is built by taking A and A' out of two terms and ANDing what is left (B · C).

## De Morgan's theorems

    (A + B)' = A' · B'          (A · B)' = A' + B'

Break the bar, change the operator, complement the letters. Proof by truth table:

| A | B | (A+B)' | A'B' | (AB)' | A'+B' |
|---|---|--------|------|-------|-------|
| 0 | 0 | 1      | 1    | 1     | 1     |
| 0 | 1 | 0      | 0    | 1     | 1     |
| 1 | 0 | 0      | 0    | 1     | 1     |
| 1 | 1 | 0      | 0    | 0     | 0     |

Columns 3 and 4 match, columns 5 and 6 match — both laws proved. They extend
to any number of variables: (A + B + C)' = A'B'C' and (ABC)' = A' + B' + C'.

> Sir's method for long complements: complement every literal, swap every
> + and ·, keep the bracket structure. One pass, no expanding first.

## Duality

Take any valid Boolean identity, swap + with · and 0 with 1, and the result is
also valid. That is why every table above comes in matched OR/AND pairs — prove
one form and the dual comes free. Example: A + AB = A dualises to A(A+B) = A.
Complements are left alone by duality.

## Minterms, maxterms, SOP and POS

A minterm is an AND term containing every variable once (plain or primed); it
is 1 for exactly one input row. A maxterm is an OR term with every variable; it
is 0 for exactly one row. Mi = mi', same index.

| m | A B C | minterm | maxterm      |
|---|-------|---------|--------------|
| 0 | 0 0 0 | A'B'C'  | A + B + C    |
| 1 | 0 0 1 | A'B'C   | A + B + C'   |
| 2 | 0 1 0 | A'BC'   | A + B' + C   |
| 3 | 0 1 1 | A'BC    | A + B' + C'  |
| 4 | 1 0 0 | AB'C'   | A' + B + C   |
| 5 | 1 0 1 | AB'C    | A' + B + C'  |
| 6 | 1 1 0 | ABC'    | A' + B' + C  |
| 7 | 1 1 1 | ABC     | A' + B' + C' |

The index reads the row with A as MSB: a 0 primes the variable in the minterm,
a 1 primes it in the maxterm. Any function is the OR of the minterms where it
is 1 (canonical SOP) or the AND of the maxterms where it is 0 (canonical POS).

Example: F(A,B,C) = A + B'C. Expand each term until every variable appears:
A = A(B+B')(C+C') = ABC + ABC' + AB'C + AB'C', and B'C = (A+A')B'C.
Collecting: F = Σm(1,4,5,6,7). The rows left over give F' = Σm(0,2,3), so the
same function in maxterms is F = ΠM(0,2,3) — the two index lists always split
the full set between them. SOP builds as a two-level AND-OR circuit, POS as
OR-AND; take whichever form comes out with fewer gates.

## Karnaugh maps

A K-map is the truth table folded so that cells differing in one variable sit
next to each other. Adjacent cells (edges wrap around) merge: 2 cells drop one
variable, 4 cells drop two, 8 cells drop three. Rows and columns run in Gray
order (00, 01, 11, 10), never binary order:

              CD
              00  01  11  10
         00 |  0   1   3   2
    AB   01 |  4   5   7   6
         11 | 12  13  15  14
         10 |  8   9  11  10

Rules: groups must be rectangles of 1, 2, 4 or 8 cells (powers of two only),
make every group as large as possible, every 1 must be in some group, and a 1
may sit in several groups. Each group read off = one product term: keep the
variables that are constant over the group, drop the ones that change.

2 variables — F(A,B) = Σm(1,3):

            B=0  B=1
       A=0 |  0    1
       A=1 |  0    1

The B=1 column is a pair, A drops out. F = B.

3 variables — F(A,B,C) = Σm(1,3,4,6):

              BC
              00  01  11  10
        A=0 |  0   1   1   0
        A=1 |  1   0   0   1

Pair (1,3) in the top row: A=0, C=1 fixed, B changes → A'C. Pair (4,6) in the
bottom row wraps around the edges: A=1, C=0 → AC'. F = A'C + AC' = A ⊕ C. XOR
patterns never group better than pairs — diagonal cells are not adjacent.

### 4-variable worked example

F(A,B,C,D) = Σm(0,1,2,4,5,6,8,9,12,13,14)

              CD
              00  01  11  10
         00 |  1   1   0   1
    AB   01 |  1   1   0   1
         11 |  1   1   0   1
         10 |  1   1   0   0

Groupings, largest first:

1. Octet — columns CD=00 and CD=01, all four rows: cells {0,1,4,5,12,13,8,9}.
   A and B both change, D changes, C stays 0 → **C'**.
2. Quad — left and right edge columns wrap; rows AB=00,01: cells {0,2,4,6}.
   A=0 and D=0 stay fixed → **A'D'**. Picks up the stray 1 at cell 2.
3. Quad — same wrap, rows AB=01,11: cells {4,6,12,14} → B=1, D=0 → **BD'**.
   Picks up cell 14.

Every 1 is covered (cells 0,1,4,5,8,9,12,13 by the octet; 2,6 by A'D'; 14 by
BD') and each group contains a 1 no other group reaches (9 for the octet, 2
for A'D', 14 for BD'), so all three are essential and the cover is minimal.

    F = C' + A'D' + BD'

Ran quine_mccluskey.c on the same minterms — same three terms, same cover.

### Don't-care conditions

Some input combinations never occur (BCD codes 1010–1111, for example). Mark
them X in the map: an X may be circled as a 1 if it enlarges a group, or left
out — no obligation either way.

F(A,B,C,D) = Σm(1,3,7,11,15) + d(0,2,5):

              CD
              00  01  11  10
         00 |  X   1   1   X
    AB   01 |  0   X   1   0
         11 |  0   0   1   0
         10 |  0   0   1   0

Column CD=11 is a quad → CD. Taking X0 and X2 as 1s makes the whole top row a
quad → A'B'. The X at 5 is left as 0. F = CD + A'B'. Without the don't-cares
the same map gives CD + A'B'D — an extra literal for nothing.

## NAND and NOR as universal gates

NAND alone can build NOT, AND, OR — so it can build anything. Same for NOR.

    not:   y = (a nand a) = (a·a)' = a'                     1 gate
    and:   t = (a nand b),  y = (t nand t) = ((ab)')' = ab  2 gates
    or:    y = (a' nand b') = (a'b')' = a + b               3 gates
           (the two inverters on the inputs are nands too)

The OR construction is De Morgan in hardware: NAND with inverted inputs is OR.
Dually for NOR:

    not:   y = (a nor a) = a'                               1 gate
    or:    t = (a nor b),  y = (t nor t) = a + b            2 gates
    and:   y = (a' nor b') = (a'+b')' = ab                  3 gates

A NAND is the cheapest gate in CMOS (4 transistors), so real two-level
circuits are designed AND-OR on paper and built NAND-NAND in silicon — the
two middle bubbles cancel. universal_nand.v has the three constructions.

## XOR, XNOR and parity

    A ⊕ B = A'B + AB'        (A ⊕ B)' = A XNOR B = AB + A'B'

XOR is 1 when the inputs differ, XNOR is 1 when they are equal.
Identities: A ⊕ 0 = A, A ⊕ 1 = A', A ⊕ A = 0, A ⊕ A' = 1.

XOR is commutative and associative, so a chain of XORs is well defined and
equals 1 exactly when an odd number of inputs are 1. That is the whole parity
trick: for even parity, the parity bit p = XOR of all data bits. Data 1011 →
p = 1 ⊕ 0 ⊕ 1 ⊕ 1 = 1, transmit 10111, which has four 1s (even). The receiver
XORs all five bits: result 0 means pass, 1 means a bit flipped. Two flipped
bits cancel out and go undetected — parity only catches odd numbers of errors.

Remember: XNOR of B and D is exactly the BD + B'D' pattern in numerical 1
below. Recognising it in a map saves time.

## Solved numericals

**Q1.** Minimize F(A,B,C,D) = Σm(0,2,5,7,8,10,13,15) using a K-map.

              CD
              00  01  11  10
         00 |  1   0   0   1
    AB   01 |  0   1   1   0
         11 |  0   1   1   0
         10 |  1   0   0   1

Centre quad {5,7,13,15}: B=1, D=1 fixed → BD. Four corners wrap both ways into
a quad {0,2,8,10}: B=0, D=0 → B'D'. All 1s covered, no smaller cover exists.

**Ans:** F = BD + B'D' = (B ⊕ D)'

**Q2.** Simplify F = ((AB)' + (A' + C)')' using De Morgan's theorems.

Outer bar first — the complement of a sum is the product of complements:

    F = ((AB)')' · ((A' + C)')'
      = (AB) · (A' + C)          involution, twice
      = ABA' + ABC               distribute
      = 0 + ABC                  A·A' = 0

**Ans:** F = ABC
