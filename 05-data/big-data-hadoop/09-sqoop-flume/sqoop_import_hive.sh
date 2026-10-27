#!/bin/bash
# sqoop import straight into a hive table

sqoop import \
  --connect jdbc:mysql://localhost/testdb \
  --username root \
  --password root \
  --table emp \
  --hive-import \
  --hive-database default \
  --hive-table emp_hive \
  --create-hive-table \
  --fields-terminated-by ',' \
  -m 1

# then in hive:  SELECT * FROM emp_hive;
