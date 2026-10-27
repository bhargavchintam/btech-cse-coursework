-- experiment 5: join queries on the emp/dept schema.
-- run emp_dept.sql first to build the tables, then this file.

-- inner join: each employee with department name and location
SELECT e.empno, e.ename, e.job, d.dname, d.loc
FROM emp e JOIN dept d ON e.deptno = d.deptno
ORDER BY e.empno;

-- left outer join: keep every department, even OPERATIONS with no employees
SELECT d.dname, e.ename
FROM dept d LEFT JOIN emp e ON d.deptno = e.deptno
ORDER BY d.dname, e.ename;

-- right outer join: same list written from the emp side
SELECT d.dname, e.ename
FROM emp e RIGHT JOIN dept d ON e.deptno = d.deptno
ORDER BY d.dname, e.ename;

-- self join: each employee beside the name of their manager
SELECT e.ename AS employee, m.ename AS manager
FROM emp e JOIN emp m ON e.mgr = m.empno
ORDER BY e.ename;

-- left self join keeps KING, who has no manager, with a NULL manager
SELECT e.ename AS employee, m.ename AS manager
FROM emp e LEFT JOIN emp m ON e.mgr = m.empno
ORDER BY e.ename;

-- cross join: every employee paired with every dept, 14 x 4 = 56 rows
SELECT COUNT(*) AS cross_rows
FROM emp CROSS JOIN dept;
