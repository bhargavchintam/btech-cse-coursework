-- experiment 6: subqueries and set-operation-style queries on emp/dept.
-- run emp_dept.sql first, then this file.

-- single-row subquery: employees earning more than JONES
SELECT ename, sal
FROM emp
WHERE sal > (SELECT sal FROM emp WHERE ename = 'JONES')
ORDER BY sal;

-- multi-row IN: employees in departments located at BANGALORE or HYDERABAD
SELECT ename, deptno
FROM emp
WHERE deptno IN (SELECT deptno FROM dept WHERE loc IN ('BANGALORE','HYDERABAD'))
ORDER BY deptno, ename;

-- multi-row ANY: non-clerks paid more than at least one clerk
SELECT ename, job, sal
FROM emp
WHERE sal > ANY (SELECT sal FROM emp WHERE job = 'CLERK')
  AND job <> 'CLERK'
ORDER BY sal;

-- multi-row ALL: employees paid more than every salesman
SELECT ename, sal
FROM emp
WHERE sal > ALL (SELECT sal FROM emp WHERE job = 'SALESMAN')
ORDER BY sal;

-- correlated: employees earning above their own department's average
SELECT e.ename, e.deptno, e.sal
FROM emp e
WHERE e.sal > (SELECT AVG(x.sal) FROM emp x WHERE x.deptno = e.deptno)
ORDER BY e.deptno, e.sal;

-- EXISTS: departments that have at least one employee
SELECT d.deptno, d.dname
FROM dept d
WHERE EXISTS (SELECT 1 FROM emp e WHERE e.deptno = d.deptno)
ORDER BY d.deptno;

-- UNION: distinct departments that employ a clerk or an analyst
SELECT deptno FROM emp WHERE job = 'CLERK'
UNION
SELECT deptno FROM emp WHERE job = 'ANALYST'
ORDER BY deptno;

-- MySQL 5.7 has no INTERSECT; emulate it with IN.
-- departments having both a clerk and a manager
SELECT DISTINCT deptno FROM emp WHERE job = 'CLERK'
  AND deptno IN (SELECT deptno FROM emp WHERE job = 'MANAGER')
ORDER BY deptno;

-- no EXCEPT either; NOT IN gives the difference.
-- departments with a clerk but no analyst
SELECT DISTINCT deptno FROM emp WHERE job = 'CLERK'
  AND deptno NOT IN (SELECT deptno FROM emp WHERE job = 'ANALYST')
ORDER BY deptno;
