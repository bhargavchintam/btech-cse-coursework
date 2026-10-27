#!/bin/bash
# lab1 - basic hdfs file operations

# make a working dir in hdfs
hdfs dfs -mkdir -p /user/hadoop/bigdata
hdfs dfs -ls /user/hadoop

# copy a local file into hdfs
hdfs dfs -put /home/hadoop/sample.txt /user/hadoop/bigdata
hdfs dfs -ls /user/hadoop/bigdata

# read it back on the console
hdfs dfs -cat /user/hadoop/bigdata/sample.txt

# copy within hdfs
hdfs dfs -cp /user/hadoop/bigdata/sample.txt /user/hadoop/bigdata/sample_copy.txt

# download from hdfs to local
hdfs dfs -get /user/hadoop/bigdata/sample.txt /home/hadoop/fromhdfs.txt

# size of the dir and rename a file
hdfs dfs -du -h /user/hadoop/bigdata
hdfs dfs -mv /user/hadoop/bigdata/sample_copy.txt /user/hadoop/bigdata/renamed.txt

# replication factor and block size of a file
hdfs dfs -stat "%r %o" /user/hadoop/bigdata/sample.txt

# cleanup
hdfs dfs -rm /user/hadoop/bigdata/renamed.txt
hdfs dfs -rm -r /user/hadoop/bigdata
