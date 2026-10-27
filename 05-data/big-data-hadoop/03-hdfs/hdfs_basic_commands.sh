#!/bin/bash
# basic hdfs dfs commands - lab

# make dirs
hdfs dfs -mkdir /user/hadoop
hdfs dfs -mkdir -p /user/hadoop/input

# put a local file into hdfs
hdfs dfs -put /home/hadoop/data.txt /user/hadoop/input

# list
hdfs dfs -ls /user/hadoop/input

# show file content
hdfs dfs -cat /user/hadoop/input/data.txt

# get file back to local
hdfs dfs -get /user/hadoop/input/data.txt /home/hadoop/data_out.txt

# remove file, then the dir
hdfs dfs -rm /user/hadoop/input/data.txt
hdfs dfs -rm -r /user/hadoop/input
