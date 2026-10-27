-- Library Management System - sample data (2019 session)

INSERT INTO publishers VALUES
 (1,'Penguin India','GURGAON','0124-4785600'),
 (2,'Rupa Publications','NEW DELHI','011-23278000'),
 (3,'Oxford University Press','NEW DELHI','011-45364356'),
 (4,'McGraw Hill Education','CHENNAI','044-45077700'),
 (5,'S. Chand Publishing','NEW DELHI','011-66672000');

INSERT INTO authors VALUES
 (1,'Chetan Bhagat','India'),
 (2,'R.K. Narayan','India'),
 (3,'Anita Desai','India'),
 (4,'Arundhati Roy','India'),
 (5,'Ruskin Bond','India'),
 (6,'A.P.J. Abdul Kalam','India'),
 (7,'E. Balagurusamy','India'),
 (8,'Herbert Schildt','USA'),
 (9,'Ramez Elmasri','USA'),
 (10,'Shamkant Navathe','USA'),
 (11,'Henry F. Korth','USA'),
 (12,'Yashavant Kanetkar','India');

INSERT INTO categories VALUES
 (1,'Fiction'),
 (2,'Computer Science'),
 (3,'Biography'),
 (4,'Children'),
 (5,'Science');

INSERT INTO books VALUES
 (1 ,'Five Point Someone'              ,'9788129135728',1,2,2004,176.00),
 (2 ,'The 3 Mistakes of My Life'       ,'9788129135513',1,2,2008,140.00),
 (3 ,'Malgudi Days'                    ,'9780143039655',1,1,1943,299.00),
 (4 ,'The Guide'                       ,'9780143039624',1,1,1958,250.00),
 (5 ,'The God of Small Things'         ,'9780679457312',1,1,1997,399.00),
 (6 ,'Fasting, Feasting'              ,'9780099283355',1,3,1999,350.00),
 (7 ,'The Blue Umbrella'              ,'9788170461964',4,1,1974,150.00),
 (8 ,'Wings of Fire'                  ,'9788173711466',3,3,1999,275.00),
 (9 ,'Programming in ANSI C'          ,'9789351343202',2,4,2017,450.00),
 (10,'Java: The Complete Reference'   ,'9789387432291',2,4,2018,720.00),
 (11,'Fundamentals of Database Systems','9789332582705',2,3,2016,825.00),
 (12,'Database System Concepts'       ,'9789332901384',2,4,2019,899.00),
 (13,'Let Us C'                       ,'9788183331630',2,5,2016,375.00),
 (14,'The English Teacher'            ,'9780226568355',1,1,1945,275.00),
 (15,'Ignited Minds'                  ,'9780143424123',3,1,2002,199.00);

INSERT INTO book_authors VALUES
 (1,1),(2,1),(3,2),(4,2),(5,4),(6,3),(7,5),(8,6),
 (9,7),(10,8),(11,9),(11,10),(12,11),(13,12),(14,2),(15,6);

INSERT INTO book_copies VALUES
 (101,1 ,'2019-06-01','available'),
 (102,1 ,'2019-06-01','issued'),
 (103,1 ,'2019-06-01','available'),
 (104,2 ,'2019-06-05','available'),
 (105,2 ,'2019-06-05','available'),
 (106,3 ,'2019-06-10','available'),
 (107,3 ,'2019-06-10','available'),
 (108,4 ,'2019-06-10','available'),
 (109,5 ,'2019-06-15','issued'),
 (110,5 ,'2019-06-15','available'),
 (111,6 ,'2019-06-20','available'),
 (112,7 ,'2019-06-20','available'),
 (113,7 ,'2019-06-20','available'),
 (114,8 ,'2019-07-01','available'),
 (115,8 ,'2019-07-01','available'),
 (116,8 ,'2019-07-01','lost'),
 (117,9 ,'2019-07-05','available'),
 (118,9 ,'2019-07-05','issued'),
 (119,9 ,'2019-07-05','available'),
 (120,10,'2019-07-10','available'),
 (121,10,'2019-07-10','available'),
 (122,11,'2019-07-15','available'),
 (123,11,'2019-07-15','available'),
 (124,12,'2019-07-20','issued'),
 (125,12,'2019-07-20','available'),
 (126,13,'2019-08-01','available'),
 (127,13,'2019-08-01','available'),
 (128,13,'2019-08-01','available'),
 (129,14,'2019-08-05','available'),
 (130,15,'2019-08-10','issued'),
 (131,15,'2019-08-10','available');

INSERT INTO members VALUES
 (1,'Ravi Kumar'    ,'ravi.kumar@gmail.com'      ,'9880012345','BANGALORE','2019-06-15','student'),
 (2,'Anita Sharma'  ,'anita.sharma@gmail.com'    ,'9845023456','MYSORE'   ,'2019-06-20','faculty'),
 (3,'Suresh Babu'   ,'suresh.babu@yahoo.com'     ,'9900034567','HYDERABAD','2019-07-01','public'),
 (4,'Priya Nair'    ,'priya.nair@gmail.com'      ,'9741045678','BANGALORE','2019-07-05','student'),
 (5,'Kiran Rao'     ,'kiran.rao@gmail.com'       ,'9886056789','MYSORE'   ,'2019-07-10','student'),
 (6,'Deepa Menon'   ,'deepa.menon@gmail.com'     ,'9448067890','BANGALORE','2019-07-15','faculty'),
 (7,'Manoj Gowda'   ,'manoj.gowda@rediffmail.com','9964078901','HYDERABAD','2019-08-01','public'),
 (8,'Lakshmi Reddy' ,'lakshmi.reddy@gmail.com'   ,'9535089012','BANGALORE','2019-08-05','student');

INSERT INTO staff VALUES
 (1,'Ramesh Iyer','Librarian'          ,'ramesh.iyer@reva.edu.in','2018-01-10'),
 (2,'Sunita Rao' ,'Assistant Librarian','sunita.rao@reva.edu.in' ,'2018-06-15'),
 (3,'Vijay Kumar','Library Clerk'      ,'vijay.kumar@reva.edu.in','2019-01-20');

INSERT INTO loans VALUES
 (1 ,101,1,1,'2019-07-01','2019-07-15','2019-07-10'),
 (2 ,104,2,1,'2019-07-05','2019-07-19','2019-07-25'),
 (3 ,106,3,2,'2019-08-01','2019-08-15','2019-08-14'),
 (4 ,114,4,1,'2019-08-10','2019-08-24','2019-09-05'),
 (5 ,117,5,3,'2019-08-20','2019-09-03','2019-09-03'),
 (6 ,120,6,2,'2019-09-01','2019-09-15','2019-09-30'),
 (7 ,122,1,1,'2019-09-10','2019-09-24','2019-09-20'),
 (8 ,126,7,1,'2019-09-15','2019-09-29','2019-10-10'),
 (9 ,109,8,2,'2019-12-20','2020-01-03',NULL),
 (10,118,2,1,'2019-12-28','2020-01-11',NULL),
 (11,130,3,3,'2020-01-05','2020-01-19',NULL),
 (12,124,4,1,'2020-01-20','2020-02-03',NULL),
 (13,102,5,2,'2020-01-25','2020-02-08',NULL),
 (14,112,6,1,'2019-11-01','2019-11-15','2019-11-12'),
 (15,127,8,1,'2019-11-05','2019-11-19','2019-12-19');

INSERT INTO fines VALUES
 (1,2 ,12.00,'Y','2019-07-25'),
 (2,4 ,24.00,'N',NULL),
 (3,6 ,30.00,'Y','2019-10-01'),
 (4,8 ,22.00,'N',NULL),
 (5,15,60.00,'N',NULL);
