-- create, load and query an employee table

CREATE DATABASE IF NOT EXISTS company;
USE company;

CREATE TABLE IF NOT EXISTS emp (
  id   INT,
  name STRING,
  dept STRING,
  sal  INT
)
ROW FORMAT DELIMITED
FIELDS TERMINATED BY ','
STORED AS TEXTFILE;

LOAD DATA LOCAL INPATH '/home/hadoop/emp.csv' INTO TABLE emp;

SELECT * FROM emp;

SELECT dept, COUNT(*) AS cnt FROM emp GROUP BY dept;

SELECT dept, AVG(sal) AS avg_sal FROM emp GROUP BY dept;

SELECT * FROM emp WHERE sal > 7000 ORDER BY sal DESC;

SELECT MAX(sal) AS max_sal, MIN(sal) AS min_sal FROM emp;
