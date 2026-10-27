# Spark Ecosystem

All the higher libraries sit on **Spark Core** (RDD engine) and share the same execution engine, cluster manager and caching. "Unified stack" is the selling point. (imp)

```
   +--------+  +-----------+  +-------+  +--------+
   | Spark  |  |  Spark    |  | MLlib |  | GraphX |
   |  SQL   |  | Streaming |  |       |  |        |
   +--------+--+-----------+--+-------+--+--------+
   |               Spark  Core (RDD)             |
   +---------------------------------------------+
   | Standalone / YARN / Mesos  (cluster mgr)    |
   +---------------------------------------------+
```

## 1. Spark Core
- Foundation. RDD API, task scheduling, memory management, fault recovery, storage interaction.

## 2. Spark SQL
- Work with **structured** data. Introduces **DataFrame** and **Dataset** (schema on RDD).
- Run **SQL** queries, read JSON/Parquet/Hive/JDBC.
- **Catalyst** optimizer + **Tungsten** engine → faster than plain RDD.
- Replaces the older **Shark**.

## 3. Spark Streaming
- Near **real-time** processing of live data (Kafka, Flume, TCP socket).
- Model = **micro-batch**: stream chopped into small batches, each processed as RDDs = **DStream** (Discretized Stream).
- (Newer **Structured Streaming** in 2.x builds on DataFrames.)

## 4. MLlib
- Scalable **machine learning** library.
- Algorithms: classification, regression, clustering (k-means), collaborative filtering (ALS), decision trees.
- Utilities: feature extraction, pipelines. (`spark.ml` DataFrame-based API is newer.)

## 5. GraphX
- **Graph** processing on Spark.
- Graph-parallel computation, algorithms like **PageRank**, connected components, triangle count.
- Extends RDD with a **Graph** abstraction (vertices + edges).

## Summary table (2 marks)
| Component | Use |
|---|---|
| Spark Core | RDDs, scheduling, base engine |
| Spark SQL | structured data, DataFrames, SQL |
| Spark Streaming | real-time micro-batch (DStream) |
| MLlib | machine learning |
| GraphX | graph algorithms |

- Languages supported across the stack: Scala, Java, Python, R.
