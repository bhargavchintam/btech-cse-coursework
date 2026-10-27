-- create and use the database for the employee lab

CREATE DATABASE IF NOT EXISTS companydb
COMMENT 'employee and department data'
WITH DBPROPERTIES ('creator' = 'bhargav');

SHOW DATABASES;

USE companydb;

DESCRIBE DATABASE companydb;

-- drop when not needed (cascade removes all tables too)
-- DROP DATABASE IF EXISTS companydb CASCADE;
