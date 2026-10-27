# Unit 6 — Normalization

Normalization is the process of organising the columns of a relation to reduce redundancy and
avoid update / insertion / deletion anomalies. It works off **functional dependencies (FDs)**: we
decompose a badly designed relation into smaller ones, each satisfying a stricter *normal form*.

## Functional dependencies

For a relation R, an FD `X → Y` (read "X determines Y") holds if any two tuples that agree on all
attributes of X also agree on all attributes of Y. X is the **determinant**.

- `empno → ename` — one employee number gives exactly one name.
- `deptno → dname, loc` — the department number fixes the department name and location.

Trivial vs non-trivial:
- **Trivial FD**: `X → Y` where `Y ⊆ X` (e.g. `empno,ename → empno`). Always holds, tells us nothing.
- **Non-trivial FD**: `X → Y` where Y has at least one attribute not in X (`empno → ename`). These
  are the ones that drive design.
- **Completely non-trivial**: `X → Y` with `X ∩ Y = ∅`.

> Sir hammered this: FDs are a statement about ALL possible legal states of the relation, not about
> the rows that happen to be in the table right now. You cannot "discover" an FD from sample data —
> it comes from the meaning of the attributes.

## Armstrong's axioms

Sound and complete rules to infer all FDs implied by a set F. F+ is the *closure* of F (every FD
derivable from F).

- **Reflexivity**: if `Y ⊆ X` then `X → Y`.
- **Augmentation**: if `X → Y` then `XZ → YZ` for any Z.
- **Transitivity**: if `X → Y` and `Y → Z` then `X → Z`.

Derived rules (proved from the three axioms, used to save time):

- **Union**: if `X → Y` and `X → Z` then `X → YZ`.
- **Decomposition**: if `X → YZ` then `X → Y` and `X → Z`.
- **Pseudotransitivity**: if `X → Y` and `WY → Z` then `WX → Z`.

## Attribute closure X+

`X+` = the set of all attributes functionally determined by X under F. Algorithm:

```
closure(X, F):
    result = X
    repeat until result stops growing:
        for each FD  A → B  in F:
            if A ⊆ result:  result = result ∪ B
    return result
```

X is a **superkey** iff `X+` = all attributes of R.

**Worked example.** R(A, B, C, D, E) with
F = { A → BC, CD → E, B → D, E → A }. Compute {A}+.

| step | rule applied        | result set        |
|------|---------------------|-------------------|
| 0    | start               | {A}               |
| 1    | A → BC              | {A, B, C}         |
| 2    | B → D               | {A, B, C, D}      |
| 3    | CD → E (C,D present)| {A, B, C, D, E}   |
| 4    | E → A (already in)  | {A, B, C, D, E}   |

`{A}+ = {A,B,C,D,E}` = R, so **A is a superkey**. Contrast `{B}+`: B → D gives {B,D}, then no FD's
left side is a subset of {B,D} (CD→E needs C), so `{B}+ = {B,D}` — B is not a key.

## Finding candidate keys from FDs

A **candidate key** is a minimal superkey. Method:

1. An attribute that never appears on the right side of any FD **must** be in every candidate key.
2. Compute the closure of that core; if it is already R, it is the key.
3. Otherwise add attributes and test closures, keeping only minimal sets.

**Worked example** (same R and F as above). Every attribute appears on some RHS
(B,C from A→BC; E from CD→E; D from B→D; A from E→A), so no forced core. Test candidates:

- `{A}+ = ABCDE` → key. `{E}+`: E→A, A→BC, B→D, CD→E = ABCDE → key.
- `{BC}+`: B→D, then CD→E, then E→A = ABCDE → key. `{CD}+`: CD→E, E→A, A→B = ABCDE → key.
- `{B}+ = BD`, `{C}+ = C`, `{D}+ = D` — none are keys on their own.

**Candidate keys: {A}, {E}, {B,C}, {C,D}.** Prime attributes (any attribute in some candidate key):
A, B, C, D, E — here all five are prime.

## Normal forms

### 1NF — atomicity
A relation is in **1NF** if every attribute holds a single atomic value — no repeating groups, no
multi-valued cells.

Violation: `student(sid, sname, phones)` with row `(1, Ravi, '99001,88002')`. Two phone numbers
crammed into one cell. Fix — pull the multi-valued attribute into its own row/table:

```
student(sid, sname)              student_phone(sid, phone)
 (1, Ravi)                        (1, 99001)
                                  (1, 88002)
```

### 2NF — remove partial dependencies
In 1NF **and** no non-prime attribute is functionally dependent on *part* of a candidate key. Only
matters when the key is composite.

`enroll(sid, cid, grade, sname, cname)`, key = {sid, cid}, with
FDs `sid → sname`, `cid → cname`, `{sid,cid} → grade`. Here `sid → sname` is a **partial
dependency** (sname depends on only half the key). Decompose:

- `student(sid, sname)` — sid → sname
- `course(cid, cname)` — cid → cname
- `enroll(sid, cid, grade)` — {sid,cid} → grade

### 3NF — remove transitive dependencies
In 2NF **and** no non-prime attribute transitively depends on a key. Formally, for every non-trivial
`X → A`, either X is a superkey **or** A is a prime attribute.

`emp(empno, ename, deptno, dname, loc)`, key = empno, with
`empno → deptno` and `deptno → dname, loc`. So `empno → deptno → dname` is transitive: dname/loc
depend on the key only *through* deptno. Decompose:

- `emp(empno, ename, deptno)`
- `dept(deptno, dname, loc)`

That is exactly the emp/dept split we use everywhere. The join reconstructs the original:

```sql
SELECT e.empno, e.ename, d.dname, d.loc
FROM emp e JOIN dept d ON e.deptno = d.deptno
ORDER BY e.empno;
```
```
empno   ename   dname       loc
7369    SMITH   RESEARCH    MYSORE
7499    ALLEN   SALES       HYDERABAD
7521    WARD    SALES       HYDERABAD
7566    JONES   RESEARCH    MYSORE
7654    MARTIN  SALES       HYDERABAD
7698    BLAKE   SALES       HYDERABAD
7782    CLARK   ACCOUNTS    BANGALORE
7788    SCOTT   RESEARCH    MYSORE
7839    KING    ACCOUNTS    BANGALORE
7844    TURNER  SALES       HYDERABAD
7876    ADAMS   RESEARCH    MYSORE
7900    JAMES   SALES       HYDERABAD
7902    FORD    RESEARCH    MYSORE
7934    MILLER  ACCOUNTS    BANGALORE
```
All 14 rows come back with no spurious tuples, so the decomposition is lossless.

### BCNF — every determinant is a superkey
Stricter than 3NF: for **every** non-trivial `X → A`, X must be a superkey. BCNF drops the "A is
prime" escape clause that 3NF allows.

Classic 3NF-but-not-BCNF relation `teach(student, subject, teacher)`:
- `teacher → subject` (a teacher teaches only one subject)
- `{student, subject} → teacher` (a student takes a subject from one teacher)

Candidate keys: `{student, subject}` and `{student, teacher}` — so student, subject, teacher are all
prime. `teacher → subject` satisfies 3NF because *subject is prime*, but teacher is **not** a
superkey, so it violates BCNF. Decompose on the offending FD:

- `R1(teacher, subject)` — teacher → subject
- `R2(student, teacher)`

## 3NF preserves dependencies, BCNF may not

Take the same `teach` relation. It is already in 3NF and it *holds both* FDs. The BCNF split above
is lossless, but R2 has only {student, teacher} and R1 only {teacher, subject} — neither relation
contains all of {student, subject, teacher}, so the FD `{student,subject} → teacher` can no longer
be checked without a join. **BCNF lost a dependency.** Staying in 3NF would have kept it.

> Remember: BCNF can lose dependency preservation, 3NF never does. Lost 4 marks on this in IA1.
> A lossless, dependency-preserving 3NF decomposition ALWAYS exists (3NF synthesis via minimal
> cover); a lossless BCNF decomposition always exists, but a dependency-preserving one may not.

## Lossless-join test

A decomposition of R into R1, R2 is **lossless** (the natural join gives back exactly R, no spurious
tuples) iff the common attributes form a superkey of at least one side:

`(R1 ∩ R2) → R1` **or** `(R1 ∩ R2) → R2`.

- emp/dept split: `R1 ∩ R2 = {deptno}`, and `deptno → dname,loc` so deptno is the key of dept →
  **lossless**.
- teach split: `R1 ∩ R2 = {teacher}`, and `teacher → subject` so teacher is the key of R1 →
  **lossless**.

For a split into more than two relations, use the tableau (chase) test: build a matrix, one row per
sub-relation, and repeatedly equate symbols using the FDs; the decomposition is lossless if some row
becomes all-distinguished.

## Dependency-preservation test

Let Fi be F projected onto Ri (the FDs of F+ that use only Ri's attributes). The decomposition is
dependency-preserving iff `(F1 ∪ F2 ∪ … )+ = F+` — i.e. every original FD is enforceable without a
join. Practical check: for each `X → Y` in F, compute `X+` using only the *projected* FDs and see if
Y ⊆ X+. In the teach split, `{student,subject}+` under {teacher → subject} stays {student,subject},
so `{student,subject} → teacher` is not recoverable — not preserved.

## 4NF and 5NF (brief)

**4NF** deals with **multivalued dependencies (MVD)** `X ↠ Y`: for each X value there is a set of Y
values independent of the other attributes. A relation is in 4NF if it is BCNF and every non-trivial
MVD has a superkey on its left. Example — `offering(course, instructor, textbook)` where a course's
instructors and textbooks are independent: `course ↠ instructor` and `course ↠ textbook`. It is
all-key (BCNF) but stores every instructor × textbook combination = redundancy. Split into
`(course, instructor)` and `(course, textbook)`.

**5NF (PJNF)** deals with **join dependencies** — a relation is in 5NF if every join dependency is
implied by its candidate keys. It covers the rare case where a relation is lossless only when split
into *three or more* pieces, not two (the classic supplier–part–project example). Real designs almost
never go past BCNF/4NF.

## Solved problems

**Problem 1.** R(A,B,C,D), F = { AB → C, C → D, D → A, D → B }. Find (AB)+, (C)+, (D)+ and the
candidate keys.

- `(AB)+`: AB→C → {A,B,C}; C→D → {A,B,C,D}. = **ABCD**.
- `(C)+`: C→D → {C,D}; D→A,D→B → {C,D,A,B}. = **ABCD**.
- `(D)+`: D→A,D→B → {D,A,B}; AB→C → {D,A,B,C}. = **ABCD**.
- `(A)+ = A`, `(B)+ = B` — not keys.

**Ans:** C and D are each single-attribute keys; AB is a key and is minimal (neither A nor B alone
determines everything). **Candidate keys: {C}, {D}, {A,B}.**

**Problem 2.** R(A,B,C,D,E), F = { A → B, BC → E, ED → A }. Find all candidate keys.

C and D never appear on any RHS (RHS = B, E, A), so **C and D are in every candidate key**.
`(CD)+ = {C,D}` — not a superkey, so add one more attribute:

- `(ACD)+`: A→B, then BC→E → ABCDE ✓
- `(BCD)+`: BC→E, then ED→A → ABCDE ✓
- `(ECD)+`: ED→A, then A→B → ABCDE ✓

Each is minimal (dropping the added attribute leaves {C,D}, not a key).
**Ans: Candidate keys = {A,C,D}, {B,C,D}, {C,D,E}.** All of A,B,C,D,E are prime.

**Problem 3.** Normalize `SUPPLY(sno, sname, city, status, pno, qty)` with FDs
`sno → sname, city, status`, `city → status`, `{sno,pno} → qty`. Key = {sno, pno}.

- **1NF:** all values atomic — already 1NF.
- **2NF:** `sno → sname,city,status` is a partial dependency (depends on half the key). Split off:
  `supplier(sno, sname, city, status)` and `supply(sno, pno, qty)`.
- **3NF:** in supplier, `sno → city → status` is transitive (status is non-prime). Split again:
  `supplier(sno, sname, city)`, `city_status(city, status)`.

**Ans (final 3NF schema):** `supplier(sno, sname, city)`, `city_status(city, status)`,
`supply(sno, pno, qty)`. Each determinant (sno, city, {sno,pno}) is the key of its relation, so the
result is also in **BCNF**. The decomposition is lossless (shared attributes sno, city are keys of
supplier and city_status) and dependency-preserving.
