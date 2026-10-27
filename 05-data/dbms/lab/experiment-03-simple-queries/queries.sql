-- queries.sql - simple SELECT: WHERE, BETWEEN, IN, LIKE, IS NULL, ORDER BY, DISTINCT
-- load emp_dept.sql first, then run this file.

SELECT ename, job, sal FROM emp WHERE sal > 20000 ORDER BY sal DESC;

SELECT ename, sal FROM emp WHERE sal BETWEEN 12000 AND 16000 ORDER BY sal, ename;

SELECT ename, job FROM emp WHERE job IN ('MANAGER','ANALYST') ORDER BY job, ename;

SELECT ename, deptno FROM emp WHERE deptno NOT IN (10,20) ORDER BY ename;

SELECT ename FROM emp WHERE ename LIKE 'M%' ORDER BY ename;

SELECT ename FROM emp WHERE ename LIKE '%ER%' ORDER BY ename;

SELECT ename, comm FROM emp WHERE comm IS NULL ORDER BY empno;

SELECT ename, comm FROM emp WHERE comm IS NOT NULL ORDER BY comm;

SELECT DISTINCT job FROM emp ORDER BY job;

SELECT ename, hiredate FROM emp
WHERE hiredate BETWEEN '2019-01-01' AND '2019-06-30' ORDER BY hiredate;

SELECT ename, sal, deptno FROM emp WHERE deptno = 30 AND sal >= 15000 ORDER BY sal DESC;
