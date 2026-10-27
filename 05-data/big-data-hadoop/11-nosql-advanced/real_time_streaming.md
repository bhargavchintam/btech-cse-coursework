# Real-Time Streaming (Kafka, Spark Streaming)

**Definition:** **Stream processing** = processing data **continuously as it arrives** (real-time / near real-time), instead of collecting it and running one big **batch** job later. (imp)

## Batch vs Stream
| Point | Batch | Stream |
|---|---|---|
| Data | bounded, stored first | unbounded, continuous |
| Latency | high (min/hours) | low (ms/sec) |
| Example tool | MapReduce, Hive | Kafka + Spark Streaming |
| Use | reports, ETL | fraud alert, live dashboard |

## Apache Kafka
- **Definition:** distributed, high-throughput **publish-subscribe messaging** system / streaming platform. From LinkedIn. Acts as a **message broker / buffer** between producers and consumers.
- Core terms:
  - **Producer** — publishes messages.
  - **Consumer** — subscribes / reads messages.
  - **Topic** — named stream/category of messages.
  - **Partition** — topic split for parallelism + ordering within partition.
  - **Broker** — a Kafka server; a **cluster** = many brokers.
  - **Offset** — position of a message in a partition.
  - **Consumer group** — consumers sharing the load of a topic.
- Uses **ZooKeeper** for broker/metadata coordination (2020 era).
- Durable (writes to disk, replicated), scalable, decouples producers from consumers.

## Spark Streaming
- **Definition:** Spark component for scalable, fault-tolerant **stream processing**.
- Model = **micro-batch**: incoming stream chopped into small time batches (e.g. every 1s), each batch processed as an **RDD**.
- **DStream** (Discretized Stream) = continuous sequence of RDDs.
- Sources: **Kafka**, Flume, TCP socket, HDFS.
- Same API as batch Spark → same code style, reuses MLlib / Spark SQL.
- Newer **Structured Streaming** (2.x) = stream as an unbounded **DataFrame**.

## Typical real-time pipeline
```
producers -> Kafka (topic) -> Spark Streaming -> HDFS / HBase / dashboard
```

## Use cases
- Fraud/anomaly detection, live recommendation, log/monitoring, IoT sensor data, real-time dashboards.

## 2 marks
- Kafka = distributed pub-sub message broker (topics, partitions, producers, consumers).
- Spark Streaming = micro-batch stream processing; DStream = sequence of RDDs; often fed by Kafka.
