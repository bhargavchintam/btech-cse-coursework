-- relational algebra examples on the emp/dept schema (load emp_dept.sql first)

-- σ(deptno=20)(emp)
SELECT * FROM emp WHERE deptno = 20 ORDER BY empno;

-- π(ename, job)(emp)
SELECT DISTINCT ename, job FROM emp ORDER BY ename;

-- π(ename, sal)(σ(sal>20000)(emp))
SELECT ename, sal FROM emp WHERE sal > 20000 ORDER BY sal DESC;

-- π(ename)(σ(job='CLERK')(emp)) ∪ π(ename)(σ(job='ANALYST')(emp))
(SELECT ename FROM emp WHERE job = 'CLERK')
UNION
(SELECT ename FROM emp WHERE job = 'ANALYST')
ORDER BY ename;

-- π(deptno)(σ(sal>25000)(emp)) ∩ π(deptno)(σ(sal<12000)(emp))
SELECT deptno FROM emp WHERE sal > 25000
INTERSECT
SELECT deptno FROM emp WHERE sal < 12000
ORDER BY deptno;

-- π(deptno)(dept) − π(deptno)(emp)
SELECT deptno FROM dept
EXCEPT
SELECT deptno FROM emp;

-- π(ename)(σ(job='PRESIDENT')(emp)) × π(dname)(dept)
SELECT k.ename, d.dname
FROM (SELECT ename FROM emp WHERE job = 'PRESIDENT') k
CROSS JOIN dept d
ORDER BY d.dname;

-- π(e.ename, m.ename)(emp e ⋈[e.mgr=m.empno] ρ(m)(emp))   self join for manager name
SELECT e.ename AS employee, m.ename AS manager
FROM emp e JOIN emp m ON e.mgr = m.empno
ORDER BY e.ename;

-- emp ⋈[emp.deptno=dept.deptno ∧ emp.sal>25000] dept   theta join
SELECT e.ename, e.sal, d.dname
FROM emp e JOIN dept d ON e.deptno = d.deptno AND e.sal > 25000
ORDER BY e.sal DESC;

-- emp ⋈ dept   natural join
SELECT ename, dname, loc FROM emp NATURAL JOIN dept ORDER BY ename;

-- dept ⟕ emp   left outer join (OPERATIONS has no rows in emp)
SELECT d.dname, e.ename
FROM dept d LEFT JOIN emp e ON d.deptno = e.deptno
WHERE d.deptno = 40;

-- π(dname, count)(dept ⟕ emp)   outer join keeps the empty department
SELECT d.dname, COUNT(e.empno) AS n_emp
FROM dept d LEFT JOIN emp e ON d.deptno = e.deptno
GROUP BY d.dname ORDER BY d.dname;

-- π(job, deptno)(emp) ÷ π(deptno)(emp)   jobs present in every occupied dept
SELECT DISTINCT e1.job
FROM emp e1
WHERE NOT EXISTS (
    SELECT d.deptno FROM (SELECT DISTINCT deptno FROM emp) d
    WHERE NOT EXISTS (
        SELECT 1 FROM emp e2 WHERE e2.job = e1.job AND e2.deptno = d.deptno
    )
)
ORDER BY e1.job;

-- π(ename)(σ(sal>20000)(emp ⋈ σ(dname='RESEARCH')(dept)))
SELECT e.ename
FROM emp e JOIN dept d ON e.deptno = d.deptno
WHERE d.dname = 'RESEARCH' AND e.sal > 20000
ORDER BY e.ename;

-- π(ename, job)(σ(loc='BANGALORE')(emp ⋈ dept))
SELECT e.ename, e.job
FROM emp e JOIN dept d ON e.deptno = d.deptno
WHERE d.loc = 'BANGALORE'
ORDER BY e.ename;

-- π(dname)(dept) where deptno ∈ (π(deptno)(dept) − π(deptno)(emp))   depts with no employees
SELECT dname FROM dept WHERE deptno NOT IN (SELECT deptno FROM emp);
