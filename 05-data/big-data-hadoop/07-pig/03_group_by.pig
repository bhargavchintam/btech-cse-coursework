-- group by department and aggregate

emp = LOAD '/home/hadoop/data/emp.txt' USING PigStorage(',')
      AS (id:int, name:chararray, deptid:int, sal:int);

grp = GROUP emp BY deptid;

-- count, total and average salary per department
summary = FOREACH grp GENERATE group AS deptid,
                               COUNT(emp)   AS emp_count,
                               SUM(emp.sal) AS total_sal,
                               AVG(emp.sal) AS avg_sal;

DUMP summary;
