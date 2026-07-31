
--1. List all books with their authors. 

SELECT * FROM BOOK
SELECT * FROM AUTHOR
SELECT * FROM PUBLISHER

SELECT TITLE,AUTHORNAME FROM BOOK B
JOIN AUTHOR A
ON B.AUTHORID = A.AUTHORID
JOIN PUBLISHER P
ON B.PUBLISHERID = P.PUBLISHERID

--2. List all books with their publishers.

SELECT TITLE,PUBLISHERNAME FROM BOOK B
JOIN AUTHOR A
ON B.AUTHORID = A.AUTHORID
JOIN PUBLISHER P
ON B.PUBLISHERID = P.PUBLISHERID

--3. List all books with their authors and publishers. 

SELECT TITLE,AUTHORNAME,PUBLISHERNAME FROM BOOK B
JOIN AUTHOR A
ON B.AUTHORID = A.AUTHORID
JOIN PUBLISHER P
ON B.PUBLISHERID = P.PUBLISHERID

--4. List all books published after 2010 with their authors and publisher and price.

SELECT TITLE,AUTHORNAME,PUBLISHERNAME,PRICE,PUBLICATIONYEAR FROM BOOK B
JOIN AUTHOR A
ON B.AUTHORID = A.AUTHORID
JOIN PUBLISHER P
ON B.PUBLISHERID = P.PUBLISHERID
WHERE PUBLICATIONYEAR > 2010

--5. List all authors and the number of books they have written. 

SELECT AUTHORNAME,COUNT(A.AUTHORID) AS NOOFBOOK FROM BOOK B
JOIN AUTHOR A
ON B.AUTHORID = A.AUTHORID
GROUP BY AUTHORNAME

--6. List all publishers and the total price of books they have published.

SELECT PUBLISHERNAME,SUM(PRICE) AS PRICEOFBOOK FROM BOOK B
JOIN AUTHOR A
ON B.AUTHORID = A.AUTHORID
JOIN PUBLISHER P
ON B.PUBLISHERID = P.PUBLISHERID
GROUP BY PUBLISHERNAME

--7. List authors who have not written any books. 

SELECT * FROM AUTHOR A
LEFT JOIN BOOK B
ON B.AUTHORID = A.AUTHORID
WHERE BOOKID IS NULL

--8. Display the total number of books written by each author along with the average price of their books. 

SELECT AUTHORNAME,COUNT(A.AUTHORID) AS NOOFBOOKS,AVG(PRICE) AS AVGPRICEOFBOOK FROM BOOK B
JOIN AUTHOR A
ON B.AUTHORID = A.AUTHORID
GROUP BY AUTHORNAME

--9. lists each publisher along with the total number of books they have published, sorted from highest to 
--lowest.

SELECT PUBLISHERNAME,COUNT(B.PUBLISHERID) FROM PUBLISHER P
JOIN BOOK B
ON B.PUBLISHERID = P.PUBLISHERID
GROUP BY PUBLISHERNAME
ORDER BY COUNT(B.PUBLISHERID) DESC

--10. Display number of books published each year.

SELECT PUBLICATIONYEAR,COUNT(B.BOOKID) AS NOOFBOOKS FROM BOOK B
GROUP BY PUBLICATIONYEAR

--11. List the publishers whose total book prices exceed 500, ordered by the total price.

SELECT SUM(PRICE) AS TOTALPRICE,PUBLISHERNAME FROM BOOK B
JOIN PUBLISHER P
ON B.PUBLISHERID = P.PUBLISHERID
GROUP BY PUBLISHERNAME
HAVING SUM(PRICE) > 500
ORDER BY SUM(PRICE)

--12. List most expensive book for each author, sort it with the highest price.

SELECT MAX(PRICE) AS MAXPRICE,A.AUTHORNAME FROM BOOK B
JOIN AUTHOR A
ON B.PUBLISHERID = A.AUTHORID
GROUP BY AUTHORNAME
ORDER BY MAX(PRICE) DESC

--13. Display publisher name and difference between maximum and minimum book price. 

SELECT MAX(PRICE) - MIN(PRICE) AS DIFF,PUBLISHERNAME FROM BOOK B
JOIN PUBLISHER P
ON B.PUBLISHERID = P.PUBLISHERID
GROUP BY PUBLISHERNAME

--14. List publisher name and total price of books published each year. 

SELECT SUM(PRICE) AS TOTALPRICE,PUBLICATIONYEAR FROM BOOK B
JOIN PUBLISHER P
ON B.PUBLISHERID = P.PUBLISHERID
GROUP BY PUBLICATIONYEAR

--15. Display author name and total price of books sorted by highest total price.

SELECT SUM(PRICE) AS TOTALPRICE,AUTHORNAME FROM BOOK B
JOIN AUTHOR A
ON B.AUTHORID = A.AUTHORID
GROUP BY AUTHORNAME
ORDER BY SUM(PRICE) DESC

--------------------------------------------------------------------------------
CREATE TABLE EMPLOYEE_MASTER (
    EmployeeNo VARCHAR(10) PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    ManagerNo VARCHAR(10)
);


INSERT INTO EMPLOYEE_MASTER (EmployeeNo, Name, ManagerNo) VALUES
('E01', 'Tarun', NULL),
('E02', 'Rohan', 'E03'),
('E03', 'Priya', 'E02'),
('E04', 'Milan', 'E01'),
('E05', 'Jay', 'E03'),
('E06', 'Anjana', 'E04');

SELECT * FROM EMPLOYEE
SELECT * FROM  EMPLOYEE_MASTER

-----------------------------------------------------------------------------------

--16. Retrieve the names of employee along with their manager’s name from the Employee table. 

SELECT E1.NAME,E2.NAME AS MANAGER
FROM EMPLOYEE_MASTER E1
INNER JOIN EMPLOYEE_MASTER E2
ON E1.ManagerNo = E2.EmployeeNo

--17. Display employees who are managers.

SELECT E2.NAME AS MANAGER
FROM EMPLOYEE_MASTER E1
INNER JOIN EMPLOYEE_MASTER E2
ON E1.EmployeeNo = E2.ManagerNo

--18. Display number of employees working under each manager.

SELECT ManagerNo,COUNT(*) AS EMPCOUNT
FROM EMPLOYEE_MASTER
WHERE ManagerNo IS NOT NULL
GROUP BY ManagerNo

--19. Display the employee’s name along with their manager’s name and senior manager name. 

SELECT E.NAME AS EMP,M.NAME AS MAN,SM.NAME AS SMAN
FROM EMPLOYEE_MASTER E
JOIN EMPLOYEE_MASTER M
ON E.ManagerNo = M.ManagerNo
LEFT JOIN EMPLOYEE_MASTER SM
ON M.ManagerNo = SM.ManagerNo

--20. Display managers and count of employees under them in descending order. 

SELECT E2.NAME AS MANAGER,COUNT(E1.EmployeeNo) AS EMPCOUNT FROM EMPLOYEE_MASTER E2
JOIN EMPLOYEE_MASTER E1
ON E1.ManagerNo = E2.EmployeeNo
GROUP BY E2.NAME
ORDER BY EMPCOUNT DESC