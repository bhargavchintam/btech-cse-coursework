-- load data from local files into the tables
-- employee.csv rows: 101,ravi,1,55000,Bangalore  (eid,name,deptid,salary,city)
-- department.csv rows: 1,HR,Bangalore  (deptid,dname,location)

USE companydb;

LOAD DATA LOCAL INPATH '/home/hadoop/data/employee.csv'
INTO TABLE employee;

LOAD DATA LOCAL INPATH '/home/hadoop/data/department.csv'
INTO TABLE department;

-- OVERWRITE clears old rows first, use when re-loading
-- LOAD DATA LOCAL INPATH '/home/hadoop/data/employee.csv'
-- OVERWRITE INTO TABLE employee;

SELECT * FROM employee LIMIT 10;
SELECT * FROM department;
