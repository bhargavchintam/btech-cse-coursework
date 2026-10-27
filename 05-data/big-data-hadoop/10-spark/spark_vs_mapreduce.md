# Spark vs MapReduce

Common exam question — differentiate Hadoop MapReduce and Spark. (asked prev year)

## Core difference
- **MapReduce** — disk-based. After map, intermediate output written to disk, shuffled, reduce reads from disk. Every job = read HDFS -> process -> write HDFS.
- **Spark** — in-memory. Keeps intermediate data in RAM, reuses across stages. Falls back to disk only if data does not fit.

## Comparison table (imp)
| Point | MapReduce | Spark |
|---|---|---|
| Processing | disk-based (batch) | in-memory |
| Speed | slower | 10x–100x faster (esp. iterative) |
| Data model | key-value, 2 stages (map, reduce) | RDD / DataFrame, DAG of stages |
| Iterative jobs | writes to disk each pass → costly | caches in memory → cheap |
| Ease of coding | verbose Java, boilerplate | concise (map, filter, reduceByKey) |
| Interactive | no | yes (spark-shell, pyspark) |
| Streaming | no (batch only) | yes (Spark Streaming) |
| Fault tolerance | replication + re-run task | RDD **lineage** (recompute) |
| Latency | high | low |

## Why Spark is faster
- No repeated disk I/O between steps.
- **DAG** execution engine optimises the whole job (pipelines narrow transformations), vs MR's rigid map-then-reduce.
- In-memory **caching** (`persist`/`cache`) — reuse a dataset many times, read once.

## When MapReduce still fits
- One-pass batch on huge data that won't fit memory, cost-sensitive, no iteration.
- Very mature, stable, part of core Hadoop.

## Note
- Spark does NOT replace HDFS — it replaces the MR **processing** layer. Storage stays HDFS.
- Spark can still run on YARN alongside MR jobs.
