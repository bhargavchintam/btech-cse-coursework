-- basic select with where, order by, limit

USE companydb;

SELECT * FROM employee;

SELECT eid, name, salary FROM employee WHERE salary > 30000;

SELECT name, city FROM employee
WHERE city = 'Bangalore' AND salary > 40000;

SELECT DISTINCT city FROM employee;

SELECT name, salary FROM employee
WHERE salary BETWEEN 30000 AND 60000
ORDER BY salary DESC;

-- top 5 highest paid
SELECT eid, name, salary FROM employee
ORDER BY salary DESC
LIMIT 5;

-- pattern match
SELECT name FROM employee WHERE name LIKE 'r%';
