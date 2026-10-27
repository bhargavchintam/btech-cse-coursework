#!/bin/bash
# lab11 - sqoop import and export between mysql and hdfs

# import a full table into hdfs
sqoop import \
  --connect jdbc:mysql://localhost/company \
  --username root --password root \
  --table employees \
  --target-dir /user/hadoop/employees \
  -m 1

# import straight into a hive table
sqoop import \
  --connect jdbc:mysql://localhost/company \
  --username root --password root \
  --table employees \
  --hive-import --hive-table employees \
  -m 1

# import only selected columns matching a condition
sqoop import \
  --connect jdbc:mysql://localhost/company \
  --username root --password root \
  --table employees \
  --columns "id,name,sal" \
  --where "sal > 5000" \
  --target-dir /user/hadoop/emp_highpaid \
  -m 1

# export processed data from hdfs back to mysql
sqoop export \
  --connect jdbc:mysql://localhost/company \
  --username root --password root \
  --table employees_out \
  --export-dir /user/hadoop/employees \
  -m 1
