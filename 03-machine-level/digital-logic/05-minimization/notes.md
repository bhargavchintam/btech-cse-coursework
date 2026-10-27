# Unit 5 — Minimization (K-map & Quine-McCluskey)

## Why minimize
Fewer literals → fewer gates → cheaper, faster circuit. Two standard methods: Karnaugh map (visual, ≤ 4–5 variables) and Quine-McCluskey (tabular, any number, programmable).

## Karnaugh map
Cells are arranged in **Gray-code order** so physically adjacent cells differ in one variable. A group of 2ⁿ adjacent 1s removes n variables.

Rules:
- Groups must be size 1, 2, 4, 8 … (powers of two), rectangular, wrap around edges.
- Make groups **as large as possible** and use **as few groups** as possible.
- Every 1 must be covered; groups may overlap.
- Don't-care (×) cells can be included if they help make a bigger group.

## Worked K-maps

**F(A,B,C) = Σm(0,1,2,3,7).**
0,1,2,3 form a quad (A=0) → A'. 3 and 7 form a pair (B=1,C=1) → BC.
**Ans: F = A' + BC.**

**F(A,B,C,D) = Σm(0,1,4,5,10,11,14,15).**
0,1,4,5 → A'C'. 10,11,14,15 → AC.
**Ans: F = A'C' + AC.**

## Prime implicants
- **Prime implicant:** a group that cannot be made any larger.
- **Essential prime implicant:** the only group covering some particular minterm — it must be in the answer.
Pick all essentials first, then cover whatever is left with the fewest remaining PIs.

## Quine-McCluskey (tabular)
1. List minterms in binary, grouped by number of 1s.
2. Combine terms from adjacent groups that differ in one bit; mark them, put a dash in the changed position.
3. Repeat until nothing more combines. Unmarked terms are the prime implicants.
4. Build a PI chart, pick essential PIs, then cover the rest.

The `quine_mccluskey.c` in this folder does all of this and prints the minimized SOP (verified on Σm(0,1,2,4,5) → B' + A'C').

## Solved
**Simplify F = Σm(1,3,5,7).** All odd minterms → **F = C** (the LSB variable = 1 throughout).
