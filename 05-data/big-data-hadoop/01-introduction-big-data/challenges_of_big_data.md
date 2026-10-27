# Challenges of Big Data

Handling Big Data brings several challenges (2 marks / 5 marks).

## Main challenges
- **Storage** - PB/EB of data cannot fit on one machine, need distributed storage.
- **Processing** - analysing huge data on a single CPU is too slow, need parallel processing.
- **Data quality (veracity)** - data is noisy, incomplete, inconsistent; cleaning is hard.
- **Variety** - mixing structured + unstructured data from many sources.
- **Velocity** - real-time / streaming data must be processed quickly.
- **Scalability** - system must grow as data grows, without rewrite.
- **Security & privacy** - protecting sensitive data (financial, medical).
- **Cost** - infrastructure and skilled manpower.
- **Fault tolerance** - many nodes -> hardware failure is common, must not lose data.
- **Skill gap** - shortage of trained big data engineers / data scientists.

## Grouped (Gartner style)
| Area | Challenge |
|------|-----------|
| Capturing | collecting data from many sources |
| Storage | where to keep PB of data |
| Curation / cleaning | fixing dirty data |
| Analysis | processing in parallel |
| Sharing / transfer | moving huge data |
| Visualization | showing results usefully |
| Privacy / security | protecting the data |

## How Hadoop solves some of these
- Distributed storage -> **HDFS**.
- Parallel processing -> **MapReduce / YARN**.
- Fault tolerance -> block **replication** (default 3 copies).
- Scalability -> just add commodity nodes.
