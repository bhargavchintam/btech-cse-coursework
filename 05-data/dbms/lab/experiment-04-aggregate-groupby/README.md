# Experiment 4 — Aggregate Functions and GROUP BY

**Date:** 23/10/2019

## Aim
Use COUNT, SUM, AVG, MIN and MAX, group rows with GROUP BY, and filter groups with HAVING.

## Tools
MySQL 5.7 (college lab). Also runs on MariaDB.

## Schema
Uses the emp/dept schema with the standard 14 employees / 4 departments (`emp_dept.sql`). Load it first, then run `queries.sql`.

## Queries

**Total employees, and how many actually earn a commission.**
```sql
SELECT COUNT(*) AS total_emps FROM emp;
SELECT COUNT(comm) AS paid_comm FROM emp;
```
`COUNT(*)` = 14, `COUNT(comm)` = 4. COUNT(comm) skips NULLs, so only the four employees with a commission value are counted.

**Lowest, highest and average salary across the company.**
```sql
SELECT MIN(sal) AS lowest, MAX(sal) AS highest, ROUND(AVG(sal),2) AS average FROM emp;
```
| lowest  | highest  | average  |
|---------|----------|----------|
| 8000.00 | 50000.00 | 20732.14 |

**Total payroll.**
```sql
SELECT SUM(sal) AS total_payroll FROM emp;
```
| total_payroll |
|---------------|
| 290250.00     |

**Headcount and wage bill per department.**
```sql
SELECT deptno, COUNT(*) AS headcount, SUM(sal) AS wagebill FROM emp GROUP BY deptno ORDER BY deptno;
```
| deptno | headcount | wagebill  |
|--------|-----------|-----------|
| 10     | 3         | 87500.00  |
| 20     | 5         | 108750.00 |
| 30     | 6         | 94000.00  |

**Average salary per department, richest department first.**
```sql
SELECT deptno, ROUND(AVG(sal),2) AS avg_sal FROM emp GROUP BY deptno ORDER BY avg_sal DESC;
```
| deptno | avg_sal  |
|--------|----------|
| 10     | 29166.67 |
| 20     | 21750.00 |
| 30     | 15666.67 |

**Count and top salary per job title.**
```sql
SELECT job, COUNT(*) AS cnt, MAX(sal) AS top_sal FROM emp GROUP BY job ORDER BY cnt DESC, job;
```
| job       | cnt | top_sal  |
|-----------|-----|----------|
| CLERK     | 4   | 13000.00 |
| SALESMAN  | 4   | 16000.00 |
| MANAGER   | 3   | 29750.00 |
| ANALYST   | 2   | 30000.00 |
| PRESIDENT | 1   | 50000.00 |

**Departments with more than three employees (HAVING on a group count).**
```sql
SELECT deptno, COUNT(*) AS cnt FROM emp GROUP BY deptno HAVING COUNT(*) > 3 ORDER BY deptno;
```
| deptno | cnt |
|--------|-----|
| 20     | 5   |
| 30     | 6   |

**Job titles whose average salary is above 15000 (HAVING on an aggregate).**
```sql
SELECT job, ROUND(AVG(sal),2) AS avg_sal FROM emp GROUP BY job HAVING AVG(sal) > 15000 ORDER BY avg_sal DESC;
```
| job       | avg_sal  |
|-----------|----------|
| PRESIDENT | 50000.00 |
| ANALYST   | 30000.00 |
| MANAGER   | 27583.33 |

## Result
The aggregates matched hand checks (payroll 290250 over 14 employees, average 20732.14). GROUP BY split the rows by department and by job; HAVING then dropped whole groups — departments 10 (only 3 staff) and the CLERK/SALESMAN jobs (average below 15000) were filtered out, which is what HAVING does that WHERE cannot.
