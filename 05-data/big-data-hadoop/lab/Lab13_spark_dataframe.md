# Lab 13 - Spark DataFrame Operations

## Aim
Create a Spark DataFrame and perform select, filter, groupBy and aggregate operations using the DataFrame API.

## Software / Environment
- Apache Spark 2.4 (PySpark, SparkSession)
- `spark-submit --master local[1]`

## Procedure
1. Run:
   ```
   spark-submit --master local[1] Lab13_dataframe.py
   ```
2. The DataFrame is built from a list of tuples with `createDataFrame`; `printSchema` shows the inferred types.

## Program
See `Lab13_dataframe.py`. Creates a DataFrame of `(id, name, dept, sal)`, then `show`, `printSchema`, `select(...).filter(sal>7000)` and `groupBy("dept").agg(avg("sal"))`.

## Output
```
+---+-----+----+----+
| id| name|dept| sal|
+---+-----+----+----+
|  1|  raj| cse|8000|
|  2| anil| ece|6000|
|  3|sunil| cse|9000|
|  4|kiran| ece|7500|
+---+-----+----+----+

+----+-------+
|dept|avg_sal|
+----+-------+
| ece| 6750.0|
| cse| 8500.0|
+----+-------+
```

## Result
DataFrame creation and the select/filter/groupBy/aggregate operations executed correctly under Spark.
