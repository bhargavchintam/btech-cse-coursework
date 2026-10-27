# Introduction to HDFS

**Definition:** HDFS = **Hadoop Distributed File System**, the storage layer of Hadoop. A distributed file system that stores very large files across a cluster of commodity machines. (2 marks)

- Based on Google File System (GFS) paper, 2003.
- Written in Java. Runs on commodity hardware (no need for costly RAID servers).
- Follows **write-once, read-many** model. File once written is not updated in place.
- Files split into **blocks**, blocks spread across DataNodes, each block replicated for fault tolerance.

## Why HDFS (need)
- Single machine disk cannot hold TB/PB scale data.
- Reading 1 TB from one disk is slow — split across many disks and read in parallel = high throughput.
- Commodity hardware fails often; HDFS keeps replicas so no data loss.

## Design goals / assumptions (imp)
- **Hardware failure is the norm**, not exception. Detect faults, recover automatically.
- **Streaming data access** — batch processing, high throughput over low latency.
- **Large datasets** — files from GB to TB. Tuned for large files, not many small ones.
- **Simple coherency model** — write once, read many. Append supported, random writes not.
- **Moving computation is cheaper than moving data** — run the computation near the data (data locality).
- **Portability** across heterogeneous hardware and OS.

## Where HDFS is NOT a good fit (asked prev year)
- **Low-latency access** (ms response) — use HBase instead.
- **Lots of small files** — each file/block/dir takes ~150 bytes of NameNode RAM, so millions of small files overload the NameNode.
- **Multiple writers / arbitrary file modification** — one writer, appends at end of file only.

## Key terms
- **Block** — fixed-size chunk of a file (default 128 MB in Hadoop 2.x/3.x).
- **NameNode** — master, holds metadata.
- **DataNode** — slave, stores actual blocks.
- **Replication factor** — number of copies of each block (default 3).
