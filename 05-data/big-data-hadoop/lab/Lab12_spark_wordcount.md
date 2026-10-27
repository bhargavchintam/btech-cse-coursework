# Lab 12 - Spark Word Count

## Aim
Implement word count in Apache Spark using the RDD transformations flatMap, map and reduceByKey.

## Software / Environment
- Apache Spark 2.4 (PySpark)
- Runs in local mode: `spark-submit --master local[1]`

## Procedure
1. Run the program:
   ```
   spark-submit --master local[1] Lab12_wordcount.py
   ```
2. In this program the input lines are built with `sc.parallelize`. To read a real file instead, replace it with `sc.textFile("hdfs:///user/hadoop/input.txt")`.

## Program
See `Lab12_wordcount.py`. `flatMap` splits each line into words, `map` turns each word into `(word, 1)`, and `reduceByKey` adds the counts per word; the result is collected and printed.

## Output
```
big     2
data    2
hadoop  2
mapreduce       1
spark   3
```

## Result
The Spark word count program ran under spark-submit and produced the correct word frequencies using RDD operations.
