# Experiment 1 — DDL and the emp/dept Schema

**Date:** 25/09/2019

## Aim
Create the emp/dept schema with primary key, foreign key, NOT NULL, UNIQUE and CHECK constraints, alter it to add a column and a constraint, and describe the tables.

## Tools
MySQL 5.7 (college lab). Also runs on MariaDB.

## Schema
Two tables. `dept` is the parent; `emp.deptno` is a foreign key into it.

- `dept(deptno PK, dname NOT NULL UNIQUE, loc DEFAULT 'BANGALORE')`
- `emp(empno PK, ename NOT NULL, job, mgr, hiredate, sal NOT NULL, comm, deptno FK→dept, CHECK sal>0, CHECK comm>=0)`

All statements are in `schema.sql`.

## Queries

**Create the parent table with a UNIQUE constraint on the department name.**
```sql
CREATE TABLE dept (
    deptno INT PRIMARY KEY,
    dname  VARCHAR(20) NOT NULL,
    loc    VARCHAR(20) DEFAULT 'BANGALORE',
    CONSTRAINT uq_dname UNIQUE (dname)
);
```

**Create the child table with the foreign key and two CHECK constraints.**
```sql
CREATE TABLE emp (
    empno    INT PRIMARY KEY,
    ename    VARCHAR(20) NOT NULL,
    job      VARCHAR(15),
    mgr      INT,
    hiredate DATE,
    sal      DECIMAL(8,2) NOT NULL,
    comm     DECIMAL(8,2),
    deptno   INT,
    CONSTRAINT fk_emp_dept FOREIGN KEY (deptno) REFERENCES dept(deptno),
    CONSTRAINT chk_sal CHECK (sal > 0),
    CONSTRAINT chk_comm CHECK (comm >= 0)
);
```

**Alter emp: add an email column, then add a UNIQUE constraint on it.**
```sql
ALTER TABLE emp ADD email VARCHAR(40);
ALTER TABLE emp ADD CONSTRAINT uq_email UNIQUE (email);
```

**Describe both tables.**
```sql
DESCRIBE dept;
```
| Field  | Type        | Null | Key | Default   | Extra |
|--------|-------------|------|-----|-----------|-------|
| deptno | int(11)     | NO   | PRI | NULL      |       |
| dname  | varchar(20) | NO   | UNI | NULL      |       |
| loc    | varchar(20) | YES  |     | BANGALORE |       |

```sql
DESCRIBE emp;
```
| Field    | Type         | Null | Key | Default | Extra |
|----------|--------------|------|-----|---------|-------|
| empno    | int(11)      | NO   | PRI | NULL    |       |
| ename    | varchar(20)  | NO   |     | NULL    |       |
| job      | varchar(15)  | YES  |     | NULL    |       |
| mgr      | int(11)      | YES  |     | NULL    |       |
| hiredate | date         | YES  |     | NULL    |       |
| sal      | decimal(8,2) | NO   |     | NULL    |       |
| comm     | decimal(8,2) | YES  |     | NULL    |       |
| deptno   | int(11)      | YES  | MUL | NULL    |       |
| email    | varchar(40)  | YES  | UNI | NULL    |       |

## Result
Both tables were created with all constraints in place. In `DESCRIBE`, the PK columns show `Key = PRI`, the unique columns `UNI`, and the foreign-key column `deptno` shows `MUL` (a non-unique index is kept for the FK). The `loc` column carries its default `BANGALORE`.
