-- stored procedures on emp/dept: IN, OUT and INOUT parameters, with CALLs.
-- load emp_dept.sql first, then this file.

DROP PROCEDURE IF EXISTS raise_dept_sal;
DROP PROCEDURE IF EXISTS dept_emp_count;
DROP PROCEDURE IF EXISTS apply_bonus;

DELIMITER //

CREATE PROCEDURE raise_dept_sal(IN p_deptno INT, IN p_pct DECIMAL(5,2))
BEGIN
    UPDATE emp
    SET sal = sal + sal * p_pct / 100
    WHERE deptno = p_deptno;
END //

CREATE PROCEDURE dept_emp_count(IN p_deptno INT, OUT p_cnt INT)
BEGIN
    SELECT COUNT(*) INTO p_cnt
    FROM emp
    WHERE deptno = p_deptno;
END //

CREATE PROCEDURE apply_bonus(INOUT p_amount DECIMAL(10,2), IN p_times INT)
BEGIN
    SET p_amount = p_amount * p_times;
END //

DELIMITER ;

-- OUT param: headcount comes back in a user variable
CALL dept_emp_count(20, @n);
SELECT @n AS research_headcount;

-- IN params: 10% raise to everyone in SALES(30), shown before and after
SELECT ename, sal FROM emp WHERE deptno = 30 ORDER BY empno;
CALL raise_dept_sal(30, 10);
SELECT ename, sal FROM emp WHERE deptno = 30 ORDER BY empno;

-- INOUT: the same variable is passed in, modified and read back
SET @amt = 1000;
CALL apply_bonus(@amt, 3);
SELECT @amt AS tripled;
