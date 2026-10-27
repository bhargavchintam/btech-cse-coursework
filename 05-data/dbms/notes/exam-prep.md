# Exam prep — questions that keep coming

Grouped by unit, marks in brackets. The theory questions carry the paper; the SQL and
numerical ones are where marks are actually won or lost, so practise those on the emp/dept data.

## Unit 1 — Introduction

- Compare the file-processing approach with the DBMS approach; list the drawbacks of files and how a DBMS fixes each. (10 marks)
- Explain the ANSI-SPARC three-schema architecture with a neat diagram. (10 marks)
- Distinguish logical and physical data independence with one example each. (6 marks) — asked in IA1
- List and explain the responsibilities of a DBA. (5 marks)
- Differentiate a schema and an instance. (4 marks)
- List any five advantages of a DBMS over a file system. (5 marks)

## Unit 2 — ER model

- Define an entity. Explain the types of attributes (simple, composite, multivalued, derived, key) with ER notation. (8 marks)
- Explain the mapping cardinalities 1:1, 1:N and M:N with an example each. (6 marks)
- What is a weak entity set? How is it represented, and what is its key? (6 marks) — 2018 paper
- Distinguish total and partial participation. (4 marks)
- Draw an ER diagram for a bank (branches, accounts, customers). (10 marks)
- Explain generalization, specialization and aggregation in the EER model. (8 marks)
- Explain the algorithm to map an ER diagram to relational tables. (10 marks)

## Unit 3 — Relational model

- Define superkey, candidate key, primary key, alternate key and foreign key with examples. (8 marks)
- Explain the three integrity constraints (entity, referential, domain). (6 marks)
- Write relational-algebra expressions for the given queries on emp/dept. (10 marks)
- Explain theta, equi, natural and outer joins in relational algebra. (8 marks)
- What is the division operation? Give an example and its SQL equivalent. (5 marks)
- Distinguish relational algebra and relational calculus (tuple vs domain). (6 marks)

## Unit 4 — SQL basics

- Explain the SQL sublanguages (DDL, DML, DQL, DCL, TCL) with example statements. (8 marks)
- Differentiate DELETE, DROP and TRUNCATE. (6 marks)
- Write a CREATE TABLE using all six constraints (PK, FK, NOT NULL, UNIQUE, CHECK, DEFAULT). (6 marks)
- Explain the LIKE operator with the `%` and `_` wildcards and examples. (4 marks)
- Explain the forms of the INSERT statement. (5 marks)
- Write the DDL for a given schema with primary and foreign keys. (8 marks)

## Unit 5 — SQL queries

- Explain the aggregate functions and the NULL rule with examples. (6 marks)
- Differentiate WHERE and HAVING; why can't an aggregate go in WHERE? (5 marks)
- Explain the types of joins in SQL (inner, left/right/full outer, self, cross) with examples. (10 marks)
- What is a correlated subquery? Give an example. (6 marks)
- What is a view? Distinguish updatable and read-only views. (6 marks)
- Write SQL for: the second-highest salary, the top earner in each department, and dept-wise headcount including empty departments. (10 marks)

## Unit 6 — Normalization

- Define functional dependency; distinguish trivial, non-trivial and completely non-trivial. (5 marks)
- State Armstrong's axioms and the three derived rules. (6 marks)
- Compute the attribute closure X+ for the given FDs and find all candidate keys. (10 marks)
- Explain 1NF, 2NF and 3NF with a worked decomposition for each. (10 marks)
- Distinguish 3NF and BCNF; give a relation that is in 3NF but not BCNF and normalize it. (8 marks) — asked in IA1
- State the lossless-join test and the dependency-preservation test. (6 marks)
- Why can a BCNF decomposition lose a dependency while 3NF never does? (6 marks)
- Explain insertion, deletion and update anomalies with an example. (5 marks)

## Unit 7 — Transactions

- Explain the ACID properties of a transaction; state what breaks if each is missing. (8 marks)
- Draw and explain the transaction state diagram. (6 marks)
- Explain the concurrency anomalies: lost update, dirty read, unrepeatable read and phantom, with schedules. (8 marks)
- Test whether the given schedule is conflict-serializable using the precedence graph, and give an equivalent serial order. (10 marks)
- Distinguish conflict serializability and view serializability. (6 marks)
- Explain recoverable, cascadeless and strict schedules. (6 marks)
- Explain COMMIT, ROLLBACK and SAVEPOINT with an example sequence. (5 marks)

## Unit 8 — Concurrency control

- Explain the two-phase locking protocol; state what it guarantees and what it does not. (8 marks)
- Distinguish strict 2PL and rigorous 2PL; what does each prevent? (6 marks)
- Explain the timestamp-ordering protocol with the read and write rules, with an example. (8 marks)
- Explain deadlock and its detection using a wait-for graph. (6 marks)
- Distinguish the wait-die and wound-wait deadlock-prevention schemes. (6 marks) — 2018 paper
- Explain the four SQL isolation levels and the anomaly each permits. (8 marks)

## Unit 9 — Procedural SQL (PL/SQL)

- Distinguish a stored procedure and a function. (5 marks)
- Explain IN, OUT and INOUT parameters with an example procedure. (6 marks)
- What is a cursor? Explain the steps (DECLARE, OPEN, FETCH, CLOSE) to use an explicit cursor. (8 marks)
- Write a procedure using a cursor to compute and store a bonus per employee from the job. (10 marks)
- What is a trigger? Explain the six kinds and the use of NEW and OLD. (8 marks)
- Write a BEFORE INSERT trigger that rejects an invalid value using SIGNAL. (10 marks)
- Explain exception handling: CONTINUE vs EXIT handlers and SIGNAL SQLSTATE. (6 marks)

## Unit 10 — Indexing and storage

- What is an index? Explain how it speeds up query processing. (6 marks)
- Distinguish primary, secondary and clustering indexes. (8 marks)
- Explain the structure of a B+ tree and why it is preferred for database indexing. (10 marks)
- Distinguish a B-tree and a B+ tree. (5 marks)
- Distinguish dense and sparse indexes. (4 marks)
- Explain static hashing and dynamic hashing as file organizations. (8 marks)

## Practical / viva

- Can a foreign key be NULL? Can a primary key be NULL? Justify.
- Difference between DELETE and TRUNCATE.
- Difference between WHERE and HAVING.
- Difference between a primary key and a unique key.
- What does NULL mean, and how do aggregate functions treat it?
- Difference between CHAR and VARCHAR.
- Why can't you put an aggregate function in a WHERE clause?
- Difference between UNION and UNION ALL.
- Can a table have more than one candidate key? More than one primary key?
- Difference between a stored procedure and a function.
- Does 2PL guarantee freedom from deadlock?
- Does BCNF always preserve functional dependencies?
- What is the default transaction isolation level in MySQL/InnoDB?
- Difference between DROP, DELETE and TRUNCATE, and which of them can be rolled back.
- What is a self join, and when do you need one?
- What is the difference between an updatable and a read-only view?
