-- BEFORE INSERT validation on emp (rejects a non-positive salary via SIGNAL) and
-- AFTER INSERT / AFTER UPDATE audit triggers writing to a log table.
-- load emp_dept.sql first, then this file.

DROP TRIGGER IF EXISTS trg_emp_bi;
DROP TRIGGER IF EXISTS trg_emp_ai;
DROP TRIGGER IF EXISTS trg_emp_au;
DROP PROCEDURE IF EXISTS try_hire;
DROP TABLE IF EXISTS emp_audit;

CREATE TABLE emp_audit (
    audit_id   INT AUTO_INCREMENT PRIMARY KEY,
    action     VARCHAR(10),
    empno      INT,
    old_sal    DECIMAL(8,2),
    new_sal    DECIMAL(8,2),
    changed_at DATETIME
);

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

-- only log a raise/cut, not an update that leaves sal unchanged
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

-- a valid hire fires the AFTER INSERT audit
INSERT INTO emp VALUES (7950,'NAIDU','CLERK',7782,'2020-01-20',10000,NULL,10);

-- a raise fires the AFTER UPDATE audit
UPDATE emp SET sal = 33000 WHERE empno = 7788;

SELECT empno, ename, sal FROM emp WHERE empno IN (7788, 7950) ORDER BY empno;
SELECT action, empno, old_sal, new_sal FROM emp_audit ORDER BY audit_id;

-- a non-positive salary is rejected by the BEFORE INSERT trigger; the SIGNAL
-- raises ERROR 1644 which would abort the script, so trap it inside a proc
DELIMITER //
CREATE PROCEDURE try_hire(IN p_empno INT, IN p_name VARCHAR(20), IN p_sal DECIMAL(8,2))
BEGIN
    DECLARE EXIT HANDLER FOR SQLSTATE '45000'
        SELECT CONCAT('rejected ', p_name, ' (sal ', p_sal, ')') AS result;
    INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
    VALUES (p_empno, p_name, 'CLERK', 7782, '2020-01-25', p_sal, NULL, 10);
    SELECT CONCAT('hired ', p_name) AS result;
END //
DELIMITER ;

CALL try_hire(7951, 'REKHA', 12000);
CALL try_hire(7952, 'BADVALUE', 0);

SELECT empno, ename, sal FROM emp WHERE empno >= 7950 ORDER BY empno;
SELECT action, empno, old_sal, new_sal FROM emp_audit ORDER BY audit_id;
