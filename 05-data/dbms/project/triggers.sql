-- Library Management System - triggers

DELIMITER //

-- validation before a loan is created: copy must be free and the member must
-- not owe more than Rs 50 in unpaid fines
DROP TRIGGER IF EXISTS trg_loan_before_insert //
CREATE TRIGGER trg_loan_before_insert
BEFORE INSERT ON loans
FOR EACH ROW
BEGIN
    DECLARE v_status VARCHAR(10);
    DECLARE v_unpaid DECIMAL(9,2);

    SELECT status INTO v_status FROM book_copies WHERE copy_id = NEW.copy_id;
    IF v_status <> 'available' THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'copy is not available for issue';
    END IF;

    SELECT COALESCE(SUM(f.amount), 0) INTO v_unpaid
    FROM fines f
    JOIN loans l ON f.loan_id = l.loan_id
    WHERE l.member_id = NEW.member_id AND f.paid = 'N';
    IF v_unpaid > 50 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'member has unpaid fines over the limit';
    END IF;
END //

DROP TRIGGER IF EXISTS trg_loan_after_insert //
CREATE TRIGGER trg_loan_after_insert
AFTER INSERT ON loans
FOR EACH ROW
BEGIN
    UPDATE book_copies SET status = 'issued' WHERE copy_id = NEW.copy_id;
END //

DROP TRIGGER IF EXISTS trg_loan_after_update //
CREATE TRIGGER trg_loan_after_update
AFTER UPDATE ON loans
FOR EACH ROW
BEGIN
    IF NEW.return_date IS NOT NULL AND OLD.return_date IS NULL THEN
        UPDATE book_copies SET status = 'available' WHERE copy_id = NEW.copy_id;
    END IF;
END //

DELIMITER ;
