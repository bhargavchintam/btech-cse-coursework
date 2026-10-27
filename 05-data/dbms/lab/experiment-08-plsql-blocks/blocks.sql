-- experiment 8: stored blocks with control flow (IF / CASE / WHILE),
-- local variables and SELECT INTO. run emp_dept.sql first, then this file.

DROP PROCEDURE IF EXISTS classify_emp;
DROP PROCEDURE IF EXISTS grade_of;
DROP PROCEDURE IF EXISTS sum_upto;

DELIMITER //

-- IF / ELSEIF: read one employee's salary with SELECT INTO and band it
CREATE PROCEDURE classify_emp(IN p_empno INT, OUT p_band VARCHAR(10))
BEGIN
    DECLARE v_sal DECIMAL(8,2);
    SELECT sal INTO v_sal FROM emp WHERE empno = p_empno;
    IF v_sal >= 30000 THEN
        SET p_band = 'HIGH';
    ELSEIF v_sal >= 15000 THEN
        SET p_band = 'MEDIUM';
    ELSE
        SET p_band = 'LOW';
    END IF;
END //

-- CASE: map a job title to a rough grade
CREATE PROCEDURE grade_of(IN p_job VARCHAR(15), OUT p_grade CHAR(1))
BEGIN
    CASE p_job
        WHEN 'PRESIDENT' THEN SET p_grade = 'A';
        WHEN 'MANAGER'   THEN SET p_grade = 'B';
        WHEN 'ANALYST'   THEN SET p_grade = 'B';
        WHEN 'SALESMAN'  THEN SET p_grade = 'C';
        ELSE SET p_grade = 'D';
    END CASE;
END //

-- WHILE: accumulate 1..n in a loop and return the running total
CREATE PROCEDURE sum_upto(IN p_n INT, OUT p_total INT)
BEGIN
    DECLARE i INT DEFAULT 1;
    SET p_total = 0;
    WHILE i <= p_n DO
        SET p_total = p_total + i;
        SET i = i + 1;
    END WHILE;
END //

DELIMITER ;

CALL classify_emp(7839, @b);
SELECT 'KING' AS ename, @b AS band;
CALL classify_emp(7844, @b);
SELECT 'TURNER' AS ename, @b AS band;
CALL classify_emp(7369, @b);
SELECT 'SMITH' AS ename, @b AS band;

CALL grade_of('MANAGER', @g);
SELECT 'MANAGER' AS job, @g AS grade;
CALL grade_of('CLERK', @g);
SELECT 'CLERK' AS job, @g AS grade;

CALL sum_upto(10, @t);
SELECT @t AS sum_1_to_10;
