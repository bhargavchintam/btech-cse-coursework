-- order by salary and take the top 5

emp = LOAD '/home/hadoop/data/emp.txt' USING PigStorage(',')
      AS (id:int, name:chararray, deptid:int, sal:int);

sorted = ORDER emp BY sal DESC;

top5 = LIMIT sorted 5;

DUMP top5;
