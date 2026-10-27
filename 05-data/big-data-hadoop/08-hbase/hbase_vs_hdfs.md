# HBase vs HDFS

Both store Big Data, but different purpose. HBase actually runs **on top of** HDFS.

| Point | HDFS | HBase |
|-------|------|-------|
| What it is | Distributed file system | Database (NoSQL) on top of HDFS |
| Access | Batch, sequential | Random real-time read/write |
| Unit | Files and blocks | Tables, rows, cells |
| Update | Write-once, append only, no random update | Update / delete individual cells |
| Lookup | No fast single-record lookup | Fast lookup by row key |
| Best for | Store + batch scan of whole file (MapReduce) | Point queries, low-latency R/W |
| Schema | No concept of records | Row key + column families |
| Latency | High (batch) | Low (real-time) |

## Key idea (imp)
- HDFS is good at storing large files and scanning them fully.
- HDFS is bad when you want row 5,000,000 quickly, or want to update one field.
- HBase sits on HDFS and adds indexing (row key), MemStore/BlockCache and WAL to give random access.
- So they are **not competitors** — HBase uses HDFS as its storage layer.

## Analogy
- HDFS = the disk / file store.
- HBase = the database engine that organizes and serves records from that store.

(2 marks) HDFS = batch file storage, write-once; HBase = random real-time R/W database built over HDFS.
