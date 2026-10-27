-- Library Management System - stored procedures

DELIMITER //

DROP PROCEDURE IF EXISTS issue_book //
CREATE PROCEDURE issue_book(IN p_member INT, IN p_copy INT, IN p_staff INT)
BEGIN
    DECLARE v_status VARCHAR(10);
    DECLARE v_loan   INT;
    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        ROLLBACK;
        RESIGNAL;
    END;

    START TRANSACTION;

    SELECT status INTO v_status FROM book_copies WHERE copy_id = p_copy FOR UPDATE;
    IF v_status IS NULL THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'no such copy';
    ELSEIF v_status <> 'available' THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'copy not available';
    END IF;

    SELECT COALESCE(MAX(loan_id), 0) + 1 INTO v_loan FROM loans;
    -- the before-insert trigger re-checks fines/availability, the after-insert
    -- trigger flips the copy to 'issued'
    INSERT INTO loans (loan_id, copy_id, member_id, staff_id, issue_date, due_date, return_date)
    VALUES (v_loan, p_copy, p_member, p_staff, CURDATE(), DATE_ADD(CURDATE(), INTERVAL 14 DAY), NULL);

    COMMIT;
END //

DROP PROCEDURE IF EXISTS return_book //
CREATE PROCEDURE return_book(IN p_loan INT)
BEGIN
    DECLARE v_due  DATE;
    DECLARE v_ret  DATE;
    DECLARE v_days INT;
    DECLARE v_fid  INT;
    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        ROLLBACK;
        RESIGNAL;
    END;

    START TRANSACTION;

    SELECT due_date, return_date INTO v_due, v_ret FROM loans WHERE loan_id = p_loan FOR UPDATE;
    IF v_due IS NULL THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'no such loan';
    ELSEIF v_ret IS NOT NULL THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'loan already returned';
    END IF;

    UPDATE loans SET return_date = CURDATE() WHERE loan_id = p_loan;

    SET v_days = DATEDIFF(CURDATE(), v_due);
    IF v_days > 0 THEN
        SELECT COALESCE(MAX(fine_id), 0) + 1 INTO v_fid FROM fines;
        INSERT INTO fines (fine_id, loan_id, amount, paid, paid_date)
        VALUES (v_fid, p_loan, v_days * 2, 'N', NULL);
    END IF;

    COMMIT;
END //

DROP PROCEDURE IF EXISTS member_report //
CREATE PROCEDURE member_report(IN p_member INT)
BEGIN
    SELECT member_id, mname, membership_type, city
    FROM members WHERE member_id = p_member;

    SELECT l.loan_id, b.title, l.issue_date, l.due_date, l.return_date
    FROM loans l
    JOIN book_copies cp ON l.copy_id = cp.copy_id
    JOIN books b        ON cp.book_id = b.book_id
    WHERE l.member_id = p_member
    ORDER BY l.issue_date;

    SELECT COALESCE(SUM(CASE WHEN f.paid = 'N' THEN f.amount END), 0) AS outstanding_fine
    FROM fines f
    JOIN loans l ON f.loan_id = l.loan_id
    WHERE l.member_id = p_member;
END //

DELIMITER ;
