# Experiment 6 — Subqueries and Set Operations

**Date:** 13/11/2019

## Aim
Write single-row, multi-row and correlated subqueries, use EXISTS, and build
set-operation queries with UNION (emulating INTERSECT and EXCEPT, which MySQL 5.7
does not have).

## Tools
MySQL 5.7 (college lab). Also runs on MariaDB.

## Schema
Uses the emp/dept schema from experiment 1. Run `emp_dept.sql`, then `subqueries.sql`.

## Queries

**1. Single-row subquery — employees earning more than JONES.**
```sql
SELECT ename, sal
FROM emp
WHERE sal > (SELECT sal FROM emp WHERE ename = 'JONES')
ORDER BY sal;
```
```
ename  sal
SCOTT  30000.00
FORD   30000.00
KING   50000.00
```

**2. Multi-row IN — employees in departments located at BANGALORE or HYDERABAD.**
```sql
SELECT ename, deptno
FROM emp
WHERE deptno IN (SELECT deptno FROM dept WHERE loc IN ('BANGALORE','HYDERABAD'))
ORDER BY deptno, ename;
```
```
ename   deptno
CLARK   10
KING    10
MILLER  10
ALLEN   30
BLAKE   30
JAMES   30
MARTIN  30
TURNER  30
WARD    30
```

**3. Multi-row ANY — non-clerks paid more than at least one clerk.**
```sql
SELECT ename, job, sal
FROM emp
WHERE sal > ANY (SELECT sal FROM emp WHERE job = 'CLERK')
  AND job <> 'CLERK'
ORDER BY sal;
```
```
ename   job        sal
WARD    SALESMAN   12500.00
MARTIN  SALESMAN   12500.00
TURNER  SALESMAN   15000.00
ALLEN   SALESMAN   16000.00
CLARK   MANAGER    24500.00
BLAKE   MANAGER    28500.00
JONES   MANAGER    29750.00
SCOTT   ANALYST    30000.00
FORD    ANALYST    30000.00
KING    PRESIDENT  50000.00
```
`> ANY` compares against the smallest clerk salary (SMITH, 8000), so every
non-clerk qualifies.

**4. Multi-row ALL — employees paid more than every salesman.**
```sql
SELECT ename, sal
FROM emp
WHERE sal > ALL (SELECT sal FROM emp WHERE job = 'SALESMAN')
ORDER BY sal;
```
```
ename  sal
CLARK  24500.00
BLAKE  28500.00
JONES  29750.00
SCOTT  30000.00
FORD   30000.00
KING   50000.00
```
`> ALL` means above the highest salesman (ALLEN, 16000).

**5. Correlated subquery — employees earning above their own department's average.**
```sql
SELECT e.ename, e.deptno, e.sal
FROM emp e
WHERE e.sal > (SELECT AVG(x.sal) FROM emp x WHERE x.deptno = e.deptno)
ORDER BY e.deptno, e.sal;
```
```
ename  deptno  sal
KING   10      50000.00
JONES  20      29750.00
SCOTT  20      30000.00
FORD   20      30000.00
ALLEN  30      16000.00
BLAKE  30      28500.00
```
The inner query re-runs for each outer row, using that row's deptno.

**6. EXISTS — departments that have at least one employee.**
```sql
SELECT d.deptno, d.dname
FROM dept d
WHERE EXISTS (SELECT 1 FROM emp e WHERE e.deptno = d.deptno)
ORDER BY d.deptno;
```
```
deptno  dname
10      ACCOUNTS
20      RESEARCH
30      SALES
```
OPERATIONS (40) is left out — no matching employee.

**7. UNION — departments that employ a clerk or an analyst.**
```sql
SELECT deptno FROM emp WHERE job = 'CLERK'
UNION
SELECT deptno FROM emp WHERE job = 'ANALYST'
ORDER BY deptno;
```
```
deptno
10
20
30
```
UNION removes duplicates automatically.

**8. INTERSECT emulated with IN — departments having both a clerk and a manager.**
```sql
SELECT DISTINCT deptno FROM emp WHERE job = 'CLERK'
  AND deptno IN (SELECT deptno FROM emp WHERE job = 'MANAGER')
ORDER BY deptno;
```
```
deptno
10
20
30
```

**9. EXCEPT emulated with NOT IN — departments with a clerk but no analyst.**
```sql
SELECT DISTINCT deptno FROM emp WHERE job = 'CLERK'
  AND deptno NOT IN (SELECT deptno FROM emp WHERE job = 'ANALYST')
ORDER BY deptno;
```
```
deptno
10
30
```
Only department 20 has analysts, so it drops out.

## Result
Single-row, IN/ANY/ALL, correlated and EXISTS subqueries all returned the expected
rows. MySQL 5.7 has no INTERSECT or EXCEPT keyword, so those were reproduced with
`IN` and `NOT IN` against a second query.
