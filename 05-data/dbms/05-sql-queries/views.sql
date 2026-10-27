-- views: an updatable single-table view and two read-only reporting views

DROP VIEW IF EXISTS emp30;
DROP VIEW IF EXISTS dept_summary;
DROP VIEW IF EXISTS emp_dept_v;

-- updatable: single table, no aggregate, so INSERT/UPDATE flow through to emp
CREATE VIEW emp30 AS
SELECT empno, ename, job, sal, deptno
FROM emp
WHERE deptno = 30;

SELECT * FROM emp30 ORDER BY sal DESC;

-- read-only: has a GROUP BY, so it cannot be updated through
CREATE VIEW dept_summary AS
SELECT d.deptno, d.dname, COUNT(e.empno) AS headcount, AVG(e.sal) AS avg_sal
FROM dept d LEFT JOIN emp e ON d.deptno = e.deptno
GROUP BY d.deptno, d.dname;

SELECT * FROM dept_summary ORDER BY deptno;

-- read-only: a join view joining emp and dept names for reporting
CREATE VIEW emp_dept_v AS
SELECT e.empno, e.ename, e.job, e.sal, d.dname, d.loc
FROM emp e JOIN dept d ON e.deptno = d.deptno;

SELECT ename, job, dname, loc FROM emp_dept_v WHERE loc = 'HYDERABAD' ORDER BY ename;
