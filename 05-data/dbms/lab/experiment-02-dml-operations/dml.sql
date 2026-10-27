-- dml.sql - INSERT / UPDATE / DELETE on emp/dept, with before/after checks.
-- load emp_dept.sql first, then run this file.

SELECT ename, sal FROM emp WHERE job = 'CLERK' ORDER BY empno;

UPDATE emp SET sal = sal * 1.10 WHERE job = 'CLERK';

SELECT ename, sal FROM emp WHERE job = 'CLERK' ORDER BY empno;

SELECT ename, comm FROM emp WHERE ename = 'MARTIN';

UPDATE emp SET comm = comm + 1000 WHERE ename = 'MARTIN';

SELECT ename, comm FROM emp WHERE ename = 'MARTIN';

SELECT empno, ename, job, sal, deptno FROM emp WHERE deptno = 40;

INSERT INTO emp VALUES
 (7950,'RAGHU','CLERK',7782,'2020-02-10',12000,NULL,40),
 (7951,'DEEPA','SALESMAN',7698,'2020-02-15',14000,2000,40);

SELECT empno, ename, job, sal, deptno FROM emp WHERE deptno = 40;

SELECT COUNT(*) AS emp_count FROM emp;

DELETE FROM emp WHERE deptno = 40;

SELECT COUNT(*) AS emp_count FROM emp;
