# Lab 7 - Hive Joins

## Aim
Perform inner join, left outer, right outer and full outer joins between an employee table and a department table in Hive.

## Software / Environment
- Hadoop 3.1 pseudo-distributed
- Apache Hive 2.3

## Procedure
1. Prepare the two data files.
   `employee.csv`
   ```
   1,raj,10
   2,anil,20
   3,sunil,10
   4,kiran,30
   ```
   `department.csv`
   ```
   10,cse
   20,ece
   40,mech
   ```
2. Run:
   ```
   hive -f Lab07_joins.hql
   ```

## Program
See `Lab07_joins.hql`. Creates `employee(id,name,dept_id)` and `department(dept_id,dept_name)`, loads both, and runs JOIN / LEFT OUTER / RIGHT OUTER / FULL OUTER on `dept_id`.

## Output
Inner join (only matching dept_id):
```
1   raj    cse
2   anil   ece
3   sunil  cse
```
Left outer (all employees, kiran has no matching dept so NULL):
```
raj     cse
anil    ece
sunil   cse
kiran   NULL
```
Right outer keeps `mech` (no employee) as NULL on the employee side; full outer keeps both unmatched rows.

## Result
All four Hive join types were executed and returned the expected matched and unmatched rows.
