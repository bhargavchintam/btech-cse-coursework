# MapReduce - Introduction

**Definition:** MapReduce is a programming model + processing engine for writing applications that process large data sets in parallel across a Hadoop cluster of commodity hardware. Given by Google (Dean & Ghemawat, 2004), Hadoop is the open-source implementation.

Works on the principle of **"move computation to the data"** — code is shipped to the node holding the block, not the other way. (imp)

## Why MapReduce (2 marks)
- Data is too big for one machine -> split across nodes, process in parallel.
- Handles node failure automatically (failed task re-run on another node).
- Programmer writes only two functions (map, reduce); framework handles the hard parts — parallelisation, scheduling, data distribution, fault tolerance.

## Key idea - everything is a (key, value) pair
- Map and Reduce both take k-v pairs in and give k-v pairs out.
- General form:
  - map:    (k1, v1)        -> list(k2, v2)
  - reduce: (k2, list(v2))  -> list(k3, v3)

## The two functions
- **Map:** takes one input record, produces zero or more intermediate k-v pairs. Runs in parallel, one map task per input split.
- **Reduce:** takes a key and the list of all values for that key, produces the final output. Runs after shuffle & sort.

Between them the framework does **shuffle and sort** — group all values by key and hand them to the reducer sorted.

## Features
- **Scalability** — add nodes, throughput grows near-linearly.
- **Fault tolerance** — re-executes failed/slow (speculative) tasks.
- **Data locality** — schedule map task on the node that has the block.
- **Simplicity** — hides parallelism from the programmer.
- Written mainly in **Java**; other languages via **Hadoop Streaming** (stdin/stdout) and **Pipes** (C++).

## Who runs the job (Hadoop 2.x / 3.x on YARN)
- **ResourceManager** — cluster-wide resource scheduling.
- **NodeManager** — per-node, launches and monitors containers.
- **ApplicationMaster (MRAppMaster)** — one per job, negotiates containers, drives the map and reduce tasks.

> In old Hadoop 1.x this was **JobTracker** (one master) + **TaskTracker** (per node). Replaced by YARN because JobTracker was a bottleneck + single point of failure. (asked prev year)

## Anatomy of a job run
1. Client submits job to ResourceManager.
2. RM starts an ApplicationMaster in a container.
3. AM asks RM for containers, launches map tasks (one per split), then reduce tasks.
4. Intermediate map output written to local disk; reducers pull it over the network.
5. Final output written to HDFS (part-r-00000, part-r-00001, ...).

## Limitations
- Not for real-time / low-latency queries (batch only) — for that use Spark, Hive-on-Tez, HBase.
- Not for iterative algorithms (each iteration = full job, disk I/O each time) — Spark is far better.
- Lot of boilerplate for simple tasks.
