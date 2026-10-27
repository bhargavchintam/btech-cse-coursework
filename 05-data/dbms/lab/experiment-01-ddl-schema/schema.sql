-- schema.sql - build the emp/dept schema with full constraints, ALTER it, DESCRIBE

DROP TABLE IF EXISTS emp;
DROP TABLE IF EXISTS dept;

CREATE TABLE dept (
    deptno INT PRIMARY KEY,
    dname  VARCHAR(20) NOT NULL,
    loc    VARCHAR(20) DEFAULT 'BANGALORE',
    CONSTRAINT uq_dname UNIQUE (dname)
);

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

ALTER TABLE emp ADD email VARCHAR(40);
ALTER TABLE emp ADD CONSTRAINT uq_email UNIQUE (email);

DESCRIBE dept;
DESCRIBE emp;
