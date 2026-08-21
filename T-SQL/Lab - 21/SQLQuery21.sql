-- 1. CREATE TABLE
CREATE TABLE CUSTOMER_ALL (
    ORDERID INT PRIMARY KEY,
    CNAME VARCHAR(100),
    PRODUCT VARCHAR(100),
    CATEGORY VARCHAR(100),
    AMOUNT INT,
    ORDERYEAR INT,
    CITY VARCHAR(100)
);

-- 2. INSERT VALUES
INSERT INTO CUSTOMER_ALL (ORDERID, CNAME, PRODUCT, CATEGORY, AMOUNT, ORDERYEAR, CITY) VALUES 
(101, 'RAHUL', 'LAPTOP', 'ELECTRONICS', 65000, 2024, 'RAJKOT'),
(102, 'PRIYA', 'MOBILE', 'ELECTRONICS', 25000, 2023, 'SURAT'),
(103, 'AMIT', 'TABLE', 'FURNITURE', 12000, 2022, 'AHMEDABAD'),
(104, 'NEHA', 'CHAIR', 'FURNITURE', 8000, 2024, 'BARODA'),
(105, 'VISHAL', 'TV', 'ELECTRONICS', 45000, 2025, 'MORBI'),
(106, 'RIYA', 'SOFA', 'FURNITURE', 30000, 2023, 'SURAT'),
(107, 'MEHUL', 'AC', 'ELECTRONICS', 40000, 2022, 'RAJKOT'),
(108, 'KRUNAL', 'BED', 'FURNITURE', 40000, 2025, 'JAMNAGAR');

-- 3. VERIFY DATA
SELECT * FROM CUSTOMER_ALL;

--1. Display top 3 highest amount orders. 

WITH TOP_ALL AS(
        SELECT ORDERID,AMOUNT,CNAME,
        DENSE_RANK() OVER (ORDER BY AMOUNT DESC) AS TOP_AM
        FROM CUSTOMER_ALL
    )

    SELECT * FROM TOP_ALL
    WHERE TOP_AM <= 3

--2. Display second highest order amount.

WITH TOP_AM AS(
        SELECT ORDERID,AMOUNT,CNAME,
        DENSE_RANK() OVER (ORDER BY AMOUNT DESC) AS TOP_AM1
        FROM CUSTOMER_ALL
    )

    SELECT * FROM TOP_AM
    WHERE TOP_AM1 <= 2;

--3. Display customers whose order amount is greater than category average amount. 

WITH CategoryAvg AS (
    SELECT CATEGORY, 
           AVG(AMOUNT) as AvgAmount
    FROM CUSTOMER_ALL
    GROUP BY CATEGORY
)
SELECT C.CNAME, C.CATEGORY, C.AMOUNT, A.AvgAmount
FROM CUSTOMER_ALL C
JOIN CategoryAvg A 
ON C.CATEGORY = A.CATEGORY
WHERE C.AMOUNT > A.AvgAmount;

--4. Display categories having average amount greater than 30000. 

WITH GroupedCategory AS (
    SELECT CATEGORY, 
           AVG(AMOUNT) as AvgAmount
    FROM CUSTOMER_ALL
    GROUP BY CATEGORY
)
SELECT CATEGORY, AvgAmount
FROM GroupedCategory
WHERE AvgAmount > 30000;

--5. Display highest amount order from each category.

WITH RankedCategory AS (
    SELECT *,
           ROW_NUMBER() OVER (PARTITION BY CATEGORY ORDER BY AMOUNT DESC) as MaxRank
    FROM CUSTOMER_ALL
)
SELECT ORDERID, CNAME, PRODUCT, CATEGORY, AMOUNT, ORDERYEAR, CITY
FROM RankedCategory
WHERE MaxRank = 1;

--6. Display lowest amount order from each category. 

WITH RankedCategory AS (
    SELECT *,
           ROW_NUMBER() OVER (PARTITION BY CATEGORY ORDER BY AMOUNT ASC) as MinRank
    FROM CUSTOMER_ALL
)
SELECT ORDERID, CNAME, PRODUCT, CATEGORY, AMOUNT, ORDERYEAR, CITY
FROM RankedCategory
WHERE MinRank = 1;

--7. Display categories having more than 3 orders.

WITH OrderCounts AS (
    SELECT CATEGORY, 
           COUNT(ORDERID) as TotalOrders
    FROM CUSTOMER_ALL
    GROUP BY CATEGORY
)
SELECT CATEGORY, TotalOrders
FROM OrderCounts
WHERE TotalOrders > 3;

--8. Display city-wise total order amount. 

WITH CityTotals AS (
    SELECT CITY, 
           SUM(AMOUNT) as TotalAmount
    FROM CUSTOMER_ALL
    GROUP BY CITY
)
SELECT CITY, TotalAmount
FROM CityTotals;


--9. Display category having highest average order amount.

WITH TopCategory AS (
    SELECT CATEGORY, 
           AVG(AMOUNT) as AvgAmount,
           ROW_NUMBER() OVER (ORDER BY AVG(AMOUNT) DESC) as AvgRank
    FROM CUSTOMER_ALL
    GROUP BY CATEGORY
)
SELECT CATEGORY, AvgAmount
FROM TopCategory
WHERE AvgRank = 1;

--10. Display cumulative order amount in ascending order of amount.

WITH CumulativeData AS (
    SELECT ORDERID, CNAME, AMOUNT,
           SUM(AMOUNT) OVER (ORDER BY AMOUNT ASC ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) as CumulativeAmount
    FROM CUSTOMER_ALL
)
SELECT ORDERID, CNAME, AMOUNT, CumulativeAmount
FROM CumulativeData;

--11. Display category-wise top 2 highest amount orders.

WITH RANK_CAT AS (
    SELECT *,
    ROW_NUMBER() OVER (PARTITION BY CATEGORY ORDER BY AMOUNT DESC) as M_RANK
    FROM CUSTOMER_ALL
)
SELECT ORDERID, CNAME, PRODUCT, CATEGORY, AMOUNT, ORDERYEAR, CITY, M_RANK
FROM RANK_CAT
WHERE M_RANK <= 2;

--12. Display customers whose amount is closest to category average amount. 

WITH AVG_AMT AS (
    SELECT CATEGORY, AVG(AMOUNT) AS AVG_AMOUNT
    FROM CUSTOMER_ALL
    GROUP BY CATEGORY
),
DIFFS AS (
    SELECT C.CNAME, C.CATEGORY, C.AMOUNT,
    ABS(C.AMOUNT - A.AVG_AMOUNT) AS DIFF
    FROM CUSTOMER_ALL C
    JOIN AVG_AMT A
    ON C.CATEGORY = A.CATEGORY
)
SELECT D.CNAME, D.CATEGORY, D.AMOUNT
FROM DIFFS D
WHERE D.DIFF = (
    SELECT MIN(D2.DIFF)
    FROM DIFFS D2
    WHERE D2.CATEGORY = D.CATEGORY
);

--13. Display previous, current and next order amount together. 

WITH ORDER_SEQ AS (
    SELECT ORDERID, AMOUNT,
    LAG(AMOUNT) OVER (ORDER BY ORDERID) AS PREV_AMOUNT,
    AMOUNT AS CURR_AMOUNT,
    LEAD(AMOUNT) OVER (ORDER BY ORDERID) AS NEXT_AMOUNT
    FROM CUSTOMER_ALL
)
SELECT ORDERID, PREV_AMOUNT, CURR_AMOUNT, NEXT_AMOUNT
FROM ORDER_SEQ;

--14. Display customers whose amount is greater than previous customer's amount. 

WITH ORDER_DIFF AS (
    SELECT ORDERID, CNAME, AMOUNT,
    LAG(AMOUNT) OVER (ORDER BY ORDERID) AS PREV_AMOUNT
    FROM CUSTOMER_ALL
)
SELECT ORDERID, CNAME, AMOUNT
FROM ORDER_DIFF
WHERE AMOUNT > PREV_AMOUNT;

--15. Display customers whose rank and dense rank are different.

 WITH RANKS AS (
    SELECT ORDERID, CNAME, AMOUNT,
    RANK() OVER (ORDER BY AMOUNT DESC) AS RANKS,
    DENSE_RANK() OVER (ORDER BY AMOUNT DESC) AS DENSE_RANKS
    FROM CUSTOMER_ALL
)
SELECT ORDERID, CNAME, AMOUNT, RANKS, DENSE_RANKS
FROM RANKS
WHERE RANKS <> DENSE_RANKS;

--16. Display orders whose amount is neither highest nor lowest in their category. 

WITH CAT_AMT AS (
    SELECT ORDERID, CNAME, CATEGORY, AMOUNT,
    MAX(AMOUNT) OVER (PARTITION BY CATEGORY) AS MAX_AMT,
    MIN(AMOUNT) OVER (PARTITION BY CATEGORY) AS MIN_AMT
    FROM CUSTOMER_ALL
)
SELECT ORDERID, CNAME, CATEGORY, AMOUNT
FROM CAT_AMT
WHERE AMOUNT NOT IN (MAX_AMT, MIN_AMT);

--17. Display category-wise difference between highest and lowest amount.

WITH CAT_RANGE AS (
    SELECT CATEGORY,
    MAX(AMOUNT) AS MAX_AMT,
    MIN(AMOUNT) AS MIN_AMT
    FROM CUSTOMER_ALL
    GROUP BY CATEGORY
)
SELECT CATEGORY, (MAX_AMT - MIN_AMT) AS DIFF
FROM CAT_RANGE;

--18. Display customers whose amount is greater than all FURNITURE category orders. 

WITH FURN_AMT AS (
    SELECT MAX(AMOUNT) AS MAX_FURN
    FROM CUSTOMER_ALL
    WHERE CATEGORY = 'FURNITURE'
)
SELECT CNAME, CATEGORY, AMOUNT
FROM CUSTOMER_ALL C, FURN_AMT F
WHERE C.AMOUNT > F.MAX_FURN;

--19. Display categories where all orders are above 10000. 

WITH CAT_MIN AS (
    SELECT CATEGORY, MIN(AMOUNT) AS MIN_AMT
    FROM CUSTOMER_ALL
    GROUP BY CATEGORY
)
SELECT CATEGORY
FROM CAT_MIN
WHERE MIN_AMT > 10000;

--20. Display customers whose amount difference from category topper is minimum.

WITH CAT_TOP AS (
    SELECT CATEGORY, MAX(AMOUNT) AS TOP_AMT
    FROM CUSTOMER_ALL
    GROUP BY CATEGORY
),
DIFFS AS (
    SELECT C.CNAME, C.CATEGORY, C.AMOUNT,
    (CAT.TOP_AMT - C.AMOUNT) AS DIFF
    FROM CUSTOMER_ALL C
    JOIN CAT_TOP CAT
    ON C.CATEGORY = CAT.CATEGORY
)
SELECT CNAME, CATEGORY, AMOUNT, DIFF
FROM DIFFS D
WHERE DIFF = (
    SELECT MIN(D2.DIFF)
    FROM DIFFS D2
    WHERE D2.CATEGORY = D.CATEGORY
);