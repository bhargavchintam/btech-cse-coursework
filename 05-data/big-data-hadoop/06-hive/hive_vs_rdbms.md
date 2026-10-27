# Hive vs RDBMS

Common exam question — "Differentiate Hive and RDBMS". (imp - 5 marks)

| Point | Hive | RDBMS |
|-------|------|-------|
| Schema | Schema on **read** (checked at query time) | Schema on **write** (checked at load time) |
| Data size | TB to PB (very large) | GB range (limited) |
| Language | HiveQL (SQL-like) | SQL |
| Processing | MapReduce / Tez jobs | own execution engine |
| Latency | High (batch, minutes) | Low (sub-second) |
| Use case | OLAP, analytics, reporting | OLTP, transactions |
| Updates/Deletes | limited (ACID from 0.14+) | full support |
| Records | read many, write once | frequent insert/update/delete |
| Cost | runs on commodity hardware | costly high-end servers |
| Indexes | limited | rich indexing |
| Data location | HDFS | local disk / DB storage |

## Key points to write
- Hive is **not** a database, it is a **data warehouse** layer over Hadoop.
- **Schema on read** is the biggest difference — Hive does not verify data during LOAD, so loading is fast but bad rows show as NULL at query time. (asked prev year)
- RDBMS is for **transactions** (bank, booking), Hive is for **analysis** on huge historical data.
- Hive gives high **throughput**, RDBMS gives low **latency**.
