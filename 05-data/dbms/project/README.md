# Library Management System

DBMS course project, 5th sem. A database for a college library that keeps track of books,
their physical copies, members, who has borrowed what, and the fines that pile up on late
returns. Written in MySQL and tested on MariaDB (the college lab runs MySQL 5.7).

## Problem statement

A library holds many titles, and each title has one or more physical copies on the shelf.
Members borrow a copy for 14 days; if they bring it back late they are fined Rs 2 per day.
The manual register the library keeps cannot answer simple questions quickly - which books
are out right now, who is overdue, which titles are most popular, how much fine money was
collected last month. This project builds the schema, loads a session's worth of data, and
writes the queries, views, procedures and triggers that answer those questions and enforce
the borrowing rules.

## ER design

Entities:

- **member** - a person who can borrow (student / faculty / public)
- **staff** - library staff who issue and receive books
- **book** - a title (identified by its ISBN)
- **author**, **publisher**, **category** - descriptive entities a book relates to
- **book_copy** - one physical copy of a book on the shelf; this is what actually gets issued
- **loan** - one borrowing event: a copy issued to a member on a date, due back later
- **fine** - a charge raised on a loan that was returned late

Relationships:

- a **publisher** *publishes* many books; a book has one publisher
- a **category** *classifies* many books; a book belongs to one category
- a **book** *is written by* many authors and an author writes many books (M:N -> `book_authors`)
- a **book** *has* many copies; a copy belongs to one book
- a **member** *borrows* a copy through a **loan**; **staff** *records* the loan
- a **loan** *incurs* at most one **fine**

```
   publishers        categories        authors
       |                  |               |
      1|                 1|              M|
       | publishes        | classifies    | writes (M:N)
      M|                 M|              M|
       +--------> books <-+---------------+
                    |1
                    | has
                    |M
                book_copies ----------------------------+
                    |1                                   |
                    | issued as                          |
                    |M                                   |
   members --1---< loans >--M-- staff                    |
      |               |1                                 |
      | borrows       | incurs                           |
      |               |1 (0..1)                          |
      |             fines                                |
      +--------------------------------------------------+
```

## Relational schema

Primary keys underlined in the mind, written here in ( ). FK = foreign key.

| table | columns | keys |
|-------|---------|------|
| publishers  | (publisher_id), pname, city, phone | PK publisher_id |
| authors     | (author_id), aname, country | PK author_id |
| categories  | (category_id), cname | PK category_id, UNIQUE cname |
| members     | (member_id), mname, email, phone, city, join_date, membership_type | PK member_id, UNIQUE email |
| staff       | (staff_id), sname, role, email, hire_date | PK staff_id |
| books       | (book_id), title, isbn, category_id, publisher_id, pub_year, price | PK book_id, UNIQUE isbn, FK category_id, FK publisher_id, CHECK price>0 |
| book_authors| (book_id, author_id) | PK(book_id,author_id), FK book_id, FK author_id |
| book_copies | (copy_id), book_id, acquired_date, status | PK copy_id, FK book_id, status ENUM(available/issued/lost) |
| loans       | (loan_id), copy_id, member_id, staff_id, issue_date, due_date, return_date | PK loan_id, FK copy_id, FK member_id, FK staff_id, CHECK due>=issue |
| fines       | (fine_id), loan_id, amount, paid, paid_date | PK fine_id, UNIQUE loan_id, FK loan_id, CHECK amount>=0 |

## Normalization

The schema is in **3NF**. In every table each non-key column depends on the whole primary
key and nothing else:

- All primary keys except `book_authors` are single columns, so there are no partial
  dependencies to worry about. `book_authors` is an all-key table (no non-key columns), so
  it is trivially in 3NF - it exists only to resolve the M:N between books and authors.
- No transitive dependencies. A book stores `publisher_id`, not the publisher's city or
  phone - those live in `publishers`. If they were kept in `books` we would have
  `book_id -> publisher_id -> city`, a transitive dependency, and updating a publisher's
  phone would mean touching every one of its books. Splitting authors, publishers and
  categories out avoids exactly that. Same reasoning keeps a copy's status in `book_copies`
  and the fine amount in `fines`.

## Features

**Reports** (`queries.sql`): currently-issued books, overdue loans with days and computed
fine, most-borrowed titles (top 5), members with unpaid fines, available copies per title,
books by a given author, and fine collected per month.

**Views** (`views.sql`):
- `available_books` - per title, total copies and how many are on the shelf
- `member_summary` - per member, current loans and outstanding fine
- `overdue_report` - loans still out and past due (as of the 31-Jan-2020 reporting date)

**Procedures** (`procedures.sql`):
- `issue_book(member, copy, staff)` - checks the copy is free, then inserts a loan inside a
  transaction (due date = today + 14). The triggers do the rest.
- `return_book(loan)` - stamps the return date, and if the book is late inserts a fine of
  Rs 2 per day overdue.
- `member_report(member)` - the member's details, full loan history and current dues.

**Triggers** (`triggers.sql`):
- `trg_loan_before_insert` - validation. Blocks the loan (via `SIGNAL`) if the copy is not
  available, or if the member owes more than Rs 50 in unpaid fines.
- `trg_loan_after_insert` - marks the copy `issued` when a loan is created.
- `trg_loan_after_update` - marks the copy `available` again when the loan is returned.

So the availability of a copy is never set by hand - the triggers keep it correct on every
issue and return.

## Sample output

Overdue report (as of 2020-01-31), `queries.sql`:

```
+---------+---------------+-------------------------+------------+--------------+------+
| loan_id | mname         | title                   | due_date   | days_overdue | fine |
+---------+---------------+-------------------------+------------+--------------+------+
|       9 | Lakshmi Reddy | The God of Small Things | 2020-01-03 |           28 |   56 |
|      10 | Anita Sharma  | Programming in ANSI C   | 2020-01-11 |           20 |   40 |
|      11 | Suresh Babu   | Ignited Minds           | 2020-01-19 |           12 |   24 |
+---------+---------------+-------------------------+------------+--------------+------+
```

Most borrowed titles:

```
+----------------------------------+----------------+
| title                            | times_borrowed |
+----------------------------------+----------------+
| Five Point Someone               |              2 |
| Let Us C                         |              2 |
| Programming in ANSI C            |              2 |
| Database System Concepts         |              1 |
| Fundamentals of Database Systems |              1 |
+----------------------------------+----------------+
```

Issuing to a member who owes 60 in fines is refused by the validation trigger:

```
CALL issue_book(8,110,2);
ERROR 1644 (45000): member has unpaid fines over the limit
```

## How to run

The files must be loaded in dependency order: schema first, then data, then the objects that
build on them.

```
mysql -u root library < schema.sql
mysql -u root library < sample_data.sql
mysql -u root library < views.sql
mysql -u root library < procedures.sql
mysql -u root library < triggers.sql
```

Then run the reports, or try the procedures:

```
mysql -u root library < queries.sql

mysql -u root library
> CALL issue_book(1, 103, 1);      -- Ravi borrows a copy of 'Five Point Someone'
> CALL return_book(9);             -- return an outstanding loan; if past its due date a fine is raised
> CALL member_report(8);           -- Lakshmi's history and dues
> SELECT * FROM overdue_report;
```

`schema.sql` starts with `DROP TABLE IF EXISTS` in reverse order, so the whole thing can be
re-loaded from scratch any time.
