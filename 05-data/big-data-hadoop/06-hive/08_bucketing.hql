-- bucketing on eid into 4 buckets

USE companydb;

-- older hive needs this on; hive 2.x sets it automatically
SET hive.enforce.bucketing = true;

CREATE TABLE IF NOT EXISTS employee_buck (
  eid INT,
  name STRING,
  deptid INT,
  salary INT,
  city STRING
)
CLUSTERED BY (eid) INTO 4 BUCKETS
ROW FORMAT DELIMITED
FIELDS TERMINATED BY ','
STORED AS TEXTFILE;

-- bucketed tables are loaded with insert, not LOAD DATA
INSERT OVERWRITE TABLE employee_buck
SELECT eid, name, deptid, salary, city
FROM employee;

-- sample one bucket out of four
SELECT * FROM employee_buck TABLESAMPLE (BUCKET 1 OUT OF 4 ON eid);
