# Unit 5 — Advanced SQL Querying

Unit 4 was the basics — SELECT, WHERE, data types, DML. This unit is the part that gets tested hard:
aggregates, grouping, the joins, subqueries, set operations and views. All examples use the emp/dept
schema (14 employees, 4 departments) from `emp_dept.sql`, so every result below is the exact output of
running the query on MariaDB in the lab.

## Aggregate functions

The five aggregates — `COUNT`, `SUM`, `AVG`, `MIN`, `MAX` — collapse many rows into one value.

```sql
SELECT COUNT(*) AS n_emp, SUM(sal) AS total_sal, AVG(sal) AS avg_sal,
       MIN(sal) AS min_sal, MAX(sal) AS max_sal
FROM emp;
```
```
n_emp  total_sal  avg_sal       min_sal  max_sal
14     290250.00  20732.142857  8000.00  50000.00
```

**The NULL rule** (the exam trap): aggregates *ignore* NULLs — not counted, not summed, not averaged.
`COUNT(*)` counts rows; `COUNT(col)` counts only rows where `col` is NOT NULL. Only 4 of the 14
employees have a commission:

```sql
SELECT COUNT(*) AS all_rows, COUNT(comm) AS with_comm FROM emp;   -- 14, 4
```

So `AVG(comm)` divides by 4, not 14. Write `AVG(COALESCE(comm,0))` to treat a missing commission as
zero, otherwise NULL rows vanish from the calculation.

> Sir hammered this: NULL is not zero and not the empty string, it means "unknown". Any arithmetic
> with NULL gives NULL, and aggregates skip it.

## GROUP BY

`GROUP BY` splits the table into groups and runs the aggregate once per group. Rule: every column in
SELECT that is not inside an aggregate must appear in the GROUP BY. Headcount and average pay per dept:

```sql
SELECT deptno, COUNT(*) AS headcount, AVG(sal) AS avg_sal
FROM emp GROUP BY deptno ORDER BY deptno;
```
```
deptno  headcount  avg_sal
10      3          29166.666667
20      5          21750.000000
30      6          15666.666667
```

## HAVING — and why not WHERE

`WHERE` filters rows *before* grouping; `HAVING` filters groups *after* the aggregate is computed. You
cannot put an aggregate in WHERE because at that point the groups don't exist yet. Departments whose
average salary tops 20000 — returns dept 20 (21750) and dept 10 (29166.67), dept 30 dropped:

```sql
SELECT deptno, AVG(sal) AS avg_sal
FROM emp GROUP BY deptno HAVING AVG(sal) > 20000 ORDER BY avg_sal;
```

Both can appear together — WHERE trims rows, GROUP BY groups the survivors, HAVING trims groups.
Average clerk pay per dept, only for depts with more than one clerk — returns just dept 20 (2 clerks,
avg 9500), the single-clerk depts 10 and 30 filtered out by HAVING:

```sql
SELECT deptno, COUNT(*) AS clerks, AVG(sal) AS avg_clerk_sal
FROM emp WHERE job = 'CLERK' GROUP BY deptno HAVING COUNT(*) > 1;
```

Execution order: FROM → WHERE → GROUP BY → HAVING → SELECT → ORDER BY. That is also why a SELECT alias
is usable in ORDER BY but not in WHERE.

## ORDER BY

Sorts the final result; `ASC` default, `DESC` reverses, and you can sort by several keys or an alias.
Employees per job, most common first (CLERK 4, SALESMAN 4, MANAGER 3, ANALYST 2, PRESIDENT 1):

```sql
SELECT job, COUNT(*) AS n FROM emp GROUP BY job ORDER BY n DESC, job;
```

## Joins

A join combines rows from two tables on a matching condition. Full set in `joins.sql`.

**Inner join** — only rows matching on both sides. Employee with department name and location:

```sql
SELECT e.ename, e.job, d.dname, d.loc FROM emp e JOIN dept d ON e.deptno = d.deptno;
```

14 rows, one per employee. OPERATIONS (deptno 40) has no employees so it never appears. `NATURAL JOIN`
gives the same result by matching the common column `deptno` automatically, but it is fragile — if the
tables later share another column name it silently joins on that too, so most people write the `ON`
form.

**Left / right outer join** — keeps the unmatched rows of one side, filling the other with NULLs.
`LEFT JOIN` keeps every left row; every department, even the empty one:

```sql
SELECT d.dname, e.ename FROM dept d LEFT JOIN emp e ON d.deptno = e.deptno;
```

15 rows come back — the 14 employees with their dept name, plus one `OPERATIONS | NULL` row kept
because that department has no employees. `RIGHT JOIN` is the mirror image, keeping every right row.

**Full outer join** — keeps unmatched rows from *both* sides. MySQL/MariaDB has no `FULL JOIN`
keyword, so UNION a LEFT and a RIGHT join:

```sql
SELECT d.dname, e.ename FROM dept d LEFT  JOIN emp e ON d.deptno = e.deptno
UNION
SELECT d.dname, e.ename FROM dept d RIGHT JOIN emp e ON d.deptno = e.deptno;
```

Here it matches the LEFT join — every employee has a valid department, only the dept side is unmatched.

**Self join** — a table joined to itself with two aliases. The classic use is a manager's name from
the same table: `e.mgr` (a manager's empno) matched to `m.empno`:

```sql
SELECT e.ename AS employee, m.ename AS manager FROM emp e JOIN emp m ON e.mgr = m.empno;
```

That returns 13 rows (ADAMS→SCOTT, ALLEN→BLAKE, ...), not 14 — KING is PRESIDENT with `mgr` NULL, so
he has no match; a LEFT self join keeps him with a NULL manager.

**Cross join** — every row paired with every row, the Cartesian product, no `ON`. A forgotten join
condition makes one by accident. `SELECT COUNT(*) FROM emp CROSS JOIN dept;` gives 14 × 4 = 56.

## Subqueries

A subquery is a SELECT nested inside another (full set in `subqueries.sql`).

**Single-row** — inner query returns one value, compared with `=`/`<`/`>`. Who earns the max:

```sql
-- SELECT ename FROM emp WHERE sal = MAX(sal);  -- doesnt work, cant use agg in where
SELECT ename, sal FROM emp WHERE sal = (SELECT MAX(sal) FROM emp);   -- KING 50000
```

**Multi-row** — inner query returns many values, use `IN`, `ANY` or `ALL`. `> ANY(list)` means
greater than the *smallest*; `> ALL(list)` greater than the *largest*. Everyone paid more than every
SALESMAN (top salesman earns 16000) — the 6 who beat 16000: CLARK, BLAKE, JONES, SCOTT, FORD, KING:

```sql
SELECT ename, sal FROM emp WHERE sal > ALL (SELECT sal FROM emp WHERE job = 'SALESMAN');
```

**Correlated** — the inner query references a column from the outer query, so it re-runs for each
outer row. The textbook example: employees earning more than their own department's average.

```sql
SELECT e.ename, e.deptno, e.sal
FROM emp e
WHERE e.sal > (SELECT AVG(x.sal) FROM emp x WHERE x.deptno = e.deptno);
```

For each employee `e` the inner query averages just `e`'s own department, then compares. Result — the
6 above their dept average: KING (10), JONES/SCOTT/FORD (20), ALLEN/BLAKE (30).

**EXISTS** — true if the subquery returns at least one row. Departments that have employees:

```sql
SELECT d.dname FROM dept d WHERE EXISTS (SELECT 1 FROM emp e WHERE e.deptno = d.deptno);
```

Returns ACCOUNTS, RESEARCH, SALES; flip to `NOT EXISTS` and only OPERATIONS comes back. EXISTS stops
at the first matching row, so it short-circuits.

## Set operations

`UNION` stacks two result sets and *removes duplicates*; `UNION ALL` keeps them. Both need the two
SELECTs to have the same number of columns of compatible type. Distinct jobs in dept 20 or 30:

```sql
SELECT job FROM emp WHERE deptno = 20
UNION
SELECT job FROM emp WHERE deptno = 30;   -- CLERK, MANAGER, ANALYST, SALESMAN
```

`UNION ALL` of the same two SELECTs returns 11 rows (5 + 6) with jobs repeated — it skips the
de-duplication UNION does, faster when duplicates don't matter.

`INTERSECT` (rows in both) and `EXCEPT`/`MINUS` (in the first, not the second) are in the SQL standard
but **MySQL 5.7 and the college lab build do not support them**. Emulate INTERSECT with `IN`, EXCEPT
with `NOT IN`. Jobs in both dept 20 and dept 30 (INTERSECT); swap `IN` for `NOT IN` and it becomes
EXCEPT, returning only `ANALYST` (in 20, not in 30):

```sql
SELECT DISTINCT job FROM emp WHERE deptno = 20
  AND job IN (SELECT job FROM emp WHERE deptno = 30);   -- CLERK, MANAGER
```

## Views

A view is a stored SELECT that behaves like a virtual table — it holds no data, every query re-runs
the underlying SELECT. See `views.sql`.

```sql
CREATE VIEW emp30 AS
SELECT empno, ename, job, sal, deptno FROM emp WHERE deptno = 30;
```

**Updatable vs read-only.** A view on a single table with no aggregate, GROUP BY or DISTINCT is
*updatable* — INSERT/UPDATE/DELETE flow through to the base table. `emp30` is updatable:
`UPDATE emp30 SET sal = sal + 1000 WHERE ename = 'JAMES';` really changes JAMES in emp. A view with an
aggregate or GROUP BY is *read-only*:

```sql
CREATE VIEW dept_summary AS
SELECT d.deptno, d.dname, COUNT(e.empno) AS headcount, AVG(e.sal) AS avg_sal
FROM dept d LEFT JOIN emp e ON d.deptno = e.deptno
GROUP BY d.deptno, d.dname;
```

`UPDATE dept_summary SET avg_sal = 0 WHERE deptno = 10;` gives `ERROR 1288: The target table
dept_summary of the UPDATE is not updatable`. Views help hide columns (security), reuse a repeated
join, and give report queries a stable name.

## Solved problems

**P1.** Department name with employee count, including departments with nobody.

```sql
SELECT d.dname, COUNT(e.empno) AS headcount
FROM dept d LEFT JOIN emp e ON d.deptno = e.deptno
GROUP BY d.deptno, d.dname ORDER BY headcount DESC, d.dname;
```

A plain inner join would drop OPERATIONS; LEFT JOIN keeps it and `COUNT(e.empno)` counts NULLs as 0.

**Ans:** SALES 6, RESEARCH 5, ACCOUNTS 3, OPERATIONS 0.

**P2.** Second highest salary in emp.

```sql
SELECT MAX(sal) AS second_highest FROM emp WHERE sal < (SELECT MAX(sal) FROM emp);
```

Inner query gives the top salary (KING, 50000); outer takes the max of everything below it. MAX
collapses the tie at 30000 so it stays correct.

**Ans:** `30000.00`

**P3.** Top earner in each department.

```sql
SELECT e.deptno, e.ename, e.sal
FROM emp e
WHERE e.sal = (SELECT MAX(x.sal) FROM emp x WHERE x.deptno = e.deptno)
ORDER BY e.deptno;
```

Correlated: each employee's salary compared against the max of their own department. Dept 20 ties at
30000, so both SCOTT and FORD return.

**Ans:** 10 KING 50000, 20 SCOTT 30000, 20 FORD 30000, 30 BLAKE 28500.
