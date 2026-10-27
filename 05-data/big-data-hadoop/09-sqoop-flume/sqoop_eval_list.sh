#!/bin/bash
# sqoop eval / list-databases / list-tables - quick checks without running a full import

# list databases on the server
sqoop list-databases \
  --connect jdbc:mysql://localhost/ \
  --username root \
  --password root

# list tables in testdb
sqoop list-tables \
  --connect jdbc:mysql://localhost/testdb \
  --username root \
  --password root

# run a SQL query directly and print result (no HDFS write)
sqoop eval \
  --connect jdbc:mysql://localhost/testdb \
  --username root \
  --password root \
  --query "SELECT dept, COUNT(*) FROM emp GROUP BY dept"

# eval can also run DML, e.g. a quick insert
sqoop eval \
  --connect jdbc:mysql://localhost/testdb \
  --username root \
  --password root \
  --query "INSERT INTO emp VALUES (10,'ravi','it',40000)"
