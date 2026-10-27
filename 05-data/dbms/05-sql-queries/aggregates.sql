-- aggregate, GROUP BY and HAVING examples on emp/dept

-- plain aggregates over the whole table
SELECT COUNT(*)     AS n_emp,
       SUM(sal)     AS total_sal,
       AVG(sal)     AS avg_sal,
       MIN(sal)     AS min_sal,
       MAX(sal)     AS max_sal
FROM emp;

-- COUNT(comm) counts only non-null commissions; COUNT(*) counts all rows
SELECT COUNT(*) AS all_rows, COUNT(comm) AS with_comm
FROM emp;

-- headcount and average pay per department
SELECT deptno, COUNT(*) AS headcount, AVG(sal) AS avg_sal
FROM emp
GROUP BY deptno
ORDER BY deptno;

-- HAVING filters groups: departments whose average salary tops 20000
SELECT deptno, AVG(sal) AS avg_sal
FROM emp
GROUP BY deptno
HAVING AVG(sal) > 20000
ORDER BY avg_sal;

-- WHERE filters rows before grouping, HAVING filters after: avg clerk pay per
-- dept, only for depts with more than one clerk
SELECT deptno, COUNT(*) AS clerks, AVG(sal) AS avg_clerk_sal
FROM emp
WHERE job = 'CLERK'
GROUP BY deptno
HAVING COUNT(*) > 1
ORDER BY deptno;

-- count of employees per job
SELECT job, COUNT(*) AS n
FROM emp
GROUP BY job
ORDER BY n DESC, job;
