# What is Sqoop

**Definition:** Sqoop (**SQ**L + Had**OOP**) is a tool to **transfer bulk data between RDBMS and Hadoop (HDFS/Hive/HBase)**. Used mainly for structured data.

Apache project. Command-line tool. Version used: **Sqoop 1.4.7**.

## Why Sqoop (imp)
- Enterprises keep structured data in RDBMS (MySQL, Oracle, SQL Server, PostgreSQL).
- To analyze it in Hadoop you must move it to HDFS first -> Sqoop does this efficiently.
- Manual export/import (CSV dumps) is slow and error prone for large tables.

## How it works
- Uses **JDBC** to connect to the database.
- Under the hood it launches a **MapReduce job** (map-only, no reducer) to do the transfer in parallel.
- Each mapper pulls a slice of the table -> parallel, fast.
- `-m` (or `--num-mappers`) sets number of parallel mappers (default 4).
- Splits work using the **primary key** (or a column given by `--split-by`).

## Two directions
- **Import** — RDBMS -> HDFS / Hive / HBase.
- **Export** — HDFS -> RDBMS.

## Key points
- Only map tasks, no reduce (nothing to aggregate).
- Import writes to a target dir in HDFS (as text / sequence / avro / parquet).
- Can import full table, part of a table (`--columns`, `--where`), or a free-form `--query`.
- `--hive-import` loads straight into a Hive table.
- Supports incremental import (`append` / `lastmodified`).

## Limitations
- For structured (relational) data only. For logs/streaming -> use **Flume**.
- Needs the JDBC driver jar for that database in `$SQOOP_HOME/lib`.

(2 marks) Sqoop = bulk transfer tool between RDBMS and Hadoop, runs map-only MapReduce over JDBC.
