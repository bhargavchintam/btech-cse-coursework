-- filter high salary rows and project selected fields

emp = LOAD '/home/hadoop/data/emp.txt' USING PigStorage(',')
      AS (id:int, name:chararray, deptid:int, sal:int);

highsal = FILTER emp BY sal > 40000;

-- project name and a computed annual salary
result = FOREACH highsal GENERATE name, sal, sal * 12 AS annual;

DUMP result;

STORE result INTO '/home/hadoop/out/highsal' USING PigStorage(',');
