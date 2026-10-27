-- indexing on the emp table: EXPLAIN a query before and after building an index to
-- watch the optimiser switch from a full table scan to an index lookup, inspect the
-- indexes with SHOW INDEX, then drop them. load emp_dept.sql first (schema + rows).

-- emp already carries two indexes for free: the PRIMARY KEY on empno, and one InnoDB
-- auto-creates on deptno to support the FK to dept. so a search by deptno is already
-- indexed without us doing anything.
SHOW INDEX FROM emp;

-- before any index on sal, filtering by salary is a full table scan
-- (type=ALL, key=NULL, rows ~ the whole table).
EXPLAIN SELECT ename, sal FROM emp WHERE sal = 30000;

CREATE INDEX idx_emp_sal ON emp (sal);

-- after: the optimiser can now reach those rows through idx_emp_sal (type=ref, key set).
EXPLAIN SELECT ename, sal FROM emp WHERE sal = 30000;

-- composite index for "by job, then salary" filters; leftmost column is job so the FK
-- on deptno is untouched. covers queries that read only job+sal (a covering index).
CREATE INDEX idx_emp_job_sal ON emp (job, sal);

-- ename happens to be unique in our data, so enforce it with a unique index
CREATE UNIQUE INDEX idx_emp_ename ON emp (ename);

-- a unique-index equality lookup is where an index really pays: one row, type=const,
-- instead of scanning all 14.
EXPLAIN SELECT empno, sal FROM emp WHERE ename = 'BLAKE';

-- covering index: idx_emp_job_sal holds both columns the query needs, so the read is
-- answered from the index alone (EXPLAIN Extra shows "Using index").
EXPLAIN SELECT job, sal FROM emp WHERE job = 'SALESMAN';

SHOW INDEX FROM emp;

DROP INDEX idx_emp_sal ON emp;
DROP INDEX idx_emp_job_sal ON emp;
DROP INDEX idx_emp_ename ON emp;

-- back to the starting point: PRIMARY plus the FK's deptno index
SHOW INDEX FROM emp;
