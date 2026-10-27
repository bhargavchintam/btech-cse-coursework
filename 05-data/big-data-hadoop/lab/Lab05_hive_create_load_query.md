# Lab 5 - Hive: Create, Load and Query

## Aim
Create a Hive table, load data from a local CSV file and run aggregate queries (count, avg, max, min, group by, order by).

## Software / Environment
- Hadoop 3.1 pseudo-distributed
- Apache Hive 2.3 with metastore configured (Derby)
- `hive` CLI or `beeline`

## Procedure
1. Prepare the local data file `emp.csv`:
   ```
   1,raj,cse,8000
   2,anil,ece,6000
   3,sunil,cse,9000
   4,kiran,ece,7500
   5,arun,cse,7000
   ```
2. Start Hive and run the script:
   ```
   hive -f Lab05_queries.hql
   ```
   or open the `hive>` shell and paste the statements.

## Program
See `Lab05_queries.hql`. Creates database `company`, an `emp` table stored as delimited text, loads `emp.csv` with `LOAD DATA LOCAL INPATH`, then runs GROUP BY / AVG / MAX / MIN / WHERE / ORDER BY queries.

## Output
```
hive> SELECT dept, AVG(sal) FROM emp GROUP BY dept;
cse     8000.0
ece     6750.0

hive> SELECT MAX(sal), MIN(sal) FROM emp;
9000    6000
```

## Result
The Hive table was created and loaded from a local file, and the aggregate queries returned the correct results.
