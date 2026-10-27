#!/bin/bash
# sqoop export - HDFS -> mysql (target table must already exist)

# table emp_out created in mysql first:
# CREATE TABLE emp_out (id INT, name VARCHAR(30), dept VARCHAR(20), sal INT);

sqoop export \
  --connect jdbc:mysql://localhost/testdb \
  --username root \
  --password root \
  --table emp_out \
  --export-dir /user/hadoop/emp \
  --input-fields-terminated-by ',' \
  -m 1

echo "export done, verify with: mysql -u root -p -e 'select * from testdb.emp_out'"
