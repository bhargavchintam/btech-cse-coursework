# Lab 1 - HDFS File Operations

## Aim
Perform the basic HDFS shell file operations - create a directory, put a local file into HDFS, list, read, copy, download, rename, check replication and remove.

## Software / Environment
- Hadoop 3.1 running in pseudo-distributed mode on Ubuntu
- Single node, NameNode + DataNode on localhost
- `JAVA_HOME` set, `hadoop`/`hdfs` on PATH

## Procedure
1. Start the daemons and check they are up:
   ```
   start-dfs.sh
   jps
   ```
   `jps` should show NameNode, DataNode, SecondaryNameNode.
2. Create a sample file in the local fs:
   ```
   echo "big data hadoop hdfs" > /home/hadoop/sample.txt
   ```
3. Run the commands in `Lab01_hdfs_commands.sh`, or execute them one by one:
   ```
   hdfs dfs -mkdir -p /user/hadoop/bigdata
   hdfs dfs -put /home/hadoop/sample.txt /user/hadoop/bigdata
   hdfs dfs -ls /user/hadoop/bigdata
   hdfs dfs -cat /user/hadoop/bigdata/sample.txt
   hdfs dfs -cp /user/hadoop/bigdata/sample.txt /user/hadoop/bigdata/sample_copy.txt
   hdfs dfs -get /user/hadoop/bigdata/sample.txt /home/hadoop/fromhdfs.txt
   hdfs dfs -mv /user/hadoop/bigdata/sample_copy.txt /user/hadoop/bigdata/renamed.txt
   hdfs dfs -stat "%r %o" /user/hadoop/bigdata/sample.txt
   hdfs dfs -rm -r /user/hadoop/bigdata
   ```

## Program
See `Lab01_hdfs_commands.sh`.

## Output
```
$ hdfs dfs -ls /user/hadoop/bigdata
Found 1 items
-rw-r--r--   1 hadoop supergroup   21 2020-08-12 10:15 /user/hadoop/bigdata/sample.txt

$ hdfs dfs -cat /user/hadoop/bigdata/sample.txt
big data hadoop hdfs

$ hdfs dfs -stat "%r %o" /user/hadoop/bigdata/sample.txt
1 134217728
```
(replication 1, block size 128 MB in pseudo-distributed mode)

## Result
Basic HDFS file operations were executed successfully and files were created, read, copied, moved and removed on HDFS.
