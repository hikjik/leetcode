WITH RankedActivities AS (
    SELECT activity,
           RANK() OVER(ORDER BY COUNT(*) DESC) AS r1,
           RANK() OVER(ORDER BY COUNT(*) ASC) AS r2
      FROM Friends
     GROUP BY activity
)
SELECT activity
  FROM RankedActivities
 WHERE r1 != 1 and r2 != 1;
