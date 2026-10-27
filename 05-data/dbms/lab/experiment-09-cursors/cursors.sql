-- cursor over emp: build a payslip for each employee with a running net total,
-- then roll the totals into a summary table.
-- load emp_dept.sql first, then this file.

DROP PROCEDURE IF EXISTS generate_payslips;
DROP TABLE IF EXISTS payslip;
DROP TABLE IF EXISTS pay_summary;

CREATE TABLE payslip (
    slno        INT,
    empno       INT,
    ename       VARCHAR(20),
    gross       DECIMAL(10,2),
    pf          DECIMAL(10,2),
    net         DECIMAL(10,2),
    running_net DECIMAL(12,2)
);

CREATE TABLE pay_summary (
    emps        INT,
    total_gross DECIMAL(12,2),
    total_pf    DECIMAL(12,2),
    total_net   DECIMAL(12,2)
);

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
        SET v_pf    = v_sal * 0.12;             -- PF is 12% of basic
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
SELECT * FROM payslip ORDER BY slno;
SELECT * FROM pay_summary;
