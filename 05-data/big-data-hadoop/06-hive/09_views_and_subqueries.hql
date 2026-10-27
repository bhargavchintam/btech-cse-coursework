-- views and subqueries

USE companydb;

-- view over the high paid employees
CREATE VIEW IF NOT EXISTS high_paid AS
SELECT eid, name, salary
FROM employee
WHERE salary > 50000;

SELECT * FROM high_paid ORDER BY salary DESC;

-- subquery in FROM (derived table): departments above avg 40000
SELECT deptid, avg_sal
FROM (
  SELECT deptid, AVG(salary) AS avg_sal
  FROM employee
  GROUP BY deptid
) t
WHERE avg_sal > 40000;

-- subquery in WHERE with IN: employees of Bangalore-located depts
SELECT name, salary
FROM employee
WHERE deptid IN (
  SELECT deptid FROM department WHERE location = 'Bangalore'
);

DROP VIEW IF EXISTS high_paid;
