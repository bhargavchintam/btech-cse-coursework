# Hadoop Ecosystem

Hadoop is not a single tool - it is an **ecosystem** of projects built around HDFS + YARN (imp).

## Components (one line each)
- **HDFS** - Hadoop Distributed File System; distributed storage layer, stores data as blocks with replication.
- **MapReduce** - programming model for parallel batch processing (map + reduce).
- **YARN** - Yet Another Resource Negotiator; cluster resource management + job scheduling (from 2.x).
- **Hive** - data warehouse on Hadoop; SQL-like queries (HiveQL) that convert to MapReduce/Tez.
- **Pig** - dataflow scripting language (Pig Latin) for ETL on Hadoop.
- **HBase** - NoSQL column-oriented database on HDFS for real-time random read/write.
- **Sqoop** - transfers bulk data between Hadoop and RDBMS (import / export).
- **Flume** - collects and ingests streaming/log data into HDFS.
- **Spark** - fast in-memory processing engine (batch + streaming + ML).
- **Zookeeper** - coordination service (config, synchronization, leader election) for the cluster.

## Extra (good to know)
- **Oozie** - workflow scheduler for Hadoop jobs.
- **Mahout** - machine learning library.
- **Kafka** - distributed messaging / streaming platform.
- **Ambari** - cluster provisioning, monitoring, management.

## Layered view
| Layer | Tools |
|-------|-------|
| Storage | HDFS, HBase |
| Resource mgmt | YARN |
| Processing | MapReduce, Spark, Tez |
| Data access / query | Hive, Pig |
| Data ingestion | Sqoop, Flume, Kafka |
| Coordination | Zookeeper |
| Workflow | Oozie |
