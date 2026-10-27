# Experiment 2 — DML: INSERT, UPDATE, DELETE

**Date:** 02/10/2019

## Aim
Insert new rows, update existing rows (give raises), delete rows with a WHERE condition, and show the before/after state each time.

## Tools
MySQL 5.7 (college lab). Also runs on MariaDB.

## Schema
Uses the emp/dept schema from experiment 1, loaded with the standard 14 employees / 4 departments (`emp_dept.sql`). Load it first, then run `dml.sql`.

## Queries

**Give every clerk a 10% raise. Salaries before and after.**
```sql
SELECT ename, sal FROM emp WHERE job = 'CLERK' ORDER BY empno;
UPDATE emp SET sal = sal * 1.10 WHERE job = 'CLERK';
SELECT ename, sal FROM emp WHERE job = 'CLERK' ORDER BY empno;
```
before:

| ename  | sal      |
|--------|----------|
| SMITH  | 8000.00  |
| ADAMS  | 11000.00 |
| JAMES  | 9500.00  |
| MILLER | 13000.00 |

after:

| ename  | sal      |
|--------|----------|
| SMITH  | 8800.00  |
| ADAMS  | 12100.00 |
| JAMES  | 10450.00 |
| MILLER | 14300.00 |

**Increase MARTIN's commission by 1000.**
```sql
SELECT ename, comm FROM emp WHERE ename = 'MARTIN';
UPDATE emp SET comm = comm + 1000 WHERE ename = 'MARTIN';
SELECT ename, comm FROM emp WHERE ename = 'MARTIN';
```
before → after: `14000.00` → `15000.00`

**Insert two new employees into the OPERATIONS department (deptno 40), which starts empty.**
```sql
SELECT empno, ename, job, sal, deptno FROM emp WHERE deptno = 40;
INSERT INTO emp VALUES
 (7950,'RAGHU','CLERK',7782,'2020-02-10',12000,NULL,40),
 (7951,'DEEPA','SALESMAN',7698,'2020-02-15',14000,2000,40);
SELECT empno, ename, job, sal, deptno FROM emp WHERE deptno = 40;
```
before: 0 rows (no one works in dept 40 yet)

after:

| empno | ename | job      | sal      | deptno |
|-------|-------|----------|----------|--------|
| 7950  | RAGHU | CLERK    | 12000.00 | 40     |
| 7951  | DEEPA | SALESMAN | 14000.00 | 40     |

**Delete the dept-40 employees again. Row count before and after.**
```sql
SELECT COUNT(*) AS emp_count FROM emp;
DELETE FROM emp WHERE deptno = 40;
SELECT COUNT(*) AS emp_count FROM emp;
```
before → after: `16` → `14`

## Result
UPDATE with a WHERE touched only the matching rows (the four clerks, then MARTIN). INSERT added two rows to the previously empty department, and DELETE with the same WHERE removed exactly those two, bringing the count back to 14.
