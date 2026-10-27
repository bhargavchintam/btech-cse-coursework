-- experiment 7: creating, querying and updating views on emp/dept.
-- run emp_dept.sql first, then this file.

DROP VIEW IF EXISTS dept_summary;
DROP VIEW IF EXISTS high_earners;
DROP VIEW IF EXISTS emp10;

-- summary view: headcount and average pay per department.
-- has a GROUP BY, so it is read-only.
CREATE VIEW dept_summary AS
SELECT d.deptno, d.dname, COUNT(e.empno) AS headcount, AVG(e.sal) AS avg_sal
FROM dept d LEFT JOIN emp e ON d.deptno = e.deptno
GROUP BY d.deptno, d.dname;

SELECT * FROM dept_summary ORDER BY deptno;

-- high earners: everyone paid above the company average, with dept name
CREATE VIEW high_earners AS
SELECT e.empno, e.ename, e.sal, d.dname
FROM emp e JOIN dept d ON e.deptno = d.deptno
WHERE e.sal > (SELECT AVG(sal) FROM emp);

SELECT ename, sal, dname FROM high_earners ORDER BY sal DESC;

-- updatable view: one table, no aggregate, so writes reach the base table
CREATE VIEW emp10 AS
SELECT empno, ename, job, sal, deptno
FROM emp
WHERE deptno = 10;

SELECT * FROM emp10 ORDER BY empno;

-- a raise applied through the view actually changes emp
UPDATE emp10 SET sal = sal * 1.05 WHERE empno = 7934;
SELECT empno, ename, sal FROM emp WHERE empno = 7934;

-- the grouped view cannot be updated through:
-- UPDATE dept_summary SET headcount = 0 WHERE deptno = 10;  -- errors, not updatable
