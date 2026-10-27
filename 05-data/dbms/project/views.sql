-- Library Management System - views

CREATE OR REPLACE VIEW available_books AS
SELECT b.book_id,
       b.title,
       c.cname AS category,
       COUNT(cp.copy_id)              AS total_copies,
       SUM(cp.status = 'available')   AS available_copies
FROM books b
JOIN categories c   ON b.category_id = c.category_id
LEFT JOIN book_copies cp ON cp.book_id = b.book_id
GROUP BY b.book_id, b.title, c.cname;

CREATE OR REPLACE VIEW member_summary AS
SELECT m.member_id,
       m.mname,
       m.membership_type,
       COUNT(DISTINCT CASE WHEN l.return_date IS NULL THEN l.loan_id END) AS current_loans,
       COALESCE(SUM(CASE WHEN f.paid = 'N' THEN f.amount END), 0)         AS outstanding_fine
FROM members m
LEFT JOIN loans l ON l.member_id = m.member_id
LEFT JOIN fines f ON f.loan_id   = l.loan_id
GROUP BY m.member_id, m.mname, m.membership_type;

-- 2020-01-31 is the reporting date (project demo, end of the Jan 2020 session)
CREATE OR REPLACE VIEW overdue_report AS
SELECT l.loan_id,
       m.mname,
       b.title,
       l.due_date,
       DATEDIFF('2020-01-31', l.due_date) AS days_overdue
FROM loans l
JOIN book_copies cp ON l.copy_id = cp.copy_id
JOIN books b        ON cp.book_id = b.book_id
JOIN members m      ON l.member_id = m.member_id
WHERE l.return_date IS NULL
  AND l.due_date < '2020-01-31';
