-- a stored PROCEDURE with IN/OUT params and a stored FUNCTION called inside a SELECT.
-- load emp_dept.sql first, then this file.

DROP PROCEDURE IF EXISTS dept_pay_summary;
DROP FUNCTION IF EXISTS income_tax;

DELIMITER //

CREATE PROCEDURE dept_pay_summary(IN p_deptno INT, OUT p_head INT, OUT p_total DECIMAL(12,2))
BEGIN
    SELECT COUNT(*), SUM(sal)
    INTO p_head, p_total
    FROM emp
    WHERE deptno = p_deptno;
END //

CREATE FUNCTION income_tax(p_sal DECIMAL(8,2)) RETURNS DECIMAL(10,2)
DETERMINISTIC
BEGIN
    DECLARE v_tax DECIMAL(10,2);
    IF p_sal >= 30000 THEN
        SET v_tax = p_sal * 0.20;
    ELSEIF p_sal >= 20000 THEN
        SET v_tax = p_sal * 0.10;
    ELSE
        SET v_tax = 0;
    END IF;
    RETURN v_tax;
END //

DELIMITER ;

-- OUT params come back in user variables
CALL dept_pay_summary(20, @head, @total);
SELECT @head AS research_emps, @total AS research_salary;

-- the function is evaluated for every row of the result
SELECT ename, sal, income_tax(sal) AS tax
FROM emp
ORDER BY empno;
