-- ddl.sql - build a small student/course schema, evolve it with ALTER, then DROP

DROP TABLE IF EXISTS enrollment;
DROP TABLE IF EXISTS student;
DROP TABLE IF EXISTS course;

CREATE TABLE student (
    sid    INT PRIMARY KEY,
    sname  VARCHAR(30) NOT NULL,
    email  VARCHAR(40) UNIQUE,
    gender CHAR(1),
    dob    DATE,
    cgpa   DECIMAL(4,2) DEFAULT 0.00,
    CONSTRAINT chk_cgpa CHECK (cgpa >= 0 AND cgpa <= 10)
);

CREATE TABLE course (
    cid     CHAR(6) PRIMARY KEY,
    title   VARCHAR(40) NOT NULL,
    credits INT DEFAULT 3,
    CONSTRAINT chk_credits CHECK (credits BETWEEN 1 AND 5)
);

-- enrollment is the link table; composite PK, two FKs back to the parents
CREATE TABLE enrollment (
    sid   INT,
    cid   CHAR(6),
    sem   VARCHAR(9),
    marks INT,
    PRIMARY KEY (sid, cid),
    CONSTRAINT fk_en_student FOREIGN KEY (sid) REFERENCES student(sid),
    CONSTRAINT fk_en_course  FOREIGN KEY (cid) REFERENCES course(cid),
    CONSTRAINT chk_marks CHECK (marks BETWEEN 0 AND 100)
);

ALTER TABLE student ADD phone CHAR(10);
ALTER TABLE student MODIFY sname VARCHAR(40) NOT NULL;
ALTER TABLE student ADD CONSTRAINT chk_gender CHECK (gender IN ('M','F'));
ALTER TABLE course ADD dept VARCHAR(10) DEFAULT 'CSE';
ALTER TABLE student DROP COLUMN phone;

DESCRIBE student;
DESCRIBE course;

-- DROP on a throwaway table so the three tables above are left standing
CREATE TABLE tmp_backup (sid INT, note VARCHAR(20));
DROP TABLE tmp_backup;
