# What is Apache Spark

**Definition:** Apache Spark is an open-source, **in-memory** cluster-computing framework for fast, large-scale data processing. Originally from **UC Berkeley AMPLab** (2009), donated to Apache, top-level project 2014.

- Written in **Scala**, runs on **JVM**. APIs in Scala, Java, Python (PySpark), R.
- General-purpose engine — batch, interactive, iterative, streaming, ML, graph — one stack.
- Does NOT have its own storage. Sits on top of HDFS, S3, Cassandra, HBase etc. (imp)
- Cluster manager: standalone, **YARN**, or Mesos.

## Why Spark (motivation)
- MapReduce writes intermediate results to **disk** after every job → slow for iterative jobs (ML, graph) that reuse data.
- Spark keeps working data in **RAM** across steps → 10x–100x faster for such jobs. (asked prev year)

## Key idea — RDD
- Core abstraction = **RDD** (Resilient Distributed Dataset). Immutable, partitioned collection computed in parallel.
- Fault-tolerant via **lineage** (recompute lost partitions), not replication.

## Main features
- **Speed** — in-memory computation, DAG execution engine.
- **Ease of use** — high-level operators (map, filter, reduceByKey, join), interactive shells (spark-shell, pyspark).
- **Generality** — Spark SQL, Streaming, MLlib, GraphX on same core.
- **Lazy evaluation** — transformations not run until an action is called.
- Runs everywhere — YARN, Mesos, standalone, cloud.

## Spark stack (layers)
| Layer | Purpose |
|---|---|
| Spark Core | RDDs, task scheduling, memory mgmt, fault recovery |
| Spark SQL | structured data, DataFrames, run SQL |
| Spark Streaming | near real-time (micro-batch) |
| MLlib | machine learning library |
| GraphX | graph processing |

- Version in our lab: **Spark 2.4** (2019). Deploy modes: client / cluster.
- 2 marks: Spark = fast, in-memory, general-purpose, sits on HDFS, RDD-based.
