#!/bin/bash
# file operations on hdfs

# copy from local to hdfs
hdfs dfs -copyFromLocal /home/hadoop/emp.csv /user/hadoop/emp.csv

# copy from hdfs to local
hdfs dfs -copyToLocal /user/hadoop/emp.csv /home/hadoop/emp_copy.csv

# move (rename) inside hdfs
hdfs dfs -mv /user/hadoop/emp.csv /user/hadoop/employee.csv

# copy inside hdfs
hdfs dfs -cp /user/hadoop/employee.csv /user/hadoop/employee_bak.csv

# disk usage of a dir
hdfs dfs -du -h /user/hadoop

# free space of the filesystem
hdfs dfs -df -h /
