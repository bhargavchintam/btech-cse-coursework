# RDD Concepts

**Definition:** **RDD = Resilient Distributed Dataset** — the fundamental data structure of Spark. An immutable, partitioned collection of records that can be processed in parallel across the cluster. (imp)

Break the name down (2 marks):
- **Resilient** — fault-tolerant, rebuilds lost partitions using **lineage**.
- **Distributed** — data split into **partitions** spread over nodes.
- **Dataset** — a collection of records (from file, or a parallelized collection).

## Properties
- **Immutable** — cannot change an RDD in place; a transformation makes a **new** RDD.
- **Partitioned** — unit of parallelism = partition; one task per partition.
- **Lazy** — nothing runs until an action.
- **In-memory** — can be cached/persisted for reuse.
- **Typed** — holds objects (e.g. String, Int, tuple).

## Ways to create RDD
1. **Parallelize** an existing collection — `sc.parallelize([1,2,3])`.
2. From **external storage** — `sc.textFile("hdfs://.../input")`.
3. From an existing RDD (transformation).

## Two kinds of operations
### Transformations (lazy, return a new RDD)
- **map**, **filter**, **flatMap**, **distinct**, **union**, **reduceByKey**, **groupByKey**, **sortByKey**, **join**.
- **Narrow** — each input partition → one output partition (map, filter). No shuffle.
- **Wide** — data moves across partitions (reduceByKey, groupByKey, join). Causes a **shuffle**. (imp)

### Actions (trigger execution, return a value / write out)
- **collect**, **count**, **first**, **take(n)**, **reduce**, **saveAsTextFile**, **foreach**.

> Rule: transformation = RDD -> RDD (lazy). action = RDD -> value/disk (runs the DAG).

## Lazy evaluation
- Transformations only build the **lineage / DAG**; no computation yet.
- When an action is called, Spark plans the whole DAG and runs it — lets it **optimise** and pipeline.
- e.g. `rdd.map(f).filter(g).count()` — map+filter run only at `count()`.

## Lineage & fault tolerance
- Spark records how each RDD was built from its parents = **lineage graph**.
- If a partition is lost (node failure), Spark **recomputes** it from the lineage — no data replication needed.

## Persistence
- `cache()` — keep RDD in memory (MEMORY_ONLY).
- `persist(level)` — choose level: MEMORY_ONLY, MEMORY_AND_DISK, DISK_ONLY, etc.
- Use when an RDD is reused across multiple actions (iterative jobs).
