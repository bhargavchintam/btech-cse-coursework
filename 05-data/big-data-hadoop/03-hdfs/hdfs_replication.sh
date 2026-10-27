#!/bin/bash
# set and check replication factor

# default rep is 3, drop this one file to 2 and wait
hdfs dfs -setrep -w 2 /user/hadoop/employee.csv

# set rep back to 3 for a whole dir (recursive)
hdfs dfs -setrep -R 3 /user/hadoop

# check replication with stat
# %r = replication, %o = block size, %b = size in bytes, %n = name
hdfs dfs -stat "%r %o %b %n" /user/hadoop/employee.csv
