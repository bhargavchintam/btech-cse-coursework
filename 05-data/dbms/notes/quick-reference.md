# DBMS quick reference

One-page revision sheet. MySQL/MariaDB dialect (college lab is MySQL 5.7). Sample data is the
emp/dept schema — 14 employees, 4 departments.

## SELECT — clause order

Written order and the order the engine actually runs them differ:

```
SELECT   col, agg(col)        -- 5. pick / compute columns
FROM     t1 JOIN t2 ON ...    -- 1. sources
WHERE    row_condition        -- 2. filter rows (no aggregates here)
GROUP BY col                  -- 3. form groups
HAVING   group_condition      -- 4. filter groups (aggregates ok)
ORDER BY col [ASC|DESC]       -- 6. sort
LIMIT    n [OFFSET m];        -- 7. cut
```

Execution: **FROM → WHERE → GROUP BY → HAVING → SELECT → ORDER BY → LIMIT.** A SELECT alias is
therefore visible in ORDER BY but not in WHERE.

## WHERE operators

| Operator | Use |
|---|---|
| `= <> < > <= >=` | comparison |
| `BETWEEN a AND b` | inclusive range (numbers, dates) |
| `IN (list)` | membership |
| `LIKE 'S%'  '_A%'  '%LL%'` | `%` = any run, `_` = one char |
| `IS NULL / IS NOT NULL` | NULL test — `= NULL` never matches |
| `AND OR NOT` | AND binds tighter than OR; parenthesise |

## Joins

| Join | Keeps |
|---|---|
| `A JOIN B ON …` (INNER) | only matching rows |
| `A LEFT JOIN B` | all of A, NULL-padded B |
| `A RIGHT JOIN B` | all of B, NULL-padded A |
| FULL OUTER | both sides — MySQL has no keyword; `LEFT … UNION RIGHT …` |
| `A CROSS JOIN B` | Cartesian product, no ON |
| self join | table to itself, two aliases (`emp e JOIN emp m ON e.mgr=m.empno`) |
| `NATURAL JOIN` | auto-match same-named columns (fragile — prefer explicit ON) |

## Aggregates and grouping

`COUNT SUM AVG MIN MAX` collapse rows to one value. **Aggregates ignore NULL**; `COUNT(*)` counts
rows, `COUNT(col)` counts non-NULL. Every non-aggregated SELECT column must be in GROUP BY.
WHERE filters rows before grouping, HAVING filters groups after.

## Subquery forms

| Form | Shape |
|---|---|
| single-row | `WHERE sal = (SELECT MAX(sal) FROM emp)` |
| multi-row | `IN (…)`, `> ANY(…)` = > min, `> ALL(…)` = > max |
| correlated | inner uses an outer column, re-runs per row |
| EXISTS | `WHERE EXISTS (SELECT 1 FROM … WHERE …)` — true if ≥1 row |

Set ops: `UNION` (removes duplicates), `UNION ALL` (keeps them). `INTERSECT`, `EXCEPT`/`MINUS` are
standard SQL but **not in MySQL 5.7** — emulate with `IN` / `NOT IN`.

## CREATE TABLE — constraints

```sql
CREATE TABLE emp (
    empno    INT PRIMARY KEY,
    ename    VARCHAR(20) NOT NULL,
    sal      DECIMAL(8,2) DEFAULT 0 CHECK (sal > 0),
    deptno   INT,
    email    VARCHAR(40) UNIQUE,
    FOREIGN KEY (deptno) REFERENCES dept(deptno)
);
```

| Constraint | Meaning |
|---|---|
| PRIMARY KEY | unique + NOT NULL, one per table |
| FOREIGN KEY | must match a parent PK **or be NULL** |
| NOT NULL | value required |
| UNIQUE | no duplicates; may be NULL, many allowed |
| CHECK (cond) | boolean the row must satisfy |
| DEFAULT v | used when INSERT omits the column |

Composite key needs the table form: `PRIMARY KEY (sid, cid)` on its own line.

## DDL / DML

```sql
ALTER TABLE t ADD phone CHAR(10);
ALTER TABLE t MODIFY ename VARCHAR(40) NOT NULL;
ALTER TABLE t DROP COLUMN phone;
DROP TABLE t;

INSERT INTO t (a,b) VALUES (1,'x');          -- named cols = safe form
INSERT INTO t VALUES (1,'x'),(2,'y');        -- multi-row
INSERT INTO t2 SELECT … FROM t WHERE …;      -- from a query
UPDATE t SET sal = sal*1.1 WHERE deptno=30;
DELETE FROM t WHERE marks < 40;
```

**DELETE vs TRUNCATE:** DELETE is DML, WHERE-able, logged per row, rollback-able, keeps
AUTO_INCREMENT. TRUNCATE is DDL, all rows, no triggers, auto-commits (no rollback), resets the
counter, faster.

## SQL sublanguages

| | Statements | Auto-commit |
|---|---|---|
| DDL | CREATE ALTER DROP TRUNCATE RENAME | yes |
| DML | INSERT UPDATE DELETE | no |
| DQL | SELECT | — |
| DCL | GRANT REVOKE | yes |
| TCL | COMMIT ROLLBACK SAVEPOINT | — |

## VIEW / INDEX

```sql
CREATE VIEW emp30 AS SELECT empno,ename,sal FROM emp WHERE deptno=30;
-- updatable only if single table, no aggregate/GROUP BY/DISTINCT

CREATE [UNIQUE] INDEX idx_emp_sal ON emp (sal);
CREATE INDEX idx_emp_job_sal ON emp (job, sal);   -- composite, leftmost first
DROP INDEX idx_emp_sal ON emp;
SHOW INDEX FROM emp;
EXPLAIN SELECT … ;                                -- type=ALL scan vs ref/const index
```

## PROCEDURE / FUNCTION

```sql
DELIMITER //
CREATE PROCEDURE dept_count(IN p_deptno INT, OUT p_cnt INT)
BEGIN
    SELECT COUNT(*) INTO p_cnt FROM emp WHERE deptno = p_deptno;
END //
DELIMITER ;
CALL dept_count(20, @n);  SELECT @n;
```

Parameter modes: **IN** (default, read), **OUT** (returns), **INOUT** (both).

```sql
DELIMITER //
CREATE FUNCTION annual_sal(p_empno INT) RETURNS DECIMAL(10,2)
READS SQL DATA
BEGIN
    DECLARE v DECIMAL(10,2);
    SELECT sal*12 + IFNULL(comm,0) INTO v FROM emp WHERE empno = p_empno;
    RETURN v;
END //
DELIMITER ;
```

Function needs a characteristic: `DETERMINISTIC` (same in→same out) or `READS SQL DATA`. A function
returns one value and is callable inside a SELECT; a procedure is `CALL`ed and may return many.

## CURSOR skeleton

```sql
DECLARE v_done INT DEFAULT 0;
DECLARE v_empno INT;
DECLARE cur CURSOR FOR SELECT empno FROM emp;
DECLARE CONTINUE HANDLER FOR NOT FOUND SET v_done = 1;
OPEN cur;
read_loop: LOOP
    FETCH cur INTO v_empno;
    IF v_done = 1 THEN LEAVE read_loop; END IF;
    -- process row
END LOOP;
CLOSE cur;
```

Steps: **DECLARE → OPEN → FETCH (loop) → CLOSE.** The NOT FOUND handler ends the loop.

## TRIGGER skeleton

```sql
CREATE TRIGGER trg_name
BEFORE INSERT ON product      -- {BEFORE|AFTER} {INSERT|UPDATE|DELETE}
FOR EACH ROW
BEGIN
    IF NEW.price <= 0 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'price must be positive';
    END IF;
END
```

6 kinds = {BEFORE, AFTER} × {INSERT, UPDATE, DELETE}. `NEW.col` exists for INSERT/UPDATE, `OLD.col`
for UPDATE/DELETE. `SIGNAL SQLSTATE '45000'` raises a user error.

## Exception handlers

```sql
DECLARE CONTINUE HANDLER FOR 1062 SET ...;        -- 1062 = duplicate key; carry on
DECLARE EXIT HANDLER FOR SQLSTATE '45000' BEGIN   -- catch, then exit block
    GET DIAGNOSTICS CONDITION 1 @m = MESSAGE_TEXT;
END;
```

`CONTINUE` resumes after the failed statement; `EXIT` leaves the enclosing block.

## Relational algebra symbols

| Symbol | Name | SQL |
|---|---|---|
| σ | select (rows) | `WHERE` |
| π | project (columns, distinct) | `SELECT DISTINCT` |
| ρ | rename | alias |
| ∪ ∩ − | union / intersect / difference | `UNION` / (IN) / (NOT IN) |
| × | Cartesian product | `CROSS JOIN` |
| ⋈ | natural / theta join | `JOIN … ON` |
| ⟕ ⟖ ⟗ | left / right / full outer join | `LEFT/RIGHT JOIN` |
| ÷ | division ("related to all") | double `NOT EXISTS` |

σ, π, ρ are unary; the rest binary. ∪ ∩ − need **union-compatible** relations. `A − B ≠ B − A`.

## Normal forms

| NF | Requires | Removes |
|---|---|---|
| 1NF | atomic values, no repeating groups | multivalued / composite cells |
| 2NF | 1NF + no non-prime attr on **part** of a key | partial dependency |
| 3NF | 2NF + every `X→A`: X superkey **or** A prime | transitive dependency |
| BCNF | every non-trivial `X→A`: X is a superkey | 3NF's "A is prime" escape |
| 4NF | BCNF + every non-trivial MVD has superkey LHS | multivalued dependency |
| 5NF | every join dependency implied by candidate keys | join dependency |

**Lossless join:** `(R1 ∩ R2)` is a superkey of R1 or of R2. **3NF is always
dependency-preserving; BCNF may not be.** Candidate key = minimal superkey; X is a superkey iff
`X+` = all attributes.

## Armstrong's axioms

Reflexivity (`Y⊆X ⇒ X→Y`), Augmentation (`X→Y ⇒ XZ→YZ`), Transitivity (`X→Y, Y→Z ⇒ X→Z`).
Derived: Union, Decomposition, Pseudotransitivity.

## ACID

| | Guarantee | Owner |
|---|---|---|
| Atomicity | all operations or none | recovery mgr (log, UNDO) |
| Consistency | valid state → valid state | constraints + correct txn |
| Isolation | concurrent ≡ some serial order | concurrency mgr |
| Durability | committed survives a crash | write-ahead logging |

## Isolation levels vs anomalies

| Level | Dirty read | Non-repeatable | Phantom |
|---|---|---|---|
| READ UNCOMMITTED | yes | yes | yes |
| READ COMMITTED | no | yes | yes |
| REPEATABLE READ | no | no | yes |
| SERIALIZABLE | no | no | no |

InnoDB default is REPEATABLE READ. `SET SESSION TRANSACTION ISOLATION LEVEL SERIALIZABLE;`

## Serializability

Two ops **conflict** if different txns, same item, at least one write. **Conflict-serializable** iff
the **precedence graph** (edge Ti→Tj when an op of Ti conflicts with a later op of Tj) has **no
cycle**; a topological sort gives the serial order. 2PL (growing then shrinking phase) guarantees
serializability but not freedom from deadlock. Strict 2PL holds X-locks to commit → no cascading
rollback. Deadlock detected by a cycle in the **wait-for graph**; prevented by wait-die (older waits,
younger dies) / wound-wait (older wounds, younger waits).

## Function cheat-list

**Aggregate:** `COUNT SUM AVG MIN MAX` (ignore NULL).

**String:** `CONCAT('DB','MS')`→DBMS, `SUBSTRING('DATABASE',1,4)`→DATA, `LENGTH('REVA')`→4,
`UPPER/LOWER`, `LPAD('7',3,'0')`→007, `REPLACE('a-b-c','-','+')`→a+b+c, `INSTR('DATABASE','A')`→2,
`TRIM`, `LEFT/RIGHT`.

**Date:** `YEAR('2019-08-15')`→2019, `MONTHNAME(…)`→August, `DATEDIFF('2019-12-31','2019-01-01')`→364,
`DATE_FORMAT(d,'%d-%m-%Y')`→15-08-2019, `DATE_ADD(d, INTERVAL 10 DAY)`, `NOW() CURDATE()`.

**Numeric:** `ROUND(20732.14,1)`→20732.1, `MOD(17,5)`→2, `CEIL(4.1)`→5, `FLOOR(4.9)`→4,
`TRUNCATE(3.567,1)`→3.5, `GREATEST(3,9,2)`→9, `ABS POWER`.

**NULL:** `IFNULL(NULL,0)`→0, `COALESCE(NULL,NULL,5)`→5, `NULLIF(4,4)`→NULL.
