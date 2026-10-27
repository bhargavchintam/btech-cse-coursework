-- queries.sql - aggregate functions, GROUP BY, HAVING on emp/dept
-- load emp_dept.sql first, then run this file.

SELECT COUNT(*) AS total_emps FROM emp;

SELECT COUNT(comm) AS paid_comm FROM emp;

SELECT MIN(sal) AS lowest, MAX(sal) AS highest, ROUND(AVG(sal),2) AS average FROM emp;

SELECT SUM(sal) AS total_payroll FROM emp;

SELECT deptno, COUNT(*) AS headcount, SUM(sal) AS wagebill FROM emp GROUP BY deptno ORDER BY deptno;

SELECT deptno, ROUND(AVG(sal),2) AS avg_sal FROM emp GROUP BY deptno ORDER BY avg_sal DESC;

SELECT job, COUNT(*) AS cnt, MAX(sal) AS top_sal FROM emp GROUP BY job ORDER BY cnt DESC, job;

SELECT deptno, COUNT(*) AS cnt FROM emp GROUP BY deptno HAVING COUNT(*) > 3 ORDER BY deptno;

SELECT job, ROUND(AVG(sal),2) AS avg_sal FROM emp GROUP BY job HAVING AVG(sal) > 15000 ORDER BY avg_sal DESC;
