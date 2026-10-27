# What is HBase

**Definition:** HBase is a **distributed, column-oriented NoSQL database** that runs on top of **HDFS**. It gives real-time random read/write access to Big Data. Written in Java, modelled on Google's **BigTable** paper.

Part of the Hadoop ecosystem. Apache top-level project.

## Why HBase (imp)
- HDFS gives batch access only, no random read/write. HBase fills that gap.
- MapReduce/Hive good for scan of full data, bad for looking up a single row fast.
- HBase -> fast lookup by **row key**, updates on single records.

## Key points
- **Column-oriented** (not row-oriented like RDBMS).
- **Schema-less** — only column family must be defined in advance, columns can be added on the fly.
- **Sparse** — a row need not have all columns. Empty cells take no space.
- **Sorted** — rows stored sorted by row key (lexicographic).
- **Versioned** — each cell keeps multiple versions by timestamp.
- **Linearly scalable** — add region servers to handle more data.
- Handles **billions of rows x millions of columns**.

## CAP
- HBase is **CP** (Consistency + Partition tolerance). Strongly consistent, not eventually consistent like Cassandra.

## When to use
- Very large data (TB to PB), sparse data, need random real-time read/write.
- Do NOT use for small data or when you need joins / full SQL / transactions across rows.

## Built on top of
- **HDFS** for storage, **Zookeeper** for coordination, integrates with **MapReduce** for bulk processing.

(2 marks) HBase = Hadoop database, column-oriented, on HDFS, based on Google BigTable.
