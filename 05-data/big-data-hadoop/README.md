<p align="center"><img src="assets/banner.svg" alt="Big Data and Hadoop" width="100%"></p>

# Big Data and Hadoop

My notes and lab work for **Big Data and Hadoop** at **REVA University, Bengaluru** (B.Tech, 2020). Theory from what big data actually is through the whole Hadoop ecosystem, and a lab side that goes hands-on with HDFS, MapReduce (Java and Python streaming), Hive, Pig, HBase, Sqoop and Spark.

141 files — notes in markdown, and lab code that runs against real Hadoop and Spark.

## Structure

Folders in the order the topics were taught.

| Folder | What's in it | Files |
|---|---|---|
| `01-introduction-big-data/` | What big data is, the 5 V's, sources, analytics types | 8 |
| `02-hadoop-basics/` | Hadoop, its history, the ecosystem, daemons, vs RDBMS | 7 |
| `03-hdfs/` | HDFS architecture, blocks/replication + `hdfs dfs` shell scripts | 10 |
| `04-mapreduce/` | Map/reduce phases + Java MapReduce + Python streaming | 17 |
| `05-yarn/` | YARN architecture, components, schedulers | 6 |
| `06-hive/` | Hive architecture notes + HiveQL scripts (DDL, joins, partitioning) | 14 |
| `07-pig/` | Pig Latin notes + `.pig` scripts | 10 |
| `08-hbase/` | HBase data model notes + HBase shell scripts | 9 |
| `09-sqoop-flume/` | Sqoop import/export + a Flume agent config | 9 |
| `10-spark/` | Spark/RDD notes + PySpark (RDD and DataFrame) | 14 |
| `11-nosql-advanced/` | NoSQL types, CAP theorem, serialization, streaming | 8 |
| `lab/` | The 14 numbered lab records with their code | 29 |

## Running the lab code

Everything was written against a pseudo-distributed Hadoop 3.x setup and Spark 2.4.

```sh
# Java MapReduce — compile against the hadoop classpath, jar it, run
javac -cp "$(hadoop classpath)" -d wc_classes 04-mapreduce/WordCount.java
jar cf wc.jar -C wc_classes .
hadoop jar wc.jar WordCount /input /output

# Python streaming — test the logic locally with a pipe first
cat input.txt | python3 04-mapreduce/streaming_mapper.py | sort | python3 04-mapreduce/streaming_reducer.py
# then on the cluster with hadoop-streaming.jar

# Spark
spark-submit --master local 10-spark/word_count.py

# Hive / Pig
hive -f 06-hive/05_group_by_aggregate.hql
pig 07-pig/06_word_count.pig
```

The Java jobs compile against `hadoop classpath`, the streaming mapper/reducer run through a plain shell pipe, and the PySpark scripts run under `spark-submit local`. The block size is the Hadoop 2/3 default of 128 MB, replication factor 3, and the Spark code is the 2.4-era RDD and DataFrame API.

## A note on what's verified

The Java MapReduce, Python streaming and PySpark code was actually compiled and run — the streaming word count comes out right through a pipe, and the Spark jobs run under `spark-submit`. The Hive, Pig, HBase and Sqoop scripts are written for those engines but weren't run here (they need a live metastore / RegionServer / a database), so they're correct by syntax and by hand, not by execution. The notes are exam-prep notes checked for the facts (the 5 V's, the GFS/MapReduce papers, YARN arriving in Hadoop 2.x, CAP theorem, block size and replication defaults).

## The bugs I actually hit

A few of them are in the commit history:

- A Python streaming reducer that dropped the **last word** because it never emitted the final key after the loop ended.
- A Java WordCount whose `setOutputValueClass` was `LongWritable` while the reducer emitted `IntWritable` — compiles fine, blows up at run time with a type mismatch.
- A Hive `GROUP BY` that selected `salary` without grouping or aggregating it.

## Lab

`lab/` holds the 14 numbered exercises — HDFS file operations, word count in both Java MapReduce and Python streaming, max temperature, Hive create/load/query/partition/join, Pig analysis, HBase CRUD, Sqoop import/export, and three Spark labs. Each writeup has the aim, the real commands, and the output.
