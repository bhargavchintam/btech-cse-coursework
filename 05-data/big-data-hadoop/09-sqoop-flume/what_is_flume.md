# What is Flume

**Definition:** Apache Flume is a distributed, reliable service for **collecting, aggregating and moving large amounts of streaming / log data** into HDFS (or HBase).

Used for **unstructured / semi-structured** streaming data. Sqoop is for structured RDBMS data — Flume is for logs and event streams. (imp)

## Why Flume
- Web servers, application servers generate huge log streams continuously.
- Need to move these logs into HDFS for analysis, in near real-time.
- Flume ingests this stream reliably without losing events.

## Use cases
- Web server log collection.
- Social media / clickstream / sensor data ingestion.
- Any continuous event data -> HDFS.

## Key features
- **Streaming** data flow (event by event), not batch.
- **Reliable** — uses transactions between components; channel buffers events so nothing is lost if sink is slow / down.
- **Scalable / distributed** — run many agents, fan-in and fan-out flows.
- **Configuration driven** — a flow is defined in a properties file (no code needed for common sources/sinks).

## Event
- **Definition:** the basic unit of data in Flume = a byte payload (the log line) + optional headers (map of key/value).
- Events flow: source -> channel -> sink.

## Sqoop vs Flume

| Point | Sqoop | Flume |
|-------|-------|-------|
| Data | Structured (RDBMS) | Streaming logs / events |
| Model | Bulk, batch pull | Continuous stream push |
| Driven by | JDBC + MapReduce | Agents (source/channel/sink) |
| Direction | RDBMS <-> HDFS | Log sources -> HDFS/HBase |

(2 marks) Flume = tool to ingest streaming/log data into HDFS; event-driven, reliable, config-based.
