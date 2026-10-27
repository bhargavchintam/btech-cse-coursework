# Experiment 12 — Exception Handling

**Date:** 15/01/2020

## Aim
Use MySQL condition handlers to catch a duplicate-key error and a not-found case, and raise a custom
error with SIGNAL, trapping it in the caller.

## Tools
MySQL 5.7 (college lab). Also runs on MariaDB.

## Schema
Self-contained — builds a small `account(accno, holder, balance)` table seeded with two rows.

## Program
`open_account` has a CONTINUE HANDLER FOR 1062 (duplicate key). `get_balance` uses a NOT FOUND handler
so a missing account is reported instead of leaving the variable stale. `withdraw` raises a custom
SIGNAL on overdraw, and `try_withdraw` traps it with an EXIT HANDLER, reading the message via
GET DIAGNOSTICS.

```sql
DELIMITER //

CREATE PROCEDURE open_account(IN p_accno INT, IN p_holder VARCHAR(20), IN p_bal DECIMAL(10,2))
BEGIN
    DECLARE CONTINUE HANDLER FOR 1062
        SELECT CONCAT('account ', p_accno, ' already exists') AS msg;
    INSERT INTO account VALUES (p_accno, p_holder, p_bal);
END //

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
```

## Result

Duplicate-key caught — the first call inserts silently, the second clashes on accno 101:

```sql
CALL open_account(103, 'Suresh', 3000);
CALL open_account(101, 'Clash', 999);
SELECT * FROM account ORDER BY accno;
```

```
msg
account 101 already exists

accno  holder      balance
101    Ravi Kumar  5000.00
102    Anita       8000.00
103    Suresh      3000.00
```

Not-found caught — 102 exists, 500 does not:

```sql
CALL get_balance(102);
CALL get_balance(500);
```

```
accno  balance
102    8000.00

result
no account 500
```

Custom SIGNAL — the first withdrawal is allowed, the second overdraws and is blocked by the handler:

```sql
CALL try_withdraw(102, 2000);
CALL try_withdraw(102, 100000);
SELECT * FROM account ORDER BY accno;
```

```
result
withdrew 2000.00 from 102

result
blocked: insufficient funds

accno  holder      balance
101    Ravi Kumar  5000.00
102    Anita       6000.00
103    Suresh      3000.00
```

## Result
All three handlers behaved: the duplicate insert was swallowed and 101 kept its original balance, the
missing account was reported, and the overdraw was blocked so 102 only lost the valid 2000.
