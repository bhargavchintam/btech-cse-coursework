# Experiment 3 — Simple Queries

**Date:** 16/10/2019

## Aim
Retrieve rows from emp/dept using WHERE, BETWEEN, IN, LIKE, IS NULL, ORDER BY and DISTINCT.

## Tools
MySQL 5.7 (college lab). Also runs on MariaDB.

## Schema
Uses the emp/dept schema with the standard 14 employees / 4 departments (`emp_dept.sql`). Load it first, then run `queries.sql`.

## Queries

**Employees earning more than 20000, highest first.**
```sql
SELECT ename, job, sal FROM emp WHERE sal > 20000 ORDER BY sal DESC;
```
| ename | job       | sal      |
|-------|-----------|----------|
| KING  | PRESIDENT | 50000.00 |
| SCOTT | ANALYST   | 30000.00 |
| FORD  | ANALYST   | 30000.00 |
| JONES | MANAGER   | 29750.00 |
| BLAKE | MANAGER   | 28500.00 |
| CLARK | MANAGER   | 24500.00 |

**Salaries in the 12000–16000 band.**
```sql
SELECT ename, sal FROM emp WHERE sal BETWEEN 12000 AND 16000 ORDER BY sal, ename;
```
| ename  | sal      |
|--------|----------|
| MARTIN | 12500.00 |
| WARD   | 12500.00 |
| MILLER | 13000.00 |
| TURNER | 15000.00 |
| ALLEN  | 16000.00 |

**Only managers and analysts.**
```sql
SELECT ename, job FROM emp WHERE job IN ('MANAGER','ANALYST') ORDER BY job, ename;
```
| ename | job     |
|-------|---------|
| FORD  | ANALYST |
| SCOTT | ANALYST |
| BLAKE | MANAGER |
| CLARK | MANAGER |
| JONES | MANAGER |

**Everyone not in department 10 or 20.**
```sql
SELECT ename, deptno FROM emp WHERE deptno NOT IN (10,20) ORDER BY ename;
```
| ename  | deptno |
|--------|--------|
| ALLEN  | 30     |
| BLAKE  | 30     |
| JAMES  | 30     |
| MARTIN | 30     |
| TURNER | 30     |
| WARD   | 30     |

**Names starting with M, and names containing "ER".**
```sql
SELECT ename FROM emp WHERE ename LIKE 'M%' ORDER BY ename;
SELECT ename FROM emp WHERE ename LIKE '%ER%' ORDER BY ename;
```
`LIKE 'M%'` → MARTIN, MILLER  
`LIKE '%ER%'` → MILLER, TURNER

**Employees with no commission, then those with a commission.**
```sql
SELECT ename, comm FROM emp WHERE comm IS NULL ORDER BY empno;
SELECT ename, comm FROM emp WHERE comm IS NOT NULL ORDER BY comm;
```
`IS NULL` returns 10 rows (SMITH, JONES, BLAKE, CLARK, SCOTT, KING, ADAMS, JAMES, FORD, MILLER). `IS NOT NULL`:

| ename  | comm     |
|--------|----------|
| TURNER | 0.00     |
| ALLEN  | 3000.00  |
| WARD   | 5000.00  |
| MARTIN | 14000.00 |

TURNER's comm is 0, a real value — so it shows up under IS NOT NULL, not IS NULL.

**The distinct job titles.**
```sql
SELECT DISTINCT job FROM emp ORDER BY job;
```
| job       |
|-----------|
| ANALYST   |
| CLERK     |
| MANAGER   |
| PRESIDENT |
| SALESMAN  |

**Employees hired in the first half of 2019.**
```sql
SELECT ename, hiredate FROM emp
WHERE hiredate BETWEEN '2019-01-01' AND '2019-06-30' ORDER BY hiredate;
```
| ename | hiredate   |
|-------|------------|
| ALLEN | 2019-02-20 |
| WARD  | 2019-02-22 |
| JONES | 2019-04-02 |
| BLAKE | 2019-05-01 |
| CLARK | 2019-06-09 |

**Dept-30 employees earning at least 15000.**
```sql
SELECT ename, sal, deptno FROM emp WHERE deptno = 30 AND sal >= 15000 ORDER BY sal DESC;
```
| ename  | sal      | deptno |
|--------|----------|--------|
| BLAKE  | 28500.00 | 30     |
| ALLEN  | 16000.00 | 30     |
| TURNER | 15000.00 | 30     |

## Result
Each predicate filtered the expected rows. The IS NULL / IS NOT NULL pair shows the trap that TURNER's `comm = 0` is not the same as NULL, and DISTINCT collapsed the five job titles.
