-- load a comma separated file and store it back
-- emp.txt rows: 101,ravi,1,55000  (id,name,deptid,sal)

emp = LOAD '/home/hadoop/data/emp.txt' USING PigStorage(',')
      AS (id:int, name:chararray, deptid:int, sal:int);

DESCRIBE emp;

DUMP emp;

STORE emp INTO '/home/hadoop/out/emp_copy' USING PigStorage(',');
