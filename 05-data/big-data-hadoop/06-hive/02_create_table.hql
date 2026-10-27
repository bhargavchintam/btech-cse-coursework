-- employee and department tables (managed, comma delimited)

USE companydb;

CREATE TABLE IF NOT EXISTS employee (
  eid INT,
  name STRING,
  deptid INT,
  salary INT,
  city STRING
)
ROW FORMAT DELIMITED
FIELDS TERMINATED BY ','
STORED AS TEXTFILE;

CREATE TABLE IF NOT EXISTS department (
  deptid INT,
  dname STRING,
  location STRING
)
ROW FORMAT DELIMITED
FIELDS TERMINATED BY ','
STORED AS TEXTFILE;

SHOW TABLES;
DESCRIBE employee;
DESCRIBE department;
