-- static + dynamic partitioning and bucketing

USE company;

-- partitioned table
CREATE TABLE emp_part (
  id   INT,
  name STRING,
  sal  INT
)
PARTITIONED BY (dept STRING)
ROW FORMAT DELIMITED FIELDS TERMINATED BY ','
STORED AS TEXTFILE;

-- static partition loads
LOAD DATA LOCAL INPATH '/home/hadoop/cse.csv' INTO TABLE emp_part PARTITION (dept='cse');
LOAD DATA LOCAL INPATH '/home/hadoop/ece.csv' INTO TABLE emp_part PARTITION (dept='ece');

SHOW PARTITIONS emp_part;
SELECT * FROM emp_part WHERE dept='cse';

-- dynamic partitioning (loads from the base emp table of lab5)
SET hive.exec.dynamic.partition=true;
SET hive.exec.dynamic.partition.mode=nonstrict;

CREATE TABLE emp_dyn (
  id   INT,
  name STRING,
  sal  INT
)
PARTITIONED BY (dept STRING)
ROW FORMAT DELIMITED FIELDS TERMINATED BY ',';

INSERT OVERWRITE TABLE emp_dyn PARTITION (dept)
SELECT id, name, sal, dept FROM emp;

SHOW PARTITIONS emp_dyn;

-- bucketing
SET hive.enforce.bucketing=true;

CREATE TABLE emp_bucket (
  id   INT,
  name STRING,
  dept STRING,
  sal  INT
)
CLUSTERED BY (id) INTO 4 BUCKETS
ROW FORMAT DELIMITED FIELDS TERMINATED BY ',';

INSERT OVERWRITE TABLE emp_bucket SELECT id, name, dept, sal FROM emp;
