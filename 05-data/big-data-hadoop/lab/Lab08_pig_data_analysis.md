# Lab 8 - Data Analysis using Pig

## Aim
Analyse employee data using Apache Pig - filter high paid employees, group by department and compute the average salary and count per department.

## Software / Environment
- Hadoop 3.1 pseudo-distributed
- Apache Pig 0.17 (MapReduce mode)

## Procedure
1. Put the data in HDFS:
   ```
   hdfs dfs -put emp.csv /user/hadoop/emp.csv
   ```
   `emp.csv`
   ```
   1,raj,cse,8000
   2,anil,ece,6000
   3,sunil,cse,9000
   4,kiran,ece,7500
   ```
2. Run the script in MapReduce mode:
   ```
   pig -x mapreduce Lab08_analysis.pig
   ```
   (use `pig -x local Lab08_analysis.pig` to test on the local fs)

## Program
See `Lab08_analysis.pig`. LOAD with schema -> FILTER `sal>7000` -> GROUP BY dept -> FOREACH ... GENERATE AVG and COUNT -> ORDER BY avg_sal DESC -> DUMP and STORE.

## Output
```
(cse,8500.0,2)
(ece,6750.0,2)
```

## Result
Pig Latin was used to filter, group and aggregate the employee data, and the average salary per department was computed correctly.
