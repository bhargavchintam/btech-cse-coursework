# What is Hive

**Definition:** Hive is a data warehouse infrastructure built on top of Hadoop, used to query and analyse large datasets stored in HDFS using an SQL-like language. Developed at Facebook, later became Apache Hive. (imp)

- Query language is **HiveQL (HQL)** — SQL-like, so analysts who know SQL need not write raw MapReduce in Java.
- Internally Hive **converts HQL into MapReduce / Tez / Spark jobs** and runs them on the cluster. User writes SQL, Hive does the map-reduce.
- Actual data stays in **HDFS**; the table structure (schema) is kept in a **metastore** (an RDBMS like Derby/MySQL).
- Follows **schema on read** — data is checked against the schema only at query time, not while loading. (asked prev year)
- Meant for **batch processing / OLAP**, not for OLTP or real-time lookups.

## Why Hive
- Writing MapReduce in Java is long and needs programming skill.
- Hive lets a person who knows only SQL run big-data queries.
- Good for **ETL, summarisation, ad-hoc analysis, reporting** on huge data.

## Features
- SQL-like language (HiveQL).
- Works on structured and semi-structured data.
- **Partitioning** and **bucketing** to speed up queries.
- Extensible with **UDF** (user defined functions).
- Runs on Hadoop, so scales to TB/PB of data.

## Limitations (imp)
- High latency — a query launches an MR job, so not real-time.
- Old versions had no row-level UPDATE/DELETE (limited ACID from Hive 0.14+).
- Not suitable for OLTP / online transactions.

## Hive is NOT
- a full RDBMS
- for real-time queries
- for small data (overhead of launching jobs is not worth it)
