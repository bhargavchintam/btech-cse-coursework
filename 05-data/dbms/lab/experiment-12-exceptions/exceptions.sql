-- condition handlers: a duplicate-key CONTINUE HANDLER, a NOT FOUND handler, and a
-- custom SIGNAL trapped by an EXIT HANDLER that reads the message with GET DIAGNOSTICS.
-- self-contained: builds its own account table.

DROP PROCEDURE IF EXISTS open_account;
DROP PROCEDURE IF EXISTS get_balance;
DROP PROCEDURE IF EXISTS withdraw;
DROP PROCEDURE IF EXISTS try_withdraw;
DROP TABLE IF EXISTS account;

CREATE TABLE account (
    accno   INT PRIMARY KEY,
    holder  VARCHAR(20),
    balance DECIMAL(10,2)
);
INSERT INTO account VALUES (101,'Ravi Kumar',5000),(102,'Anita',8000);

DELIMITER //

-- 1062 = ER_DUP_ENTRY: swallow the duplicate accno and carry on
CREATE PROCEDURE open_account(IN p_accno INT, IN p_holder VARCHAR(20), IN p_bal DECIMAL(10,2))
BEGIN
    DECLARE CONTINUE HANDLER FOR 1062
        SELECT CONCAT('account ', p_accno, ' already exists') AS msg;
    INSERT INTO account VALUES (p_accno, p_holder, p_bal);
END //

-- SELECT ... INTO with no matching row trips the NOT FOUND handler
CREATE PROCEDURE get_balance(IN p_accno INT)
BEGIN
    DECLARE v_bal   DECIMAL(10,2);
    DECLARE v_found INT DEFAULT 1;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET v_found = 0;

    SELECT balance INTO v_bal FROM account WHERE accno = p_accno;
    IF v_found = 0 THEN
        SELECT CONCAT('no account ', p_accno) AS result;
    ELSE
        SELECT p_accno AS accno, v_bal AS balance;
    END IF;
END //

-- raises a custom application error when the debit exceeds the balance
CREATE PROCEDURE withdraw(IN p_accno INT, IN p_amt DECIMAL(10,2))
BEGIN
    DECLARE v_bal DECIMAL(10,2);
    SELECT balance INTO v_bal FROM account WHERE accno = p_accno;
    IF p_amt > v_bal THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'insufficient funds';
    END IF;
    UPDATE account SET balance = balance - p_amt WHERE accno = p_accno;
END //

-- calls withdraw and traps the SIGNAL, reading its message back out
CREATE PROCEDURE try_withdraw(IN p_accno INT, IN p_amt DECIMAL(10,2))
BEGIN
    DECLARE EXIT HANDLER FOR SQLSTATE '45000'
    BEGIN
        GET DIAGNOSTICS CONDITION 1 @msg = MESSAGE_TEXT;
        SELECT CONCAT('blocked: ', @msg) AS result;
    END;
    CALL withdraw(p_accno, p_amt);
    SELECT CONCAT('withdrew ', p_amt, ' from ', p_accno) AS result;
END //

DELIMITER ;

-- duplicate-key caught: the second call clashes on accno 101
CALL open_account(103, 'Suresh', 3000);
CALL open_account(101, 'Clash', 999);
SELECT * FROM account ORDER BY accno;

-- not-found caught: 500 does not exist
CALL get_balance(102);
CALL get_balance(500);

-- custom SIGNAL: first withdrawal allowed, second blocked
CALL try_withdraw(102, 2000);
CALL try_withdraw(102, 100000);
SELECT * FROM account ORDER BY accno;
