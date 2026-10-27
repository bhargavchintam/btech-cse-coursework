# Unit 4 — SQL Basics: DDL, DML and SELECT ... WHERE

SQL (Structured Query Language) is the standard language for a relational DBMS. It is
declarative — you say *what* rows you want, the engine works out *how*, one whole set of
rows at a time. All SQL here runs on MySQL/MariaDB (lab is MySQL 5.7); results are real.

## The five sublanguages

SQL is split by what a statement does, not by any keyword in the grammar.

| Sublang | Full form                | Statements                          | Auto-commit? |
|---------|--------------------------|-------------------------------------|--------------|
| DDL     | Data Definition Language | CREATE, ALTER, DROP, TRUNCATE, RENAME | yes (implicit commit) |
| DML     | Data Manipulation        | INSERT, UPDATE, DELETE              | no           |
| DQL     | Data Query Language      | SELECT                             | n/a          |
| DCL     | Data Control Language    | GRANT, REVOKE                      | yes          |
| TCL     | Transaction Control      | COMMIT, ROLLBACK, SAVEPOINT        | —            |

> Sir hammered this: DDL and DCL *auto-commit*. A CREATE or an ALTER cannot be rolled
> back — the transaction so far gets committed the moment the DDL runs. Exam trap.

## Data types (the common ones)

| Type          | Holds                                   | Example            |
|---------------|-----------------------------------------|--------------------|
| `INT`         | whole number, 4 bytes                   | `empno INT`        |
| `VARCHAR(n)`  | variable text up to n chars             | `ename VARCHAR(20)`|
| `CHAR(n)`     | fixed n chars, right-padded with spaces | `gender CHAR(1)`   |
| `DECIMAL(p,s)`| exact number, p digits, s after point   | `sal DECIMAL(8,2)` |
| `DATE`        | calendar date `'YYYY-MM-DD'`            | `hiredate DATE`    |

`CHAR` vs `VARCHAR`: `CHAR(10)` always uses 10 chars, `VARCHAR(10)` only what you store —
use CHAR for fixed things ('M'/'F'), VARCHAR for names. Never store money in `FLOAT`, it
rounds; use `DECIMAL` so 12500.00 stays exact.

## DDL — defining the schema

### CREATE TABLE with constraints

A constraint is a rule the DBMS enforces on every INSERT/UPDATE. A *column constraint* is
written after one column; a *table constraint* is written on its own line and can span
several columns (a composite key needs this form).

```sql
CREATE TABLE student (
    sid    INT PRIMARY KEY,                 -- column constraint
    sname  VARCHAR(30) NOT NULL,
    email  VARCHAR(40) UNIQUE,
    gender CHAR(1),
    cgpa   DECIMAL(4,2) DEFAULT 0.00,
    CONSTRAINT chk_cgpa CHECK (cgpa >= 0 AND cgpa <= 10)   -- table constraint, named
);
```

The six constraints:

- **PRIMARY KEY** — unique *and* NOT NULL, one per table, identifies each row.
- **FOREIGN KEY** — a column whose value must exist in the referenced parent table (or be
  NULL). `FOREIGN KEY (deptno) REFERENCES dept(deptno)`.
- **NOT NULL** — the column must have a value.
- **UNIQUE** — no two rows share the value; unlike PK it *may* be NULL and you can have many.
- **CHECK** — a boolean the row must satisfy, e.g. `CHECK (sal > 0)`.
- **DEFAULT** — value used when the INSERT omits the column.

> A foreign key *can* be NULL, a primary key cannot. Lost 2 marks in IA1 for saying a FK
> must always point at a real parent row — it can be NULL (means "not assigned yet").

A composite key (more than one column) *must* use the table-constraint form —
`PRIMARY KEY (sid, cid)` on its own line; you cannot write it after a single column. Same
for a FK that references a multi-column key.

### ALTER TABLE

Change a table that already exists — add/drop a column, change a type, add a constraint.

```sql
ALTER TABLE student ADD phone CHAR(10);              -- add a column
ALTER TABLE student MODIFY sname VARCHAR(40) NOT NULL;   -- change type/nullability
ALTER TABLE student ADD CONSTRAINT chk_g CHECK (gender IN ('M','F'));  -- add constraint
ALTER TABLE student DROP COLUMN phone;               -- drop a column
```

`MODIFY` is MySQL's spelling (standard SQL uses `ALTER COLUMN`); `CHANGE old new TYPE`
renames a column.

### DROP, and TRUNCATE vs DELETE

`DROP TABLE student;` removes the table itself — structure and data both gone. Start schema
files with `DROP TABLE IF EXISTS ...;` so re-running them doesn't error on "table exists".

TRUNCATE and DELETE both empty a table but are not the same:

| Point          | `DELETE FROM t`            | `TRUNCATE TABLE t`        |
|----------------|----------------------------|---------------------------|
| Sublanguage    | DML                        | DDL                       |
| WHERE allowed  | yes                        | no (all rows, always)     |
| Per-row        | logs each row, fires triggers | drops & recreates, no triggers |
| Rollback       | yes (within a transaction) | no (auto-commits)         |
| AUTO_INCREMENT | keeps the counter          | resets to 1               |
| Speed          | slower on big tables       | very fast                 |

## DML — changing the data

### INSERT (its forms)

```sql
-- 1. all columns, in table order (values must match every column)
INSERT INTO course VALUES ('CS3010','Database Systems',4);

-- 2. named columns (omitted ones take DEFAULT / NULL) — the safe form
INSERT INTO student (sid, sname, email) VALUES (5,'Kiran Shetty','kiran@reva.edu');

-- 3. many rows in one statement
INSERT INTO course VALUES
 ('CS3020','Operating Systems',4),
 ('CS3030','Computer Networks',3);

-- 4. rows from another query
INSERT INTO topper (sid, cgpa) SELECT sid, cgpa FROM student WHERE cgpa >= 9;
```

Form 2 (named columns) is the one to prefer — it still works if a column is added later,
and the DEFAULT fires for anything you leave out.

### UPDATE

```sql
UPDATE student SET cgpa = 8.90 WHERE sid = 3;
UPDATE emp SET sal = sal * 1.10 WHERE deptno = 30;   -- 10% raise for dept 30
```

Forget the WHERE and *every* row is updated — so test the WHERE with a SELECT first.

### DELETE

```sql
DELETE FROM enrollment WHERE marks < 40;
DELETE FROM enrollment;          -- every row, table structure stays
```

With foreign keys, delete the child rows before the parent or the FK blocks it.

## SELECT ... WHERE and its operators

`SELECT columns FROM table WHERE condition;` — WHERE keeps only the rows where the
condition is TRUE. Examples run on the emp/dept sample (14 employees, 4 departments).

**Comparison** `= <> < > <= >=`, **BETWEEN a AND b** (inclusive, numbers or dates), and
**IN (list)** (any value in the set, shorter than a chain of ORs):

```sql
SELECT ename, sal FROM emp WHERE sal > 20000;                    -- 6 rows
SELECT ename, sal FROM emp WHERE sal BETWEEN 12000 AND 16000;    -- 5 rows
SELECT ename, job FROM emp WHERE job IN ('MANAGER','ANALYST');   -- 5 rows
```

**LIKE** — pattern match. `%` = any run of characters (including none), `_` = exactly one:

```sql
SELECT ename FROM emp WHERE ename LIKE 'S%';     -- starts with S: SMITH, SCOTT
SELECT ename FROM emp WHERE ename LIKE '_A%';    -- 2nd letter A: WARD, MARTIN, JAMES
SELECT ename FROM emp WHERE ename LIKE '%LL%';   -- contains LL: ALLEN, MILLER
```

**IS NULL / IS NOT NULL** — NULL means "unknown", so `comm = NULL` never matches; you must
use IS NULL. And 0 is a value, not NULL:

```sql
SELECT ename FROM emp WHERE comm IS NULL;        -- 10 rows (TURNER has comm 0, so NOT here)
```

**AND / OR / NOT** — combine conditions; AND binds tighter than OR, so parenthesise:

```sql
SELECT ename FROM emp
WHERE (deptno = 30 AND sal > 12500) OR job = 'PRESIDENT';   -- 4 rows: ALLEN, BLAKE, KING, TURNER
```

## DCL — GRANT and REVOKE (briefly)

DCL controls *who* may do *what*. The DBA grants privileges to users and revokes them.

```sql
GRANT SELECT, INSERT ON school.student TO 'ravi'@'localhost';
GRANT ALL PRIVILEGES ON school.* TO 'admin'@'localhost';
REVOKE INSERT ON school.student FROM 'ravi'@'localhost';
```

`WITH GRANT OPTION` lets the grantee pass the privilege on further.

---

## Solved problems

**1. Write a CREATE TABLE for `account(accno, name, balance, branch)` where accno is the
key, name is required, balance defaults to 0 and can't go negative, and branch defaults to
'MAIN'.**

**Ans:**
```sql
CREATE TABLE account (
    accno   INT PRIMARY KEY,
    name    VARCHAR(30) NOT NULL,
    balance DECIMAL(10,2) DEFAULT 0.00 CHECK (balance >= 0),
    branch  VARCHAR(15) DEFAULT 'MAIN'
);
```
PRIMARY KEY gives unique + NOT NULL on accno, the CHECK stops a negative balance, and the
DEFAULTs supply 0.00 and 'MAIN' when the INSERT omits them.

**2. From emp, list employees whose name is exactly five letters and ends in N.**

**Ans:** exactly five letters ⇒ four wildcards then N — `'____N'` (four underscores, one N):
```sql
SELECT ename FROM emp WHERE ename LIKE '____N';
```
Actual result — one row:
```
ename
ALLEN
```
(SMITH ends in H, JONES/JAMES/ADAMS end in S, so only ALLEN qualifies.)

**3. From emp, list name, hiredate and salary of everyone in dept 20 hired in 2019 earning
above 25000, ordered by name.**

**Ans:**
```sql
SELECT ename, hiredate, sal FROM emp
WHERE deptno = 20 AND YEAR(hiredate) = 2019 AND sal > 25000
ORDER BY ename;
```
Actual result — three rows:
```
ename   hiredate     sal
FORD    2019-12-03   30000.00
JONES   2019-04-02   29750.00
SCOTT   2019-12-09   30000.00
```
SMITH is in dept 20 but was hired in 2018; ADAMS earns only 11000, so both drop out.
