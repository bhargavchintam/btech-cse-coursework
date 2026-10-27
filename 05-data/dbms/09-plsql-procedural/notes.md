# Unit 9 — Procedural SQL (Stored Programs)

Plain SQL is declarative — one statement at a time, no variables, no loops. When
you need logic that lives *inside* the database — a validation that runs no matter
which application inserts the row, a nightly calculation, a reusable computation —
you write a **stored program**: a procedure, function or trigger. MySQL/MariaDB
calls this its stored-program language; Oracle calls the same idea **PL/SQL**. The
concepts line up one-to-one, only the spelling differs (mapping table at the end).

## Stored program structure — DELIMITER and BEGIN…END

A stored program groups statements in a `BEGIN … END` block. The problem: every
inner statement ends with `;`, but the client also reads `;` as "send this now",
so the `CREATE PROCEDURE` gets cut off at the first inner `;`. The fix is to switch
the client's terminator with `DELIMITER` while you define the routine:

```sql
DELIMITER //
CREATE PROCEDURE hello()
BEGIN
    SELECT 'hi' AS greeting;
END //
DELIMITER ;
```

`//` is arbitrary (`$$` is also common); you set it back to `;` afterwards. This
only matters in the client — it is not part of the stored SQL.

## Variables — DECLARE, SET, SELECT INTO

- `DECLARE v_sal DECIMAL(8,2) DEFAULT 0;` — a local variable. All DECLAREs must
  come **first** in the block, before any other statement.
- `SET v_sal = 5000;` — assign a value.
- `SELECT col1, col2 INTO v_a, v_b FROM ...;` — assign from a query. The query
  must return **exactly one row** (zero rows fires NOT FOUND, many rows errors).

```sql
CREATE PROCEDURE demo_into()
BEGIN
    DECLARE v_name VARCHAR(20);
    DECLARE v_sal  DECIMAL(8,2);
    SELECT ename, sal INTO v_name, v_sal FROM emp WHERE empno = 7839;
    SELECT v_name AS name, v_sal AS sal;
END
```
`CALL demo_into();` returns `KING | 50000.00`. Session variables like `@x` are
different — no DECLARE, they live for the whole connection, and are how you read an
`OUT` value back after a CALL.

## Control flow — IF, CASE, WHILE, REPEAT, LOOP

**IF / ELSEIF / ELSE**, closed with `END IF`:

```sql
IF p_sal >= 30000 THEN SET g = 'A';
ELSEIF p_sal >= 20000 THEN SET g = 'B';
ELSE SET g = 'C';
END IF;
```

**CASE** — cleaner when branching on one value:

```sql
SET v_bonus = CASE v_job
    WHEN 'MANAGER'  THEN v_sal * 0.15
    WHEN 'SALESMAN' THEN v_sal * 0.10
    ELSE v_sal * 0.05
END;
```

Three loop forms. **WHILE** tests *before* the body:

```sql
WHILE i <= n DO
    SET v_result = v_result * i;
    SET i = i + 1;
END WHILE;
```
That accumulating loop is factorial (solved problem 1). **REPEAT** tests *after*
the body, so it always runs at least once: `REPEAT ... UNTIL i > n END REPEAT;`.
**LOOP** has no condition of its own — you label it and break out with `LEAVE`;
that is the form used for cursor loops below.

## Stored procedures — IN, OUT, INOUT

A procedure does work; it is invoked with `CALL`, not used in an expression.
Parameters have a mode:

- **IN** (default) — passed in, read-only inside.
- **OUT** — starts NULL, the procedure writes it, caller reads it back.
- **INOUT** — passed in, modified, read back.

```sql
CREATE PROCEDURE dept_emp_count(IN p_deptno INT, OUT p_cnt INT)
BEGIN
    SELECT COUNT(*) INTO p_cnt FROM emp WHERE deptno = p_deptno;
END
```
`CALL dept_emp_count(20, @n); SELECT @n;` returns 5 (RESEARCH has 5 employees).
A raise procedure — `CALL raise_dept_sal(30, 10)` — bumps every SALES salary 10%;
ALLEN goes 16000 → 17600, BLAKE 28500 → 31350. See `procedures.sql`.

> Sir hammered this: OUT/INOUT must be passed a *variable* (a `@var`), never a
> literal — the server needs somewhere to write the result back to.

## Stored functions — RETURNS, called in SQL

A function returns **one value** and can be used anywhere an expression is legal —
a `SELECT` list, a `WHERE`, an `ORDER BY`. It declares `RETURNS <type>`, uses `RETURN`.

```sql
CREATE FUNCTION annual_sal(p_empno INT) RETURNS DECIMAL(10,2)
READS SQL DATA
BEGIN
    DECLARE v_annual DECIMAL(10,2);
    SELECT sal * 12 + IFNULL(comm,0) INTO v_annual FROM emp WHERE empno = p_empno;
    RETURN v_annual;
END
```
Then `SELECT ename, annual_sal(empno) FROM emp;` — KING's annual is 600000.00.
A function must carry a **characteristic**: `DETERMINISTIC` (same input → same
output), or `READS SQL DATA` / `MODIFIES SQL DATA` when it touches tables. Without
one, a server with binary logging on refuses to create it (the
`log_bin_trust_function_creators` error). Exam line: a **function** returns a value
and is called in SQL; a **procedure** is called with `CALL` and can have multiple
OUT params.

## Cursors

A cursor lets a procedure walk a result set **row by row** — needed when the
per-row work can't be expressed as one set-based statement. Four steps: `DECLARE`
the cursor over a query, `OPEN`, `FETCH` a row into variables, `CLOSE`. When FETCH
runs past the last row it raises **NOT FOUND**; you catch that with a
`CONTINUE HANDLER` that sets a done-flag, and `LEAVE` the loop on it.

```sql
CREATE PROCEDURE build_bonuses()
BEGIN
    DECLARE v_done INT DEFAULT 0;
    DECLARE v_empno INT; DECLARE v_ename VARCHAR(20);
    DECLARE v_job VARCHAR(15); DECLARE v_sal DECIMAL(8,2);
    DECLARE cur CURSOR FOR SELECT empno, ename, job, sal FROM emp;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET v_done = 1;
    OPEN cur;
    read_loop: LOOP
        FETCH cur INTO v_empno, v_ename, v_job, v_sal;
        IF v_done = 1 THEN LEAVE read_loop; END IF;
        INSERT INTO emp_bonus VALUES (v_empno, v_ename, v_job,
            CASE v_job WHEN 'MANAGER' THEN v_sal*0.15 ELSE v_sal*0.05 END);
    END LOOP;
    CLOSE cur;
END
```
Order matters: the cursor DECLARE comes after variable DECLAREs but before the
HANDLER DECLARE. See `cursors.sql` for the full job-wise version.

> A cursor is a last resort — if a plain `UPDATE` or an aggregate can do the job in
> one statement, use that. Sir docked marks for a cursor where a `GROUP BY` fits.

## Triggers

A trigger is a stored program that fires **automatically** on a table event. You
pick the timing (`BEFORE` / `AFTER`) and the event (`INSERT` / `UPDATE` /
`DELETE`); it runs `FOR EACH ROW`. Inside, `NEW` is the incoming row and `OLD` is
the previous row:

| event  | OLD available | NEW available |
|--------|:-------------:|:-------------:|
| INSERT |       no      |      yes      |
| UPDATE |      yes      |      yes      |
| DELETE |      yes      |       no      |

Three typical uses:

- **Validation** — reject bad data with a `BEFORE INSERT`/`BEFORE UPDATE` that
  raises `SIGNAL`:
  ```sql
  CREATE TRIGGER trg_product_bi BEFORE INSERT ON product FOR EACH ROW
  BEGIN
      IF NEW.price <= 0 THEN
          SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'price must be positive';
      END IF;
  END
  ```
- **Auditing** — an `AFTER UPDATE` that writes the old and new values into a log
  table (`INSERT INTO product_audit VALUES (OLD.pid, OLD.price, NEW.price, NOW())`).
- **Maintaining a derived column** — a `BEFORE INSERT` that fills a column from
  others: `SET NEW.line_total = NEW.qty * NEW.unit_price;`. In a `BEFORE` trigger
  you may assign to `NEW.col`; in an `AFTER` trigger the row is already written, so
  you cannot. Both are in `triggers.sql`.

## Error handling — HANDLER and SIGNAL

`DECLARE ... HANDLER` catches a condition raised inside the block:

- `CONTINUE HANDLER` — run the handler body, then resume at the next statement.
- `EXIT HANDLER` — run the handler body, then leave the enclosing BEGIN…END.

You name the condition by MySQL error number (`1062` = duplicate key), by
`SQLSTATE` (`'23000'`), or by a named condition (`SQLEXCEPTION`, `NOT FOUND`).

```sql
CREATE PROCEDURE add_member(IN p_mid INT, IN p_name VARCHAR(20))
BEGIN
    DECLARE CONTINUE HANDLER FOR 1062
        SELECT CONCAT('duplicate id ', p_mid, ' ignored') AS msg;
    INSERT INTO member VALUES (p_mid, p_name);
END
```
Inserting an existing id no longer aborts — the handler reports it and execution
continues. To *raise* your own error use `SIGNAL SQLSTATE '45000'` (the generic
user-defined state) with a `MESSAGE_TEXT`. A caller can trap that SIGNAL with its
own handler and read the message back with `GET DIAGNOSTICS CONDITION 1 @m =
MESSAGE_TEXT;` — see `exceptions.sql`.

## Mapping to Oracle PL/SQL

The lab runs MySQL but the textbook is Oracle, so know both names.

| MySQL / MariaDB                    | Oracle PL/SQL                         |
|------------------------------------|---------------------------------------|
| `DELIMITER //` … `//`              | `/` on its own line to run a block    |
| `DECLARE v INT;` (top of block)    | `DECLARE v NUMBER;` (declare section)  |
| no direct `%TYPE`                  | `v emp.sal%TYPE;` anchors to a column  |
| `SELECT … INTO v`                  | `SELECT … INTO v` (same idea)          |
| `SELECT 'x';` to show a value      | `DBMS_OUTPUT.PUT_LINE('x');`           |
| `DECLARE … HANDLER FOR …`          | `EXCEPTION WHEN … THEN …`              |
| `SIGNAL SQLSTATE '45000'`          | `RAISE_APPLICATION_ERROR(-20001,'…')`  |
| NOT FOUND handler + done-flag loop | cursor `%NOTFOUND` in the loop test    |

Oracle's `%TYPE` has no clean MySQL equivalent — you repeat the column type by hand.

## Solved problems

**1. Write a function that returns n! using a loop, and show 5! and 0!.**

**Ans:** A `WHILE` loop multiplying 1..n, base result 1 so 0! = 1 falls out for free:
```sql
CREATE FUNCTION factorial(n INT) RETURNS BIGINT DETERMINISTIC
BEGIN
    DECLARE v_result BIGINT DEFAULT 1;
    DECLARE i INT DEFAULT 1;
    WHILE i <= n DO SET v_result = v_result * i; SET i = i + 1; END WHILE;
    RETURN v_result;
END
```
`SELECT factorial(5), factorial(0);` gives `120 | 1`. Verified.

**2. Keep a derived column in sync with a trigger: an invoice line's `line_total`
must always equal `qty * unit_price`, though the INSERT never supplies it.**

**Ans:** A `BEFORE INSERT` trigger sets `NEW.line_total` before the row is stored
(an `AFTER` trigger could not — the row is already written):
```sql
CREATE TRIGGER trg_invoice_bi BEFORE INSERT ON invoice FOR EACH ROW
    SET NEW.line_total = NEW.qty * NEW.unit_price;
```
`INSERT INTO invoice (inv_id, qty, unit_price) VALUES (1,3,45.00),(2,10,12.50);`
then `SELECT * FROM invoice;` shows line_total 135.00 and 125.00 — computed by the
trigger, never passed in. Verified.
