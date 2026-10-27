-- join examples on emp/dept: inner, natural, left/right/full outer, self, cross

-- inner join: employees with their department name and location
SELECT e.ename, e.job, d.dname, d.loc
FROM emp e JOIN dept d ON e.deptno = d.deptno
ORDER BY e.ename;

-- natural join: same result, deptno matched implicitly (only common column)
SELECT ename, job, dname, loc
FROM emp NATURAL JOIN dept
ORDER BY ename;

-- left outer join: every dept, even OPERATIONS which has no employees
SELECT d.dname, e.ename
FROM dept d LEFT JOIN emp e ON d.deptno = e.deptno
ORDER BY d.dname, e.ename;

-- right outer join: same idea written the other way round
SELECT d.dname, e.ename
FROM emp e RIGHT JOIN dept d ON e.deptno = d.deptno
ORDER BY d.dname, e.ename;

-- full outer join: MySQL has no FULL JOIN, emulate with LEFT UNION RIGHT
SELECT d.dname, e.ename
FROM dept d LEFT JOIN emp e ON d.deptno = e.deptno
UNION
SELECT d.dname, e.ename
FROM dept d RIGHT JOIN emp e ON d.deptno = e.deptno
ORDER BY dname, ename;

-- self join: each employee alongside their manager's name
SELECT e.ename AS employee, m.ename AS manager
FROM emp e JOIN emp m ON e.mgr = m.empno
ORDER BY e.ename;

-- KING has no manager, so a LEFT self join keeps him with a NULL manager
SELECT e.ename AS employee, m.ename AS manager
FROM emp e LEFT JOIN emp m ON e.mgr = m.empno
ORDER BY e.ename;

-- cross join: every emp paired with every dept, 14 x 4 = 56 rows
SELECT COUNT(*) AS cross_rows
FROM emp CROSS JOIN dept;
