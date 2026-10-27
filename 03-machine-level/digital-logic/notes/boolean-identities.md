# Boolean Algebra — identities sheet

Revision sheet. Everything on one page.

## Basic
- A + 0 = A          A · 1 = A
- A + 1 = 1          A · 0 = 0
- A + A = A          A · A = A
- A + A' = 1         A · A' = 0
- (A')' = A

## Commutative / Associative / Distributive
- A + B = B + A               A·B = B·A
- A + (B + C) = (A + B) + C   A(BC) = (AB)C
- A(B + C) = AB + AC          A + BC = (A + B)(A + C)

## Absorption / Redundancy
- A + AB = A                  A(A + B) = A
- A + A'B = A + B             A(A' + B) = AB
- AB + A'C + BC = AB + A'C    (consensus — BC is redundant)

## DeMorgan
- (A·B)' = A' + B'
- (A + B)' = A' · B'
- generalises to any number of variables

## XOR / XNOR
- A ⊕ B = A'B + AB'
- A ⊙ B = (A ⊕ B)' = AB + A'B'
- A ⊕ 0 = A, A ⊕ 1 = A', A ⊕ A = 0, A ⊕ A' = 1
- XOR is associative and commutative

## Duality
Swap (· ↔ +) and (0 ↔ 1) in any identity to get another valid identity.
