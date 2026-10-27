-- employee data analysis in pig

emp = LOAD '/user/hadoop/emp.csv' USING PigStorage(',')
      AS (id:int, name:chararray, dept:chararray, sal:int);

highpaid = FILTER emp BY sal > 7000;

grp = GROUP emp BY dept;

avgsal = FOREACH grp GENERATE group AS dept, AVG(emp.sal) AS avg_sal, COUNT(emp) AS cnt;

ordered = ORDER avgsal BY avg_sal DESC;

DUMP ordered;

STORE ordered INTO '/user/hadoop/pig_out' USING PigStorage(',');
