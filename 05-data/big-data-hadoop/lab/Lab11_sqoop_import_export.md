# Lab 11 - Sqoop Import and Export

## Aim
Use Sqoop to import a table from MySQL into HDFS and Hive, and export processed data from HDFS back into MySQL.

## Software / Environment
- Hadoop 3.1 pseudo-distributed
- Apache Sqoop 1.4.7
- MySQL 5.7 with `mysql-connector-java.jar` in `$SQOOP_HOME/lib`

## Procedure
1. Create the source table in MySQL:
   ```
   CREATE DATABASE company;
   USE company;
   CREATE TABLE employees(id INT PRIMARY KEY, name VARCHAR(20), sal INT);
   INSERT INTO employees VALUES (1,'raj',8000),(2,'anil',6000),(3,'sunil',9000);
   CREATE TABLE employees_out(id INT, name VARCHAR(20), sal INT);
   ```
2. Check the connection:
   ```
   sqoop list-tables --connect jdbc:mysql://localhost/company --username root --password root
   ```
3. Run the commands in `Lab11_sqoop.sh`. `-m 1` uses a single mapper (needed when the table has no numeric primary key to split on).
4. Verify the import in HDFS:
   ```
   hdfs dfs -cat /user/hadoop/employees/part-m-00000
   ```

## Program
See `Lab11_sqoop.sh` - import to HDFS, import to Hive, import selected columns with a `--where` filter, and export back to MySQL.

## Output
```
$ hdfs dfs -cat /user/hadoop/employees/part-m-00000
1,raj,8000
2,anil,6000
3,sunil,9000
```
After export, `SELECT * FROM employees_out;` in MySQL shows the same rows.

## Result
Sqoop successfully transferred data from MySQL to HDFS/Hive and exported it back to MySQL.
