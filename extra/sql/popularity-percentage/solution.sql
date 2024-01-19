WITH Users AS (
    SELECT user1, user2
      FROM Friends
     UNION
    SELECT user2, user1
      FROM Friends
)
SELECT user1,
       ROUND(COUNT(DISTINCT user2) * 100 /
             COUNT(user1) OVER(), 2) AS percentage_popularity
  FROM Users
 GROUP BY user1
 ORDER BY user1;