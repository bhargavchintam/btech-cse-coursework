# Experiment 5 — Joins

**Date:** 06/11/2019

## Aim
Combine rows from the emp and dept tables using inner, outer, self and cross joins.

## Tools
MySQL 5.7 (college lab). Also runs on MariaDB.

## Schema
Uses the emp/dept schema from experiment 1 (14 employees, 4 departments). The
`emp_dept.sql` in this folder builds and loads it; run it before `joins.sql`.

## Queries

**1. Inner join — each employee with department name and location.**
```sql
SELECT e.empno, e.ename, e.job, d.dname, d.loc
FROM emp e JOIN dept d ON e.deptno = d.deptno
ORDER BY e.empno;
```
```
empno  ename   job        dname     loc
7369   SMITH   CLERK      RESEARCH  MYSORE
7499   ALLEN   SALESMAN   SALES     HYDERABAD
7521   WARD    SALESMAN   SALES     HYDERABAD
7566   JONES   MANAGER    RESEARCH  MYSORE
7654   MARTIN  SALESMAN   SALES     HYDERABAD
7698   BLAKE   MANAGER    SALES     HYDERABAD
7782   CLARK   MANAGER    ACCOUNTS  BANGALORE
7788   SCOTT   ANALYST    RESEARCH  MYSORE
7839   KING    PRESIDENT  ACCOUNTS  BANGALORE
7844   TURNER  SALESMAN   SALES     HYDERABAD
7876   ADAMS   CLERK      RESEARCH  MYSORE
7900   JAMES   CLERK      SALES     HYDERABAD
7902   FORD    ANALYST    RESEARCH  MYSORE
7934   MILLER  CLERK      ACCOUNTS  BANGALORE
```

**2. Left outer join — every department, even one with no employees.**
```sql
SELECT d.dname, e.ename
FROM dept d LEFT JOIN emp e ON d.deptno = e.deptno
ORDER BY d.dname, e.ename;
```
```
dname       ename
ACCOUNTS    CLARK
ACCOUNTS    KING
ACCOUNTS    MILLER
OPERATIONS  NULL
RESEARCH    ADAMS
RESEARCH    FORD
RESEARCH    JONES
RESEARCH    SCOTT
RESEARCH    SMITH
SALES       ALLEN
SALES       BLAKE
SALES       JAMES
SALES       MARTIN
SALES       TURNER
SALES       WARD
```
OPERATIONS has no employees, so it appears once with a NULL ename.

**3. Right outer join — the same list, written from the emp side.**
```sql
SELECT d.dname, e.ename
FROM emp e RIGHT JOIN dept d ON e.deptno = d.deptno
ORDER BY d.dname, e.ename;
```
Identical 15-row result to query 2 (dept is on the preserved side either way).

**4. Self join — each employee beside their manager's name.**
```sql
SELECT e.ename AS employee, m.ename AS manager
FROM emp e JOIN emp m ON e.mgr = m.empno
ORDER BY e.ename;
```
```
employee  manager
ADAMS     SCOTT
ALLEN     BLAKE
BLAKE     KING
CLARK     KING
FORD      JONES
JAMES     BLAKE
JONES     KING
MARTIN    BLAKE
MILLER    CLARK
SCOTT     JONES
SMITH     FORD
TURNER    BLAKE
WARD      BLAKE
```
KING is missing — the inner join drops him because his mgr is NULL. A LEFT self
join keeps him:
```sql
SELECT e.ename AS employee, m.ename AS manager
FROM emp e LEFT JOIN emp m ON e.mgr = m.empno
ORDER BY e.ename;
```
This returns all 14 rows, with `KING | NULL` included.

**5. Cross join — every employee paired with every department.**
```sql
SELECT COUNT(*) AS cross_rows
FROM emp CROSS JOIN dept;
```
```
cross_rows
56
```
14 employees × 4 departments = 56 rows.

## Result
Inner, left/right outer, self and cross joins were written and run on emp/dept.
The outer join surfaced the empty OPERATIONS department and the self join needed a
LEFT variant to keep the president, who has no manager.
