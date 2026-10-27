# Experiment 10 — Stored Procedures and Functions

**Date:** 18/12/2019

## Aim
Write a stored procedure with IN and OUT parameters, and a stored function that can be called
from inside a SELECT.

## Tools
MySQL 5.7 (college lab). Also runs on MariaDB.

## Schema
Uses the emp/dept schema from experiment 1 (`emp_dept.sql`).

## Program
`dept_pay_summary` takes a department number (IN) and returns headcount and total salary through
two OUT parameters. `income_tax` is a deterministic function that returns tax by salary slab and is
evaluated once per row when used in a SELECT.

```sql
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
```

## Result

Procedure — the OUT params for department 20 (RESEARCH) come back in user variables (5 employees,
total salary 108750.00):

```sql
CALL dept_pay_summary(20, @head, @total);
SELECT @head AS research_emps, @total AS research_salary;
```

```
research_emps  research_salary
5              108750.00
```

Function — called for every row of the SELECT:

```sql
SELECT ename, sal, income_tax(sal) AS tax FROM emp ORDER BY empno;
```

```
ename   sal        tax
SMITH    8000.00      0.00
ALLEN   16000.00      0.00
WARD    12500.00      0.00
JONES   29750.00   2975.00
MARTIN  12500.00      0.00
BLAKE   28500.00   2850.00
CLARK   24500.00   2450.00
SCOTT   30000.00   6000.00
KING    50000.00  10000.00
TURNER  15000.00      0.00
ADAMS   11000.00      0.00
JAMES    9500.00      0.00
FORD    30000.00   6000.00
MILLER  13000.00      0.00
```

Both work: the procedure hands headcount and total back through OUT parameters, and the function is
applied per row, taxing each salary by its slab (0 below 20000, 10% from 20000, 20% from 30000).
