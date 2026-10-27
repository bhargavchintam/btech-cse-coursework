-- group by with count / sum / avg aggregates

USE companydb;

-- employees per department
SELECT deptid, COUNT(*) AS emp_count
FROM employee
GROUP BY deptid;

-- total and average salary per department
SELECT deptid,
       COUNT(*)    AS emp_count,
       SUM(salary) AS total_sal,
       AVG(salary) AS avg_sal,
       MAX(salary) AS max_sal,
       MIN(salary) AS min_sal
FROM employee
GROUP BY deptid;

-- departments whose average salary is above 40000
SELECT deptid, AVG(salary) AS avg_sal
FROM employee
GROUP BY deptid
HAVING AVG(salary) > 40000;

-- count by city, only cities with more than 2 employees
SELECT city, COUNT(*) AS cnt
FROM employee
GROUP BY city
HAVING COUNT(*) > 2
ORDER BY cnt DESC;
