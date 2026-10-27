# Experiment 9 — Cursors

**Date:** 11/12/2019

## Aim
Use a cursor to walk every employee, build a payslip row for each (gross, PF, net) with a
running net total, and roll the totals into a summary table.

## Tools
MySQL 5.7 (college lab). Also runs on MariaDB.

## Schema
Uses the emp/dept schema from experiment 1 (`emp_dept.sql`). The procedure builds two of its own
tables — `payslip` (one row per employee, with a `running_net` column) and `pay_summary` (one totals row).

## Program
A `LOOP` fetches from the cursor and exits on the `NOT FOUND` handler. For each row
gross = sal + comm, PF = 12% of sal, net = gross − PF, and `running_net` accumulates net as the
cursor advances.

```sql
DELIMITER //
CREATE PROCEDURE generate_payslips()
BEGIN
    DECLARE v_done  INT DEFAULT 0;
    DECLARE v_empno INT;
    DECLARE v_ename VARCHAR(20);
    DECLARE v_sal   DECIMAL(8,2);
    DECLARE v_comm  DECIMAL(8,2);
    DECLARE v_gross DECIMAL(10,2);
    DECLARE v_pf    DECIMAL(10,2);
    DECLARE v_net   DECIMAL(10,2);
    DECLARE v_run   DECIMAL(12,2) DEFAULT 0;
    DECLARE v_sl    INT DEFAULT 0;

    DECLARE cur CURSOR FOR SELECT empno, ename, sal, comm FROM emp ORDER BY empno;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET v_done = 1;

    OPEN cur;
    read_loop: LOOP
        FETCH cur INTO v_empno, v_ename, v_sal, v_comm;
        IF v_done = 1 THEN
            LEAVE read_loop;
        END IF;

        SET v_gross = v_sal + IFNULL(v_comm, 0);
        SET v_pf    = v_sal * 0.12;
        SET v_net   = v_gross - v_pf;
        SET v_run   = v_run + v_net;
        SET v_sl    = v_sl + 1;

        INSERT INTO payslip VALUES (v_sl, v_empno, v_ename, v_gross, v_pf, v_net, v_run);
    END LOOP;
    CLOSE cur;

    INSERT INTO pay_summary
    SELECT COUNT(*), SUM(gross), SUM(pf), SUM(net) FROM payslip;
END //
DELIMITER ;

CALL generate_payslips();
```

## Result

`SELECT * FROM payslip ORDER BY slno;`

```
slno  empno  ename   gross      pf       net       running_net
1     7369   SMITH    8000.00    960.00    7040.00    7040.00
2     7499   ALLEN   19000.00   1920.00   17080.00   24120.00
3     7521   WARD    17500.00   1500.00   16000.00   40120.00
4     7566   JONES   29750.00   3570.00   26180.00   66300.00
5     7654   MARTIN  26500.00   1500.00   25000.00   91300.00
6     7698   BLAKE   28500.00   3420.00   25080.00  116380.00
7     7782   CLARK   24500.00   2940.00   21560.00  137940.00
8     7788   SCOTT   30000.00   3600.00   26400.00  164340.00
9     7839   KING    50000.00   6000.00   44000.00  208340.00
10    7844   TURNER  15000.00   1800.00   13200.00  221540.00
11    7876   ADAMS   11000.00   1320.00    9680.00  231220.00
12    7900   JAMES    9500.00   1140.00    8360.00  239580.00
13    7902   FORD    30000.00   3600.00   26400.00  265980.00
14    7934   MILLER  13000.00   1560.00   11440.00  277420.00
```

`SELECT * FROM pay_summary;`

```
emps  total_gross  total_pf   total_net
14     312250.00   34830.00   277420.00
```

The `running_net` on the last row (277420.00) equals `total_net` in the summary — the cursor's running
total and the aggregate agree.
