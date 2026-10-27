# Unit 3 — The Relational Model

The relational model (Codd, 1970) stores data as a set of **relations** — tables — with no
navigational pointers; all connections are made by values (a deptno in emp matches a deptno in
dept). This unit covers the terminology, keys, integrity rules, and relational algebra — the theory
the optimiser works in. All examples use the emp/dept schema: dept has 4 rows, emp has 14.

## Relations, tuples, attributes, domains

- **Relation** — a table. Formally a subset of the Cartesian product of the domains of its
  attributes. Because it is a *set*, no two tuples are identical and there is no row order.
- **Tuple** — a row. One emp record: (7369, SMITH, CLERK, 7902, 2018-12-17, 8000, NULL, 20).
- **Attribute** — a column, with a name and a domain: `ename`, `sal`, `deptno`.
- **Domain** — the set of allowed atomic values for an attribute. Domain of `deptno` is the integers,
  of `job` character strings up to 15 chars. Values must be atomic — no lists in a cell (this is 1NF).
- **Relation schema** — the name plus attributes: `emp(empno, ename, job, mgr, hiredate, sal, comm, deptno)`.
- **Relation instance** — the actual set of tuples now. Schema is fixed, instance changes.

**Degree** = number of attributes (columns): emp has degree 8, dept has degree 3.
**Cardinality** = number of tuples (rows): emp has cardinality 14, dept has cardinality 4. Degree is
fixed by the schema; cardinality changes every INSERT or DELETE.

## Keys

A **superkey** is any set of attributes that uniquely identifies a tuple. `{empno}` is a superkey; so
is `{empno, ename}`, but the second carries a useless extra attribute. A **candidate key** is a
*minimal* superkey — remove any attribute and it stops being unique. In emp, `{empno}` is a candidate
key; `{ename}` happens to be unique for this instance too, but names aren't guaranteed unique so we
don't rely on it.

The **primary key** is the one candidate key chosen to identify tuples — `empno` for emp, `deptno`
for dept. Underlined in a schema: emp(<u>empno</u>, ...). It cannot be NULL. An **alternate key** is a
candidate key not chosen as primary; if a national-id column were a second candidate key, it is the
alternate key. A **composite key** is a key of two or more attributes — a `works_on(empno, projno,
hours)` table keyed on `{empno, projno}` together has a composite primary key.

A **foreign key** is an attribute in one relation that refers to the primary key of another (or the
same) relation. `emp.deptno` is a foreign key referencing `dept.deptno`. `emp.mgr` is a foreign key
referencing `emp.empno` — a relation can reference itself.

> A foreign key can be NULL (KING has mgr = NULL, he reports to no one). A primary key never can.
> Exam trap, sir hammered this every class.

## The three integrity constraints

1. **Entity integrity** — no part of a primary key may be NULL. You cannot insert an emp with a NULL
   empno, because then the row cannot be identified. Enforced by `PRIMARY KEY`.
2. **Referential integrity** — a foreign-key value must either match some existing primary-key value
   in the referenced relation, or be wholly NULL. `emp.deptno` must be one of dept's deptnos (10,20,30,40).
3. **Domain integrity** — every attribute value must belong to its declared domain (type, and any
   CHECK). `sal` must be a number; `CHECK (sal > 0)` would forbid a negative salary.

**What a referential-integrity violation looks like:** trying to give an employee a department that
does not exist —

```sql
INSERT INTO emp (empno, ename, deptno) VALUES (9001, 'RAVI', 99);
-- ERROR 1452: Cannot add or update a child row: a foreign key constraint fails
```

There is no deptno 99 in dept, so the insert is rejected. Deleting dept 20 while SMITH still points at
it fails the same way (a child row would be orphaned).

## Relational algebra

A procedural language: each operator takes one or two relations and returns a relation, so operators
compose. The **unary** ones (σ, π, ρ) take one relation; the **binary** ones (∪, ∩, −, ×, ⋈, ÷) take two.

### Selection σ — picks rows

σ<sub>predicate</sub>(R) keeps the tuples that satisfy the predicate.

    σ(deptno=20)(emp)
```sql
SELECT * FROM emp WHERE deptno = 20;
```
Returns 5 rows: SMITH, JONES, SCOTT, ADAMS, FORD.

### Projection π — picks columns

π<sub>attr-list</sub>(R) keeps only the named columns and, being a set, removes duplicates.

    π(ename, job)(emp)
```sql
SELECT DISTINCT ename, job FROM emp;
```
Returns 14 rows (ADAMS/CLERK, ALLEN/SALESMAN, ... WARD/SALESMAN).

Compose them — names and salaries of the high earners, π(ename, sal)(σ(sal>20000)(emp)):

```sql
SELECT ename, sal FROM emp WHERE sal > 20000;
```
6 rows: KING 50000, SCOTT 30000, FORD 30000, JONES 29750, BLAKE 28500, CLARK 24500.

### Union ∪, intersection ∩, difference −

    π(ename)(σ(job='CLERK')(emp)) ∪ π(ename)(σ(job='ANALYST')(emp))
```sql
SELECT ename FROM emp WHERE job = 'CLERK'
UNION
SELECT ename FROM emp WHERE job = 'ANALYST';
```
6 rows: ADAMS, FORD, JAMES, MILLER, SCOTT, SMITH. These three operators need **union-compatible**
operands — same number of attributes, matching domains.

Intersection — departments having both a very high (>25000) and a very low (<12000) earner:

    π(deptno)(σ(sal>25000)(emp)) ∩ π(deptno)(σ(sal<12000)(emp))
```sql
SELECT deptno FROM emp WHERE sal > 25000
INTERSECT
SELECT deptno FROM emp WHERE sal < 12000;
```
Returns 20 and 30.

Difference — departments that have no employees (all depts minus the ones that appear in emp):

    π(deptno)(dept) − π(deptno)(emp)
```sql
SELECT deptno FROM dept
EXCEPT
SELECT deptno FROM emp;
```
Returns 40 (OPERATIONS). Difference is not commutative: A − B ≠ B − A.

### Cartesian product ×

R × S pairs every tuple of R with every tuple of S; degree adds, cardinality multiplies. σ over a ×
is exactly a join, which is why it is rarely used on its own.

    π(ename)(σ(job='PRESIDENT')(emp)) × π(dname)(dept)
```sql
SELECT k.ename, d.dname
FROM (SELECT ename FROM emp WHERE job = 'PRESIDENT') k
CROSS JOIN dept d;
```
1 × 4 = 4 rows: KING paired with ACCOUNTS, OPERATIONS, RESEARCH, SALES.

### Rename ρ

ρ<sub>m</sub>(emp) gives the relation a new name so it can be used twice in one expression. Needed for a
**self join** — pairing each employee with his manager, who is another emp row:

    π(e.ename, m.ename)( emp[e] ⋈[e.mgr = m.empno] ρ(m)(emp) )
```sql
SELECT e.ename AS employee, m.ename AS manager
FROM emp e JOIN emp m ON e.mgr = m.empno;
```
13 rows (KING is dropped — his mgr is NULL, nothing matches): ADAMS→SCOTT, BLAKE→KING, CLARK→KING,
FORD→JONES, JONES→KING, MILLER→CLARK, SCOTT→JONES, SMITH→FORD, and the four SALESMEN plus JAMES → BLAKE.

### Joins

A **theta join** R ⋈<sub>θ</sub> S is σ<sub>θ</sub>(R × S) — a product filtered by any condition θ.

    emp ⋈[emp.deptno=dept.deptno ∧ emp.sal>25000] dept
```sql
SELECT e.ename, e.sal, d.dname
FROM emp e JOIN dept d ON e.deptno = d.deptno AND e.sal > 25000;
```
5 rows: KING 50000 ACCOUNTS, SCOTT 30000 RESEARCH, FORD 30000 RESEARCH, JONES 29750 RESEARCH,
BLAKE 28500 SALES.

An **equi join** is a theta join whose condition is only equalities (deptno = deptno). A **natural
join** R ⋈ S is an equi join on all commonly-named attributes, then it drops the duplicate column.
emp and dept share only `deptno`, so:

    emp ⋈ dept
```sql
SELECT ename, dname, loc FROM emp NATURAL JOIN dept;
```
14 rows — every employee gets his department name and location (ADAMS RESEARCH MYSORE, ... KING
ACCOUNTS BANGALORE); no rows are lost, since all 14 deptnos are valid.

An **outer join** keeps unmatched tuples and pads the other side with NULL. Left outer ⟕ keeps all of
the left; right ⟖ all of the right; full ⟗ both.

    dept ⟕ emp
```sql
SELECT d.dname, e.ename
FROM dept d LEFT JOIN emp e ON d.deptno = e.deptno
WHERE d.deptno = 40;
```
OPERATIONS has no employees, so the inner join (14 rows) loses it, but the left outer (15 rows) keeps
it as a padded row:

    dname       ename
    OPERATIONS  NULL

### Division ÷

R ÷ S returns the values in R paired with **every** tuple of S ("find X related to all Y"). With
JD = π(job, deptno)(emp) and D = π(deptno)(emp) = {10,20,30}, JD ÷ D is the jobs in *every* occupied dept.

    π(job, deptno)(emp) ÷ π(deptno)(emp)

SQL has no ÷ operator; the idiom is a double NOT EXISTS ("no dept in which this job is missing"):

```sql
SELECT DISTINCT e1.job
FROM emp e1
WHERE NOT EXISTS (
    SELECT d.deptno FROM (SELECT DISTINCT deptno FROM emp) d
    WHERE NOT EXISTS (
        SELECT 1 FROM emp e2 WHERE e2.job = e1.job AND e2.deptno = d.deptno
    )
);
```
Returns CLERK and MANAGER — the only jobs present in dept 10, 20 and 30 alike.

## Multi-step queries

**Names of employees in RESEARCH earning more than 20000.** Join emp to the RESEARCH row of dept,
select on salary, project the name:

    π(ename)( σ(sal>20000)( emp ⋈ σ(dname='RESEARCH')(dept) ) )
```sql
SELECT e.ename FROM emp e JOIN dept d ON e.deptno = d.deptno
WHERE d.dname = 'RESEARCH' AND e.sal > 20000;
```
**Ans:** FORD, JONES, SCOTT.

**Names and jobs of everyone who works in BANGALORE.** BANGALORE is where ACCOUNTS (dept 10) sits:

    π(ename, job)( σ(loc='BANGALORE')( emp ⋈ dept ) )
```sql
SELECT e.ename, e.job FROM emp e JOIN dept d ON e.deptno = d.deptno
WHERE d.loc = 'BANGALORE';
```
**Ans:** CLARK MANAGER, KING PRESIDENT, MILLER CLERK.

## Relational calculus (brief)

Algebra says *how* to compute the answer (procedural); calculus says *what* the answer is
(declarative), and the two have equal expressive power (Codd's theorem). Two flavours:

- **Tuple relational calculus (TRC):** variables range over tuples —
  { t.ename | t ∈ emp ∧ t.sal > 20000 } is the names of emps earning over 20000.
- **Domain relational calculus (DRC):** variables range over attribute values —
  { n | ∃ s ( ⟨_, n, _, _, _, s, _, _⟩ ∈ emp ∧ s > 20000 ) } is the same answer, one variable per column.

SQL feels like calculus (you state a condition) but the engine executes it as algebra.

## Solved problems

**1. List the candidate keys, primary key and alternate key of dept(deptno, dname, loc).**
deptno is unique and dname is unique in this instance, so both {deptno} and {dname} are candidate
keys; supersets like {deptno,loc} or {dname,loc} are superkeys but not minimal.
**Ans:** candidate keys {deptno} and {dname}; primary key = deptno; alternate key = dname.

**2. Write the algebra and SQL for "jobs that occur in every department that has employees", and give
the answer.** This is a division, JD ÷ D as above.
**Ans:** π(job,deptno)(emp) ÷ π(deptno)(emp) = { CLERK, MANAGER } (verified against the data).

**3. A row `INSERT INTO emp VALUES (9002,'MEENA','CLERK',NULL,'2020-02-01',9000,NULL,50)` is rejected.
Which integrity constraint fails and why?**
**Ans:** referential integrity. deptno 50 is a foreign key that has no matching primary key in dept
(dept holds only 10,20,30,40), so the child row is refused. Fix: insert dept 50 first, or use an
existing deptno.
