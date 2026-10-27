-- stored functions called from a SELECT: one reads emp, one is a pure computation.
-- load emp_dept.sql first, then this file.

DROP FUNCTION IF EXISTS annual_sal;
DROP FUNCTION IF EXISTS sal_grade;

DELIMITER //

CREATE FUNCTION annual_sal(p_empno INT) RETURNS DECIMAL(10,2)
READS SQL DATA
BEGIN
    DECLARE v_annual DECIMAL(10,2);
    SELECT sal * 12 + IFNULL(comm,0) INTO v_annual
    FROM emp WHERE empno = p_empno;
    RETURN v_annual;
END //

CREATE FUNCTION sal_grade(p_sal DECIMAL(8,2)) RETURNS CHAR(1)
DETERMINISTIC
BEGIN
    DECLARE v_grade CHAR(1);
    IF p_sal >= 30000 THEN
        SET v_grade = 'A';
    ELSEIF p_sal >= 20000 THEN
        SET v_grade = 'B';
    ELSEIF p_sal >= 12000 THEN
        SET v_grade = 'C';
    ELSE
        SET v_grade = 'D';
    END IF;
    RETURN v_grade;
END //

DELIMITER ;

SELECT ename, sal, annual_sal(empno) AS annual, sal_grade(sal) AS grade
FROM emp
ORDER BY empno;
