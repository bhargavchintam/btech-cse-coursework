# Experiment 11 — Triggers

**Date:** 08/01/2020

## Aim
Write a BEFORE INSERT trigger that rejects invalid data with SIGNAL, and AFTER INSERT / AFTER UPDATE
triggers that write an audit trail to a log table.

## Tools
MySQL 5.7 (college lab). Also runs on MariaDB.

## Schema
Uses the emp/dept schema from experiment 1 (`emp_dept.sql`). The triggers write into an `emp_audit`
log table built by this experiment (action, empno, old_sal, new_sal, changed_at).

## Program
`trg_emp_bi` blocks a non-positive salary before the row is inserted. `trg_emp_ai` logs every insert,
`trg_emp_au` logs an update only when the salary actually changed.

```sql
DELIMITER //

CREATE TRIGGER trg_emp_bi
BEFORE INSERT ON emp
FOR EACH ROW
BEGIN
    IF NEW.sal <= 0 THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'salary must be positive';
    END IF;
END //

CREATE TRIGGER trg_emp_ai
AFTER INSERT ON emp
FOR EACH ROW
BEGIN
    INSERT INTO emp_audit (action, empno, old_sal, new_sal, changed_at)
    VALUES ('INSERT', NEW.empno, NULL, NEW.sal, NOW());
END //

CREATE TRIGGER trg_emp_au
AFTER UPDATE ON emp
FOR EACH ROW
BEGIN
    IF NEW.sal <> OLD.sal THEN
        INSERT INTO emp_audit (action, empno, old_sal, new_sal, changed_at)
        VALUES ('UPDATE', OLD.empno, OLD.sal, NEW.sal, NOW());
    END IF;
END //

DELIMITER ;
```

## Result

A valid hire and a raise fire the AFTER triggers:

```sql
INSERT INTO emp VALUES (7950,'NAIDU','CLERK',7782,'2020-01-20',10000,NULL,10);
UPDATE emp SET sal = 33000 WHERE empno = 7788;
SELECT empno, ename, sal FROM emp WHERE empno IN (7788, 7950) ORDER BY empno;
```

```
empno  ename   sal
7788   SCOTT   33000.00
7950   NAIDU   10000.00
```

`SELECT action, empno, old_sal, new_sal FROM emp_audit ORDER BY audit_id;`

```
action  empno  old_sal   new_sal
INSERT  7950   NULL      10000.00
UPDATE  7788   30000.00  33000.00
```

The BEFORE INSERT trigger rejects a zero salary. The SIGNAL raises ERROR 1644, so the bad insert is
routed through `try_hire`, whose handler traps it (a valid hire goes through, the bad one is refused):

```sql
CALL try_hire(7951, 'REKHA', 12000);
CALL try_hire(7952, 'BADVALUE', 0);
```

```
result
hired REKHA

result
rejected BADVALUE (sal 0.00)
```

Final state — REKHA is in, BADVALUE never was, and the audit log has a third row for the REKHA insert:

```
empno  ename   sal
7950   NAIDU   10000.00
7951   REKHA   12000.00

action  empno  old_sal   new_sal
INSERT  7950   NULL      10000.00
UPDATE  7788   30000.00  33000.00
INSERT  7951   NULL      12000.00
```

## Result
The audit table captured the insert and the raise; the BEFORE INSERT trigger rejected the zero-salary
row via SIGNAL, so it left no audit entry.
