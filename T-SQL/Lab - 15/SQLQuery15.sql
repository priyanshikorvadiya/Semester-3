
--1. Display players who belong to teams located in ‘Mumbai’. 

SELECT PLAYER_FIRST_NAME,Stadium_city
FROM STADIUM S JOIN TEAM T
ON S.Stadium_id=T.HOME_STADIUM_ID
JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
WHERE Stadium_city='Mumbai'

--2. Display all teams and players.

SELECT PLAYER_FIRST_NAME,TEAM_NAME
FROM TEAM T JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID

--3. Display players along with team wins and stadium city.

SELECT PLAYER_FIRST_NAME,Stadium_city,TEAM_WINS
FROM STADIUM S JOIN TEAM T
ON S.Stadium_id=T.HOME_STADIUM_ID
JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID

--4. Display team name and number of players in each team.

SELECT TEAM_NAME,COUNT(PLAYER_ID)
FROM TEAM T JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
GROUP BY TEAM_NAME

--5. Display team name, coach, and number of bowlers in each team. 

SELECT TEAM_NAME,TEAM_COACH,COUNT(PLAYER_ID)
FROM TEAM T JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
WHERE PLAYER_ROLE='bowler'
GROUP BY TEAM_NAME,TEAM_COACH

--6. Display team name with count of batsmen, bowlers, and all-rounders. 

SELECT TEAM_NAME,
COUNT(CASE WHEN PLAYER_ROLE='BATSMEN' THEN 1 ELSE NULL END) AS COUNT_BATSMEN,
COUNT(CASE WHEN PLAYER_ROLE='bowler' THEN 1 ELSE NULL END) AS COUNT_bowlers,
COUNT(CASE WHEN PLAYER_ROLE='all-rounder' THEN 1 ELSE NULL END) AS [COUNT_all-rounders]
FROM TEAM T JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
GROUP BY TEAM_NAME

--7. Display stadiums where teams have won more than 10 matches.

SELECT STADIUM_NAME,TEAM_WINS
FROM STADIUM S JOIN TEAM T
ON S.Stadium_id=T.HOME_STADIUM_ID
WHERE TEAM_WINS>10

--8. Display team name and number of players whose matches played is greater than 25.

SELECT TEAM_NAME,COUNT(PLAYER_ID)
FROM TEAM T JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
WHERE PLAYER_MATCHES_PLAYED>25
GROUP BY TEAM_NAME

--9. Display team name and total number of players having jersey number greater than 30.

SELECT TEAM_NAME,COUNT(PLAYER_ID)
FROM TEAM T JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
WHERE PLAYER_JERSEY_NUMBER>30
GROUP BY TEAM_NAME

--10. Display team name and total matches played by its players.

SELECT TEAM_NAME,PLAYER_MATCHES_PLAYED
FROM TEAM T JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID

--11. Display stadium city and total number of teams in each city.

SELECT Stadium_city,COUNT(TEAM_NAME)
FROM STADIUM S JOIN TEAM T
ON S.Stadium_id=T.HOME_STADIUM_ID
GROUP BY Stadium_city

--12. Display team name and average matches played by players in each team. 

SELECT TEAM_NAME,AVG(PLAYER_MATCHES_PLAYED)
FROM TEAM T JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
GROUP BY TEAM_NAME

--13. Display team name and maximum matches played by any player in each team.

SELECT TEAM_NAME,MAX(PLAYER_MATCHES_PLAYED)
FROM TEAM T JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
GROUP BY TEAM_NAME

--14. Display team name and minimum matches played by any player in each team. 

SELECT TEAM_NAME,MIN(PLAYER_MATCHES_PLAYED)
FROM TEAM T JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
GROUP BY TEAM_NAME

--15. Display stadium name and total number of players playing under teams of that stadium.

SELECT S.STADIUM_NAME,COUNT(PLAYER_ID)
FROM STADIUM S JOIN TEAM T
ON S.Stadium_id=T.HOME_STADIUM_ID
JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
GROUP BY STADIUM_NAME

SELECT * FROM  STADIUM

--16. Display teams having more all-rounders than bowlers.

SELECT TEAM_NAME,
COUNT(CASE WHEN PLAYER_ROLE='all-rounder' THEN 1 ELSE NULL END) AS [COUNT_all-rounders],
COUNT(CASE WHEN PLAYER_ROLE='bowler' THEN 1 ELSE NULL END) AS COUNT_bowlers
FROM TEAM T JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
GROUP BY TEAM_NAME
HAVING COUNT(CASE WHEN PLAYER_ROLE='all-rounder' THEN 1 ELSE NULL END)>
COUNT(CASE WHEN PLAYER_ROLE='bowler' THEN 1 ELSE NULL END)

--17. Display teams where difference between max and min player matches is greater than 5.

SELECT TEAM_NAME,MAX(PLAYER_MATCHES_PLAYED)-MIN(PLAYER_MATCHES_PLAYED)
FROM TEAM T JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
GROUP BY TEAM_NAME
HAVING MAX(PLAYER_MATCHES_PLAYED)-MIN(PLAYER_MATCHES_PLAYED)>5

--18. Display stadium city and total wins of teams in that city.\

SELECT Stadium_city,COUNT(PLAYER_MATCHES_PLAYED)
FROM STADIUM S JOIN TEAM T
ON S.Stadium_id=T.HOME_STADIUM_ID
JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
GROUP BY Stadium_city

--19. Display team name and total number of players for each role (grouped by role).

SELECT PLAYER_ROLE,TEAM_NAME,COUNT(PLAYER_ID)
FROM STADIUM S JOIN TEAM T
ON S.Stadium_id=T.HOME_STADIUM_ID
JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
GROUP BY PLAYER_ROLE,TEAM_NAME

--20. Display team name and total number of players whose name starts with ‘A’

SELECT TEAM_NAME,COUNT(PLAYER_ID)
FROM STADIUM S JOIN TEAM T
ON S.Stadium_id=T.HOME_STADIUM_ID
JOIN PLAYER P
ON P.TEAM_ID=T.TEAM_ID
WHERE PLAYER_FIRST_NAME LIKE 'A%'
GROUP BY TEAM_NAME