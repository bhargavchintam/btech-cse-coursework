#!/bin/bash
# sqoop import - mysql table emp -> HDFS

sqoop import \
  --connect jdbc:mysql://localhost/testdb \
  --username root \
  --password root \
  --table emp \
  --target-dir /user/hadoop/emp \
  --fields-terminated-by ',' \
  -m 1

# check output in HDFS
hdfs dfs -ls /user/hadoop/emp
hdfs dfs -cat /user/hadoop/emp/part-m-00000
