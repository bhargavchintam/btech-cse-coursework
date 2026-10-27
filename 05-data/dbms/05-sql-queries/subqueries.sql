-- subquery examples: single-row, multi-row (IN/ANY/ALL), correlated, EXISTS

-- single-row: employees earning more than SMITH
SELECT ename, sal
FROM emp
WHERE sal > (SELECT sal FROM emp WHERE ename = 'SMITH')
ORDER BY sal;

-- single-row with aggregate: who earns the maximum salary
-- SELECT ename FROM emp WHERE sal = MAX(sal);  -- doesnt work, cant use agg in where
SELECT ename, sal
FROM emp
WHERE sal = (SELECT MAX(sal) FROM emp);

-- multi-row IN: everyone working in a department located in BANGALORE or MYSORE
SELECT ename, deptno
FROM emp
WHERE deptno IN (SELECT deptno FROM dept WHERE loc IN ('BANGALORE','MYSORE'))
ORDER BY deptno, ename;

-- multi-row ANY: paid more than at least one CLERK
SELECT ename, sal
FROM emp
WHERE sal > ANY (SELECT sal FROM emp WHERE job = 'CLERK')
  AND job <> 'CLERK'
ORDER BY sal;

-- multi-row ALL: paid more than every SALESMAN
SELECT ename, sal
FROM emp
WHERE sal > ALL (SELECT sal FROM emp WHERE job = 'SALESMAN')
ORDER BY sal;

-- correlated: employees earning more than their own department's average
SELECT e.ename, e.deptno, e.sal
FROM emp e
WHERE e.sal > (SELECT AVG(x.sal) FROM emp x WHERE x.deptno = e.deptno)
ORDER BY e.deptno, e.sal;

-- EXISTS: departments that actually have at least one employee
SELECT d.dname
FROM dept d
WHERE EXISTS (SELECT 1 FROM emp e WHERE e.deptno = d.deptno)
ORDER BY d.dname;

-- NOT EXISTS: the department with no employees
SELECT d.dname
FROM dept d
WHERE NOT EXISTS (SELECT 1 FROM emp e WHERE e.deptno = d.deptno);
