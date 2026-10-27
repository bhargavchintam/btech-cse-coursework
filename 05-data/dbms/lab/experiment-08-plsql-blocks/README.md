# Experiment 8 — PL/SQL Blocks (Control Flow)

**Date:** 04/12/2019

## Aim
Write stored blocks that use IF, CASE and WHILE control flow, local variables and
SELECT INTO. (MySQL keeps procedural code inside stored routines rather than
standalone anonymous blocks like Oracle PL/SQL, so each block is a small procedure.)

## Tools
MySQL 5.7 (college lab). Also runs on MariaDB.

## Schema
Uses the emp/dept schema from experiment 1. Run `emp_dept.sql`, then `blocks.sql`.

## Queries

**1. IF / ELSEIF with SELECT INTO — band an employee's salary.**
```sql
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
```
Called for KING (50000), TURNER (15000) and SMITH (8000):
```
ename   band
KING    HIGH
TURNER  MEDIUM
SMITH   LOW
```

**2. CASE — map a job title to a grade.**
```sql
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
```
Called for MANAGER and CLERK:
```
job      grade
MANAGER  B
CLERK    D
```
CLERK is not listed, so the ELSE branch gives D.

**3. WHILE — accumulate 1..n in a loop.**
```sql
CREATE PROCEDURE sum_upto(IN p_n INT, OUT p_total INT)
BEGIN
    DECLARE i INT DEFAULT 1;
    SET p_total = 0;
    WHILE i <= p_n DO
        SET p_total = p_total + i;
        SET i = i + 1;
    END WHILE;
END //
```
Called with 10:
```
sum_1_to_10
55
```

## Result
Three stored blocks ran, one per control structure: IF/ELSEIF banded salaries read
by SELECT INTO, CASE mapped jobs to grades, and a WHILE loop summed 1..10 to 55.
Values come back through OUT parameters read into user variables.
