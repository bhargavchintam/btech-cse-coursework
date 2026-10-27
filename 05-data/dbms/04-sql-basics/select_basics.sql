-- select_basics.sql - WHERE / BETWEEN / IN / LIKE / IS NULL on emp/dept
-- load emp_dept.sql first, then run this file.

SELECT empno, ename, sal FROM emp WHERE sal > 20000 ORDER BY sal;   -- 6 rows

SELECT ename, job FROM emp WHERE deptno = 20 AND job = 'CLERK';     -- SMITH, ADAMS

SELECT ename, sal FROM emp WHERE sal BETWEEN 12000 AND 16000 ORDER BY sal, ename;   -- 5 rows

SELECT ename, hiredate FROM emp
WHERE hiredate BETWEEN '2019-01-01' AND '2019-06-30' ORDER BY hiredate;   -- 5 rows

SELECT ename, job FROM emp WHERE job IN ('MANAGER','ANALYST') ORDER BY job, ename;   -- 5 rows

SELECT ename, deptno FROM emp WHERE deptno IN (10,20) ORDER BY deptno, ename;   -- 8 rows

SELECT ename FROM emp WHERE ename LIKE 'S%';                 -- SMITH, SCOTT

SELECT ename FROM emp WHERE ename LIKE '_A%' ORDER BY ename; -- WARD, MARTIN, JAMES

SELECT ename FROM emp WHERE ename LIKE '%LL%';               -- ALLEN, MILLER

SELECT ename, comm FROM emp WHERE comm IS NULL ORDER BY ename;   -- 10 rows

-- 0 is a real value, not null, so TURNER is excluded here
SELECT ename, comm FROM emp WHERE comm IS NOT NULL AND comm > 0 ORDER BY comm;   -- 3 rows

SELECT ename, deptno, sal, job FROM emp
WHERE (deptno = 30 AND sal > 12500) OR job = 'PRESIDENT' ORDER BY ename;   -- 4 rows

SELECT ename, job FROM emp WHERE NOT job = 'SALESMAN' ORDER BY ename;   -- 10 rows
