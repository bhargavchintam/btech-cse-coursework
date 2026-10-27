-- hive joins between employee and department

USE company;

CREATE TABLE IF NOT EXISTS employee (
  id      INT,
  name    STRING,
  dept_id INT
)
ROW FORMAT DELIMITED FIELDS TERMINATED BY ',' STORED AS TEXTFILE;

CREATE TABLE IF NOT EXISTS department (
  dept_id   INT,
  dept_name STRING
)
ROW FORMAT DELIMITED FIELDS TERMINATED BY ',' STORED AS TEXTFILE;

LOAD DATA LOCAL INPATH '/home/hadoop/employee.csv' INTO TABLE employee;
LOAD DATA LOCAL INPATH '/home/hadoop/department.csv' INTO TABLE department;

-- inner join
SELECT e.id, e.name, d.dept_name
FROM employee e JOIN department d ON e.dept_id = d.dept_id;

-- left outer join
SELECT e.name, d.dept_name
FROM employee e LEFT OUTER JOIN department d ON e.dept_id = d.dept_id;

-- right outer join
SELECT e.name, d.dept_name
FROM employee e RIGHT OUTER JOIN department d ON e.dept_id = d.dept_id;

-- full outer join
SELECT e.name, d.dept_name
FROM employee e FULL OUTER JOIN department d ON e.dept_id = d.dept_id;
