-- TCL demo: COMMIT, ROLLBACK, SAVEPOINT on a bank accounts table.
-- Run in one session (autocommit off) so the transaction boundaries hold.

DROP TABLE IF EXISTS accounts;

CREATE TABLE accounts (
    acc_no  INT PRIMARY KEY,
    name    VARCHAR(20),
    balance DECIMAL(10,2) NOT NULL CHECK (balance >= 0)
);

INSERT INTO accounts VALUES
 (101,'Ravi Kumar',50000),
 (102,'Anita',30000),
 (103,'Suresh',20000);

SET autocommit = 0;

-- 1. transfer 10000 from Ravi(101) to Anita(102), then COMMIT (made permanent)
START TRANSACTION;
UPDATE accounts SET balance = balance - 10000 WHERE acc_no = 101;
UPDATE accounts SET balance = balance + 10000 WHERE acc_no = 102;
COMMIT;
SELECT 'after commit' AS step, acc_no, name, balance FROM accounts ORDER BY acc_no;

-- 2. debit Suresh, then change our mind and ROLLBACK (nothing sticks)
START TRANSACTION;
UPDATE accounts SET balance = balance - 5000 WHERE acc_no = 103;
ROLLBACK;
SELECT 'after rollback' AS step, acc_no, name, balance FROM accounts ORDER BY acc_no;

-- 3. two transfers in one txn, undo only the second with ROLLBACK TO savepoint
START TRANSACTION;
UPDATE accounts SET balance = balance - 5000 WHERE acc_no = 101;
UPDATE accounts SET balance = balance + 5000 WHERE acc_no = 103;
SAVEPOINT sp1;
UPDATE accounts SET balance = balance - 3000 WHERE acc_no = 101;
UPDATE accounts SET balance = balance + 3000 WHERE acc_no = 102;
ROLLBACK TO sp1;   -- the Ravi->Anita 3000 is discarded, the Ravi->Suresh 5000 stays
COMMIT;
SELECT 'final' AS step, acc_no, name, balance FROM accounts ORDER BY acc_no;

SET autocommit = 1;
