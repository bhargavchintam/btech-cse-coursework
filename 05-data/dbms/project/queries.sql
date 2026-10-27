-- Library Management System - reports

-- currently issued books (not yet returned)
SELECT l.loan_id, m.mname, b.title, l.issue_date, l.due_date
FROM loans l
JOIN book_copies cp ON l.copy_id = cp.copy_id
JOIN books b        ON cp.book_id = b.book_id
JOIN members m      ON l.member_id = m.member_id
WHERE l.return_date IS NULL
ORDER BY l.due_date;

-- overdue loans with days overdue and fine at Rs 2/day, as of 2020-01-31
SELECT l.loan_id, m.mname, b.title, l.due_date,
       DATEDIFF('2020-01-31', l.due_date)     AS days_overdue,
       DATEDIFF('2020-01-31', l.due_date) * 2 AS fine
FROM loans l
JOIN book_copies cp ON l.copy_id = cp.copy_id
JOIN books b        ON cp.book_id = b.book_id
JOIN members m      ON l.member_id = m.member_id
WHERE l.return_date IS NULL
  AND l.due_date < '2020-01-31'
ORDER BY days_overdue DESC;

-- most borrowed books (top 5)
SELECT b.title, COUNT(*) AS times_borrowed
FROM loans l
JOIN book_copies cp ON l.copy_id = cp.copy_id
JOIN books b        ON cp.book_id = b.book_id
GROUP BY b.book_id, b.title
ORDER BY times_borrowed DESC, b.title
LIMIT 5;

-- members with unpaid fines
SELECT m.member_id, m.mname, SUM(f.amount) AS outstanding
FROM fines f
JOIN loans l   ON f.loan_id  = l.loan_id
JOIN members m ON l.member_id = m.member_id
WHERE f.paid = 'N'
GROUP BY m.member_id, m.mname
ORDER BY outstanding DESC;

-- available copies per title
SELECT b.title,
       SUM(cp.status = 'available') AS available,
       COUNT(*)                     AS total
FROM books b
JOIN book_copies cp ON cp.book_id = b.book_id
GROUP BY b.book_id, b.title
ORDER BY b.title;

-- books written by R.K. Narayan
SELECT b.title, b.pub_year
FROM books b
JOIN book_authors ba ON b.book_id = ba.book_id
JOIN authors a       ON ba.author_id = a.author_id
WHERE a.aname = 'R.K. Narayan'
ORDER BY b.pub_year;

-- fine collected per month
SELECT DATE_FORMAT(paid_date, '%Y-%m') AS month, SUM(amount) AS collected
FROM fines
WHERE paid = 'Y'
GROUP BY DATE_FORMAT(paid_date, '%Y-%m')
ORDER BY month;
