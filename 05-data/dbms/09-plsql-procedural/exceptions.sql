-- error handling: a CONTINUE HANDLER catching a duplicate-key error, and a
-- custom SIGNAL trapped by an EXIT HANDLER with GET DIAGNOSTICS.
-- self-contained: builds its own member table.

DROP TABLE IF EXISTS member;
DROP PROCEDURE IF EXISTS add_member;
DROP PROCEDURE IF EXISTS withdraw;
DROP PROCEDURE IF EXISTS try_withdraw;

CREATE TABLE member (
    mid  INT PRIMARY KEY,
    name VARCHAR(20)
);
INSERT INTO member VALUES (1,'Ravi Kumar'),(2,'Anita');

DELIMITER //

-- 1062 = ER_DUP_ENTRY; swallow it and carry on instead of aborting
CREATE PROCEDURE add_member(IN p_mid INT, IN p_name VARCHAR(20))
BEGIN
    DECLARE CONTINUE HANDLER FOR 1062
        SELECT CONCAT('duplicate id ', p_mid, ' ignored') AS msg;
    INSERT INTO member VALUES (p_mid, p_name);
END //

-- raises a custom application error
CREATE PROCEDURE withdraw(IN p_bal DECIMAL(10,2), IN p_amt DECIMAL(10,2))
BEGIN
    IF p_amt > p_bal THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'insufficient funds';
    END IF;
    SELECT p_bal - p_amt AS new_balance;
END //

-- calls withdraw and traps the SIGNAL, reading its message back out
CREATE PROCEDURE try_withdraw(IN p_bal DECIMAL(10,2), IN p_amt DECIMAL(10,2))
BEGIN
    DECLARE EXIT HANDLER FOR SQLSTATE '45000'
    BEGIN
        GET DIAGNOSTICS CONDITION 1 @msg = MESSAGE_TEXT;
        SELECT CONCAT('blocked: ', @msg) AS result;
    END;
    CALL withdraw(p_bal, p_amt);
END //

DELIMITER ;

CALL add_member(3, 'Suresh');
CALL add_member(1, 'Duplicate');
SELECT * FROM member ORDER BY mid;

CALL try_withdraw(5000, 2000);
CALL try_withdraw(5000, 9000);
