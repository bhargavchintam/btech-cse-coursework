# Big Data vs Traditional Data

Differentiate Big Data from traditional (RDBMS) data (imp - table question).

| Point | Traditional Data | Big Data |
|-------|-----------------|----------|
| Volume | GB, limited | TB, PB, EB |
| Data type | structured only | structured + semi + unstructured |
| Schema | schema-on-write (fixed) | schema-on-read (flexible) |
| Storage | centralized, RDBMS | distributed, HDFS / cluster |
| Scaling | vertical (scale up) | horizontal (scale out) |
| Hardware | high-end servers | commodity machines |
| Processing | serial, one machine | parallel, many nodes |
| Relationship | known relations (keys) | may be unknown |
| Cost | costly per TB | cheaper per TB |
| Tools | SQL, RDBMS | Hadoop, Spark, NoSQL |
| Data integrity | high (ACID) | eventual / relaxed |

## Key differences in words
- Traditional systems **scale up** (bigger box); Big Data **scales out** (more boxes).
- RDBMS applies schema **when writing**; Big Data applies schema **when reading**.
- RDBMS moves data to the program; Hadoop moves the program to the data.
- RDBMS = structured only; Big Data = any format.
