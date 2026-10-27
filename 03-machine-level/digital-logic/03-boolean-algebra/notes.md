# Unit 3 — Boolean Algebra

## Postulates and laws
Variables take 0 or 1. Operators: OR (+), AND (·), NOT (').

| Law | OR form | AND form |
|---|---|---|
| Identity | A + 0 = A | A · 1 = A |
| Null | A + 1 = 1 | A · 0 = 0 |
| Idempotent | A + A = A | A · A = A |
| Complement | A + A' = 1 | A · A' = 0 |
| Commutative | A + B = B + A | A·B = B·A |
| Associative | A+(B+C)=(A+B)+C | A(BC)=(AB)C |
| Distributive | A(B+C)=AB+AC | A+BC=(A+B)(A+C) |
| Absorption | A + AB = A | A(A+B) = A |

## DeMorgan's theorems
(A·B)' = A' + B'  and  (A+B)' = A'·B'
Extends to any number of variables: complement the whole, complement each variable, swap AND↔OR.

> DeMorgan is why NAND and NOR are universal. Comes up every year.

## Duality
Swap AND↔OR and 0↔1 in any identity and it stays true. That's why the table above pairs up.

## Minterms and maxterms (n variables)
- **Minterm (mᵢ):** product term that is 1 for exactly one input combination. A variable appears complemented if its bit is 0.
- **Maxterm (Mᵢ):** sum term that is 0 for exactly one combination. Complemented if its bit is 1.
- mᵢ' = Mᵢ.

## Canonical forms
- **SOP** (sum of products) = OR of the minterms where F = 1.  F = Σm(...).
- **POS** (product of sums) = AND of the maxterms where F = 0.  F = ΠM(...).

Getting SOP/POS from a truth table: SOP picks the 1-rows, POS picks the 0-rows.

## Solved

**1. F(A,B,C) = Σm(1,3,5,7).** Rows where output is 1 are all odd → C=1 always. **Ans: F = C.**

**2. Prove A + A'B = A + B.** A + A'B = (A+A')(A+B) = 1·(A+B) = **A + B**. ✔

**3. Complement of F = AB + C'D using DeMorgan.**
F' = (AB)'·(C'D)' = (A'+B')(C+D').
