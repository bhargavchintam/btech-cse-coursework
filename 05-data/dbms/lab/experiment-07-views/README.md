# Experiment 7 — Views

**Date:** 27/11/2019

## Aim
Create views over emp/dept, query them, and show the difference between an
updatable view and a read-only one.

## Tools
MySQL 5.7 (college lab). Also runs on MariaDB.

## Schema
Uses the emp/dept schema from experiment 1. Run `emp_dept.sql`, then `views.sql`.

## Queries

**1. A department-summary view (read-only, has a GROUP BY).**
```sql
CREATE VIEW dept_summary AS
SELECT d.deptno, d.dname, COUNT(e.empno) AS headcount, AVG(e.sal) AS avg_sal
FROM dept d LEFT JOIN emp e ON d.deptno = e.deptno
GROUP BY d.deptno, d.dname;

SELECT * FROM dept_summary ORDER BY deptno;
```
```
deptno  dname       headcount  avg_sal
10      ACCOUNTS    3          29166.666667
20      RESEARCH    5          21750.000000
30      SALES       6          15666.666667
40      OPERATIONS  0          NULL
```

**2. A high-earners view — everyone paid above the company average.**
```sql
CREATE VIEW high_earners AS
SELECT e.empno, e.ename, e.sal, d.dname
FROM emp e JOIN dept d ON e.deptno = d.deptno
WHERE e.sal > (SELECT AVG(sal) FROM emp);

SELECT ename, sal, dname FROM high_earners ORDER BY sal DESC;
```
```
ename  sal       dname
KING   50000.00  ACCOUNTS
SCOTT  30000.00  RESEARCH
FORD   30000.00  RESEARCH
JONES  29750.00  RESEARCH
BLAKE  28500.00  SALES
CLARK  24500.00  ACCOUNTS
```
The company average is 20732.14, so six employees clear it.

**3. An updatable view — a single-table slice of department 10.**
```sql
CREATE VIEW emp10 AS
SELECT empno, ename, job, sal, deptno
FROM emp
WHERE deptno = 10;

SELECT * FROM emp10 ORDER BY empno;
```
```
empno  ename   job        sal       deptno
7782   CLARK   MANAGER    24500.00  10
7839   KING    PRESIDENT  50000.00  10
7934   MILLER  CLERK      13000.00  10
```
Because it is one table with no aggregate, an UPDATE through it reaches emp:
```sql
UPDATE emp10 SET sal = sal * 1.05 WHERE empno = 7934;
SELECT empno, ename, sal FROM emp WHERE empno = 7934;
```
```
empno  ename   sal
7934   MILLER  13650.00
```
MILLER's salary changed in the base table, not just the view.

**4. The grouped view is read-only.**
```sql
UPDATE dept_summary SET headcount = 0 WHERE deptno = 10;
```
```
ERROR 1288 (HY000): The target table dept_summary of the UPDATE is not updatable
```
A view built on GROUP BY (or aggregates, DISTINCT, a join with derived columns)
cannot be written through, so this statement is left commented out in `views.sql`.

## Result
Three views were created — a grouped summary, a high-earners report and a
single-table slice. The single-table view accepted an UPDATE that flowed to emp,
while the grouped view rejected it with error 1288.
