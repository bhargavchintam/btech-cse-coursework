# What is Big Data

**Definition:** Big Data refers to datasets that are so **large, fast-arriving and complex** that traditional data processing tools (single machine, RDBMS) cannot store or process them in a reasonable time.

- Data has grown beyond the storage + memory of one machine.
- Needs **distributed** storage and **distributed** processing across a cluster of commodity machines.
- Scale is TB / PB / EB now, not MB / GB.

## Why traditional systems fail (imp)
- RDBMS is built for **structured** data + limited volume.
- Vertical scaling (buy a bigger machine) is costly and hits a ceiling.
- Cannot handle unstructured data (video, images, logs) well.
- Reading PB of data from one disk is too slow (I/O bottleneck).

## The idea behind Big Data
- **Scale out** (horizontal) instead of scale up - add more cheap machines.
- **Move computation to the data**, not data to the computation.
- Store data across many nodes, process it in parallel.
- Main frameworks: **Hadoop**, Spark.

## Units of data
| Unit | Size |
|------|------|
| KB | 1024 B |
| MB | 1024 KB |
| GB | 1024 MB |
| TB | 1024 GB |
| PB | 1024 TB |
| EB | 1024 PB |

## Quick points (2 marks)
- Big Data is defined by the **5 V's** (Volume, Velocity, Variety, Veracity, Value).
- Data is stored on a cluster, processed in parallel.
- Commodity hardware = cheap, ordinary machines, not high-end servers.
