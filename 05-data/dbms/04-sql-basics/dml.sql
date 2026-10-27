-- dml.sql - INSERT / UPDATE / DELETE on the student-course schema

DROP TABLE IF EXISTS enrollment;
DROP TABLE IF EXISTS student;
DROP TABLE IF EXISTS course;

CREATE TABLE student (
    sid    INT PRIMARY KEY,
    sname  VARCHAR(40) NOT NULL,
    email  VARCHAR(40) UNIQUE,
    gender CHAR(1),
    dob    DATE,
    cgpa   DECIMAL(4,2) DEFAULT 0.00
);

CREATE TABLE course (
    cid     CHAR(6) PRIMARY KEY,
    title   VARCHAR(40) NOT NULL,
    credits INT DEFAULT 3
);

CREATE TABLE enrollment (
    sid   INT,
    cid   CHAR(6),
    sem   VARCHAR(9),
    marks INT,
    PRIMARY KEY (sid, cid),
    FOREIGN KEY (sid) REFERENCES student(sid),
    FOREIGN KEY (cid) REFERENCES course(cid)
);

INSERT INTO student (sid, sname, email, gender, dob, cgpa) VALUES
 (1,'Ravi Kumar','ravi@reva.edu','M','1999-05-14',8.10),
 (2,'Anita Rao','anita@reva.edu','F','2000-01-22',9.05),
 (3,'Suresh Babu','suresh@reva.edu','M','1999-11-30',7.40),
 (4,'Deepa Nair','deepa@reva.edu','F','2000-07-09',8.75);

-- no cgpa given, so the DEFAULT 0.00 kicks in for this row
INSERT INTO student (sid, sname, email, gender, dob) VALUES
 (5,'Kiran Shetty','kiran@reva.edu','M','1999-03-18');

INSERT INTO course VALUES
 ('CS3010','Database Systems',4),
 ('CS3020','Operating Systems',4),
 ('CS3030','Computer Networks',3),
 ('MA3010','Discrete Maths',3);

INSERT INTO enrollment VALUES
 (1,'CS3010','2019-ODD',72),
 (1,'CS3020','2019-ODD',65),
 (2,'CS3010','2019-ODD',88),
 (2,'MA3010','2019-ODD',91),
 (3,'CS3010','2019-ODD',54),
 (4,'CS3030','2019-ODD',77);
SELECT ROW_COUNT() AS enroll_rows_inserted;

UPDATE student SET cgpa = 8.90 WHERE sid = 3;
SELECT ROW_COUNT() AS rows_updated;

UPDATE enrollment SET marks = marks + 5 WHERE cid = 'CS3010';
SELECT ROW_COUNT() AS rows_updated;

-- child rows first, then the parent, or the FK blocks the delete
DELETE FROM enrollment WHERE sid = 4;
SELECT ROW_COUNT() AS rows_deleted;

DELETE FROM student WHERE sid = 4;
SELECT ROW_COUNT() AS rows_deleted;

SELECT sid, sname, cgpa FROM student ORDER BY sid;
SELECT sid, cid, marks FROM enrollment ORDER BY sid, cid;
