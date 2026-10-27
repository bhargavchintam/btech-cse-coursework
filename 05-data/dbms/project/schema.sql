-- Library Management System - schema (3NF)

DROP TABLE IF EXISTS fines;
DROP TABLE IF EXISTS loans;
DROP TABLE IF EXISTS book_copies;
DROP TABLE IF EXISTS book_authors;
DROP TABLE IF EXISTS books;
DROP TABLE IF EXISTS staff;
DROP TABLE IF EXISTS members;
DROP TABLE IF EXISTS categories;
DROP TABLE IF EXISTS authors;
DROP TABLE IF EXISTS publishers;

CREATE TABLE publishers (
    publisher_id INT PRIMARY KEY,
    pname        VARCHAR(50) NOT NULL,
    city         VARCHAR(25),
    phone        VARCHAR(15)
);

CREATE TABLE authors (
    author_id INT PRIMARY KEY,
    aname     VARCHAR(40) NOT NULL,
    country   VARCHAR(25) DEFAULT 'India'
);

CREATE TABLE categories (
    category_id INT PRIMARY KEY,
    cname       VARCHAR(30) NOT NULL UNIQUE
);

CREATE TABLE members (
    member_id       INT PRIMARY KEY,
    mname           VARCHAR(40) NOT NULL,
    email           VARCHAR(50) UNIQUE,
    phone           VARCHAR(15),
    city            VARCHAR(25),
    join_date       DATE NOT NULL,
    membership_type VARCHAR(10) NOT NULL DEFAULT 'student'
);

CREATE TABLE staff (
    staff_id  INT PRIMARY KEY,
    sname     VARCHAR(40) NOT NULL,
    role      VARCHAR(25),
    email     VARCHAR(50),
    hire_date DATE
);

CREATE TABLE books (
    book_id      INT PRIMARY KEY,
    title        VARCHAR(80) NOT NULL,
    isbn         VARCHAR(20) UNIQUE,
    category_id  INT,
    publisher_id INT,
    pub_year     INT,
    price        DECIMAL(7,2) CHECK (price > 0),
    FOREIGN KEY (category_id)  REFERENCES categories(category_id),
    FOREIGN KEY (publisher_id) REFERENCES publishers(publisher_id)
);

-- a book can have several authors and an author writes several books,
-- so the M:N is broken out into its own table
CREATE TABLE book_authors (
    book_id   INT,
    author_id INT,
    PRIMARY KEY (book_id, author_id),
    FOREIGN KEY (book_id)   REFERENCES books(book_id),
    FOREIGN KEY (author_id) REFERENCES authors(author_id)
);

CREATE TABLE book_copies (
    copy_id       INT PRIMARY KEY,
    book_id       INT NOT NULL,
    acquired_date DATE,
    status        ENUM('available','issued','lost') NOT NULL DEFAULT 'available',
    FOREIGN KEY (book_id) REFERENCES books(book_id)
);

CREATE TABLE loans (
    loan_id     INT PRIMARY KEY,
    copy_id     INT NOT NULL,
    member_id   INT NOT NULL,
    staff_id    INT,
    issue_date  DATE NOT NULL,
    due_date    DATE NOT NULL,
    return_date DATE,
    FOREIGN KEY (copy_id)   REFERENCES book_copies(copy_id),
    FOREIGN KEY (member_id) REFERENCES members(member_id),
    FOREIGN KEY (staff_id)  REFERENCES staff(staff_id),
    CHECK (due_date >= issue_date)
);

CREATE TABLE fines (
    fine_id   INT PRIMARY KEY,
    loan_id   INT NOT NULL UNIQUE,
    amount    DECIMAL(7,2) NOT NULL CHECK (amount >= 0),
    paid      ENUM('Y','N') NOT NULL DEFAULT 'N',
    paid_date DATE,
    FOREIGN KEY (loan_id) REFERENCES loans(loan_id)
);
