-- partitioning by city for faster city-wise queries

USE companydb;

CREATE TABLE IF NOT EXISTS employee_part (
  eid INT,
  name STRING,
  deptid INT,
  salary INT
)
PARTITIONED BY (city STRING)
ROW FORMAT DELIMITED
FIELDS TERMINATED BY ','
STORED AS TEXTFILE;

-- static partition: load one city into its own partition
LOAD DATA LOCAL INPATH '/home/hadoop/data/emp_bangalore.csv'
INTO TABLE employee_part PARTITION (city = 'Bangalore');

-- dynamic partition: let hive create partitions from the data
SET hive.exec.dynamic.partition = true;
SET hive.exec.dynamic.partition.mode = nonstrict;

-- partition column must be the LAST column in the select
INSERT OVERWRITE TABLE employee_part PARTITION (city)
SELECT eid, name, deptid, salary, city
FROM employee;

SHOW PARTITIONS employee_part;

-- query hits only the Bangalore partition (partition pruning)
SELECT name, salary FROM employee_part WHERE city = 'Bangalore';
