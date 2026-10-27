-- cursor loop: walk every employee, work out a bonus from the job, store one row each.
-- load emp_dept.sql first, then this file.

DROP PROCEDURE IF EXISTS build_bonuses;
DROP TABLE IF EXISTS emp_bonus;

CREATE TABLE emp_bonus (
    empno INT PRIMARY KEY,
    ename VARCHAR(20),
    job   VARCHAR(15),
    bonus DECIMAL(10,2)
);

DELIMITER //

CREATE PROCEDURE build_bonuses()
BEGIN
    DECLARE v_done  INT DEFAULT 0;
    DECLARE v_empno INT;
    DECLARE v_ename VARCHAR(20);
    DECLARE v_job   VARCHAR(15);
    DECLARE v_sal   DECIMAL(8,2);
    DECLARE v_bonus DECIMAL(10,2);

    DECLARE cur CURSOR FOR SELECT empno, ename, job, sal FROM emp;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET v_done = 1;

    OPEN cur;
    read_loop: LOOP
        FETCH cur INTO v_empno, v_ename, v_job, v_sal;
        IF v_done = 1 THEN
            LEAVE read_loop;
        END IF;

        SET v_bonus = CASE v_job
            WHEN 'MANAGER'  THEN v_sal * 0.15
            WHEN 'ANALYST'  THEN v_sal * 0.12
            WHEN 'SALESMAN' THEN v_sal * 0.10
            ELSE v_sal * 0.05
        END;

        INSERT INTO emp_bonus VALUES (v_empno, v_ename, v_job, v_bonus);
    END LOOP;
    CLOSE cur;
END //

DELIMITER ;

CALL build_bonuses();
SELECT * FROM emp_bonus ORDER BY empno;
