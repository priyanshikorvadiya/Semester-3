
--Retrieve all data from table STUDENT. 

SELECT * FROM STUDENT

--Display Student Name and City from STUDENT.

SELECT SNAME , CITY FROM STUDENT;

--Display student details of all students who belongs to COMPUTER branch.

SELECT SNAME FROM STUDENT 
WHERE BRANCH = 'COMPUTER'

--Display names of students whose ID is less than 105 from STUDENT table. 

SELECT SNAME FROM STUDENT
WHERE STDID < 105

--Give Student Name, City and SPI of student whose SPI is greater than 6.50. 

SELECT SNAME,CITY,SPI FROM STUDENT
WHERE SPI > 6.50

--Give name of Student whose branch is COMPUTER and SPI is greater than 8.00. 

SELECT SNAME FROM STUDENT
WHERE BRANCH = 'COMPUTER' AND SPI > 8.00

--Give names of students whose ID is greater than 103 and belongs to Rajkot city.

SELECT SNAME FROM STUDENT
WHERE STDID > 103 AND CITY = 'RAJKOT'

--Display names of students who belong to either ‘RAJKOT’ or ‘SURAT’ city (USE OR & IN). 

SELECT SNAME FROM STUDENT
WHERE CITY = 'RAJKOT' OR CITY = 'SURAT'

--Display names of students with branch whose SPI is greater than 8.0 and ID is less than 105.

SELECT SNAME,BRANCH FROM STUDENT 
WHERE SPI > 8.0 AND STDID < 105

--Find all students whose SPI is greater than or equal to 7.0 and less than or equal to 9.0 (USE AND & 
--BETWEEN). 

SELECT * FROM STUDENT
WHERE SPI BETWEEN 7.0 AND 9.0

--Find all students who do not belong to ‘COMPUTER’ branch. 

SELECT * FROM STUDENT
WHERE BRANCH != 'COMPUTER'

--Display Student ID, Name & SPI of students who belong to ‘COMPUTER’, ‘CIVIL’ or ‘CHEMICAL’ branch 
--and ID is less than 104. 

SELECT STDID,SNAME,SPI FROM STUDENT
WHERE STDID < 104 AND BRANCH IN ('COMPUTER' , 'CIVIL' , 'CHEMICAL') 

--Display all student IDs and names who do not belong to ‘COMPUTER’ or ‘CIVIL’ branch (USE NOT IN).

SELECT * FROM STUDENT
WHERE BRANCH NOT IN ('COMPUTER','CIVIL')

--Display all student names other than ‘DEEP’ from STUDENT table (USE NOT, <>, !=).

SELECT * FROM STUDENT
WHERE SNAME != 'DEEP'

SELECT * FROM STUDENT
WHERE SNAME <> 'DEEP'

SELECT * FROM STUDENT
WHERE NOT SNAME = 'DEEP'

--Display student names whose branch is not available (NULL) in STUDENT table. 

SELECT * FROM STUDENT
WHERE BRANCH IS NULL

--Retrieve all unique branches name from STUDENT table. 

SELECT DISTINCT BRANCH FROM STUDENT

--Retrieve first 50% records from STUDENT table. 

SELECT TOP 50 PERCENT * FROM STUDENT

--Retrieve first five student IDs from STUDENT table.

SELECT TOP 5 STDID FROM STUDENT

--Display all the details of first five students from STUDENT table. 

SELECT TOP 5 * FROM STUDENT

--Display all the details of first three students whose SPI is greater than 8.0. 

SELECT TOP 3 * FROM STUDENT
WHERE SPI > 8.0

--Display Student ID, Name of first five students whose branch does not belong to ‘COMPUTER’ branch.

SELECT TOP 5 STDID,SNAME FROM STUDENT
WHERE BRANCH != 'COMPUTER'

--Select all details with student IDs not in the range 105 to 109. 

SELECT * FROM STUDENT
WHERE NOT STDID BETWEEN 105 AND 109

--Select all records from STUDENT where SPI is greater than 7.0 and less than or equal to 9.0, and student 
--ID is between 102 and 108. 

SELECT * FROM STUDENT
WHERE SPI > 7.0 AND SPI <= 9.0 AND STDID BETWEEN 102 AND 108

--Display all details of students who have SPI more than 8.5 without using * from STUDENT table.

SELECT STDID,SNAME,CITY,SPI,BRANCH FROM STUDENT 
WHERE SPI > 8.5

--Retrieve names of students whose city is ‘RAJKOT’ and SPI is less than 8.00.

SELECT SNAME FROM STUDENT
WHERE CITY = 'RAJKOT' AND SPI < 8.00

--Retrieve records from STUDENT table where SPI is greater than 8.0 and student ID is less than 105.

SELECT * FROM STUDENT 
WHERE STDID < 105 AND SPI > 8.0

--Retrieve records from STUDENT table where SPI is greater than 7.5 and student ID is between 100 and 
--110 and city is ‘RAJKOT’ or ‘SURAT’.

SELECT * FROM STUDENT
WHERE STDID BETWEEN 100 AND 110 AND SPI > 7.5 AND CITY IN ('RAJKOT' , 'SURAT')

--Display details of students who belong to ‘CIVIL’ or ‘MECHANICAL’ branch and SPI is greater than 8.0.

SELECT * FROM STUDENT
WHERE BRANCH IN ('CIVIL' , 'MECHANICAL') AND SPI > 8.0

-- EXTRA

--1. Display all students whose city is ‘RAJKOT’ and branch is ‘COMPUTER’.

SELECT * FROM STUDENT 
WHERE CITY = 'RAJKOT' AND BRANCH = 'COMPUTER'

--2. Retrieve names and SPI of students whose SPI is less than 7.00.

SELECT SNAME,SPI FROM STUDENT
WHERE SPI < 7.00

--3. Display all details of students whose ID is between 103 and 107.

SELECT * FROM STUDENT
WHERE STDID BETWEEN 103 AND 107

--4. Retrieve Student ID, Name, and Branch of students whose branch is ‘MECHANICAL’.

SELECT STDID,SNAME,BRANCH FROM STUDENT
WHERE BRANCH = 'MECHANICAL'

--5. Display all records where the city is not ‘SURAT’.

SELECT * FROM STUDENT
WHERE CITY <> 'SURAT'

--6. Display names of students whose branch is either ‘ELECTRICAL’ or ‘MECHANICAL’.

SELECT SNAME FROM STUDENT
WHERE BRANCH IN ('ELECTRICAL','MECHANICAL')

--7. Retrieve all students whose SPI is not between 6.0 and 8.0.

SELECT * FROM STUDENT
WHERE SPI NOT BETWEEN 6.0 AND 8.0

--8. Display details of students whose city is NULL.

SELECT * FROM STUDENT
WHERE CITY IS NULL

--9. Display all students whose SPI is greater than 8.0 and who do not belong to either COMPUTER or
--CIVIL branch.

SELECT * FROM STUDENT
WHERE SPI > 8.0 AND BRANCH NOT IN ('COMPUTER','CIVIL')

--10. Display all students whose branch is NULL and whose city is not NULL.

SELECT * FROM STUDENT
WHERE BRANCH IS NULL AND CITY IS NOT NULL

--11. Retrieve students whose SPI is greater than 7.5 and less than 9.0 but whose IDs are not between
--104 and 108.

SELECT * FROM STUDENT 
WHERE SPI > 7.5 AND SPI < 9.0 AND STDID NOT BETWEEN 104 AND 108

--12. Retrieve all records where the city is RAJKOT and the branch is not COMPUTER.

SELECT * FROM STUDENT 
WHERE CITY = 'RAJKOT' AND BRANCH = 'COMPUTER'

--13. Display students whose IDs are not between 102 and 107 and whose SPI is greater than 7.5.

SELECT * FROM STUDENT 
WHERE STDID NOT BETWEEN 102 AND 107 AND SPI > 7.5

--14. Retrieve students whose SPI is between 7.0 and 8.5 and who belong to COMPUTER, CIVIL, or
--MECHANICAL branches.

SELECT * FROM STUDENT
WHERE SPI BETWEEN 7.0 AND 8.5 AND BRANCH IN ('COMPUTER','CIVIL','MECHANICAL')

--15. Display records where the branch is COMPUTER and city is not RAJKOT and SPI is greater than
--7.0.

SELECT * FROM STUDENT
WHERE BRANCH = 'COMPUTER' AND CITY != 'RAJKOT' AND SPI > 7.0
