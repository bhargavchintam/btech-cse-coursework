# What is Hadoop

**Definition:** Hadoop is an **open-source framework** (Apache) for **distributed storage and distributed processing** of very large datasets across clusters of commodity hardware.

- Written in **Java**.
- Handles storage (HDFS) + processing (MapReduce / YARN).
- Designed to scale from a single machine to thousands of nodes.

## Core idea
- Split a huge file into blocks, store the blocks on many machines.
- Run the computation **in parallel** on the machines that hold the data (data locality).
- Handle machine failures automatically (replication).

## Core components (imp)
| Component | Role |
|-----------|------|
| **HDFS** | distributed storage (Hadoop Distributed File System) |
| **MapReduce** | distributed processing / programming model |
| **YARN** | resource management + job scheduling (from Hadoop 2.x) |
| Hadoop Common | shared utilities / libraries |

## Features
- **Scalable** - just add commodity nodes (scale out).
- **Fault tolerant** - blocks are replicated (default 3 copies).
- **Cost effective** - runs on cheap hardware.
- **Data locality** - move computation to data.
- **Flexible** - stores structured + unstructured data (schema-on-read).
- **High throughput** - parallel processing.

## Note
- Hadoop is **not a database**; it is a framework / ecosystem.
- Best for **batch** processing of large data (not for real-time OLTP).
