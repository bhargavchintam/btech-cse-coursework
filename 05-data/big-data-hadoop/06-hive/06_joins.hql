-- joins between employee and department

USE companydb;

-- inner join: employees that have a matching department
SELECT e.name, e.salary, d.dname, d.location
FROM employee e
JOIN department d ON e.deptid = d.deptid;

-- left outer join: all employees, dept null if no match
SELECT e.name, d.dname
FROM employee e
LEFT OUTER JOIN department d ON e.deptid = d.deptid;

-- right outer join: all departments, employee null if none
SELECT e.name, d.dname
FROM employee e
RIGHT OUTER JOIN department d ON e.deptid = d.deptid;

-- full outer join: all rows from both sides
SELECT e.name, d.dname
FROM employee e
FULL OUTER JOIN department d ON e.deptid = d.deptid;

-- join with group by: avg salary per department name
SELECT d.dname, AVG(e.salary) AS avg_sal
FROM employee e
JOIN department d ON e.deptid = d.deptid
GROUP BY d.dname;
