-- join employee with department on deptid
-- dept.txt rows: 1,HR  (deptid,dname)

emp = LOAD '/home/hadoop/data/emp.txt' USING PigStorage(',')
      AS (id:int, name:chararray, deptid:int, sal:int);

dept = LOAD '/home/hadoop/data/dept.txt' USING PigStorage(',')
       AS (deptid:int, dname:chararray);

joined = JOIN emp BY deptid, dept BY deptid;

result = FOREACH joined GENERATE emp::name AS name,
                                emp::sal   AS sal,
                                dept::dname AS dname;

DUMP result;
