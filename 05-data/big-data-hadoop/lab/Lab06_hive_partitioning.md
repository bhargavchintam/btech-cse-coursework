# Lab 6 - Hive Partitioning and Bucketing

## Aim
Demonstrate static and dynamic partitioning of a Hive table on the `dept` column, and create a bucketed table.

## Software / Environment
- Hadoop 3.1 pseudo-distributed
- Apache Hive 2.3

## Procedure
1. Uses database `company` and the base `emp` table from Lab 5.
2. For static partitioning, prepare per-department files (no dept column inside):
   `cse.csv`
   ```
   1,raj,8000
   3,sunil,9000
   5,arun,7000
   ```
   `ece.csv`
   ```
   2,anil,6000
   4,kiran,7500
   ```
3. Run the script:
   ```
   hive -f Lab06_partition.hql
   ```
4. For dynamic partitioning `hive.exec.dynamic.partition.mode=nonstrict` is set so all partitions come from the SELECT. Note the partition column `dept` is the last column in the SELECT list.

## Program
See `Lab06_partition.hql`. Creates `emp_part` (static loads per partition), `emp_dyn` (dynamic partition INSERT from `emp`) and `emp_bucket` (`CLUSTERED BY (id) INTO 4 BUCKETS`).

## Output
```
hive> SHOW PARTITIONS emp_part;
dept=cse
dept=ece

hive> SELECT * FROM emp_part WHERE dept='cse';
1   raj    8000  cse
3   sunil  9000  cse
5   arun   7000  cse
```
Each partition is a sub-directory under the table dir, e.g. `/user/hive/warehouse/company.db/emp_part/dept=cse`. The bucketed table stores 4 files.

## Result
Static and dynamic partitioning and bucketing were demonstrated; partition pruning makes `WHERE dept=...` read only the relevant partition.
