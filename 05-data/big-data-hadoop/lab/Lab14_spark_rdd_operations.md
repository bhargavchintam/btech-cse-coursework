# Lab 14 - Spark RDD Operations

## Aim
Demonstrate common Spark RDD transformations and actions - parallelize, count, reduce, max, filter, map and reduceByKey.

## Software / Environment
- Apache Spark 2.4 (PySpark)
- `spark-submit --master local[1]`

## Procedure
1. Run:
   ```
   spark-submit --master local[1] Lab14_rdd_ops.py
   ```
2. `parallelize` creates an RDD from a Python list; `count`, `reduce`, `max` and `collect` are actions (they trigger execution), while `filter` and `map` are lazy transformations.

## Program
See `Lab14_rdd_ops.py`. Builds a numeric RDD and applies count/sum/max, filters evens, maps to squares, and does a `(word,1)` + `reduceByKey` word frequency.

## Output
```
count: 10
sum: 55
max: 10
evens: [2, 4, 6, 8, 10]
squares: [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
wordfreq: [('hadoop', 2), ('hive', 1), ('spark', 3)]
```

## Result
The Spark RDD transformations and actions were executed successfully and produced the expected results.
