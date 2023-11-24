WITH Registration AS (
    SELECT player_id,
           MIN(event_date) AS signup
      FROM Activity
     GROUP BY player_id)
SELECT ROUND(COUNT(*) / (SELECT COUNT(*) FROM Registration), 2) AS fraction
  FROM Activity
 INNER JOIN Registration
    ON Activity.player_id = Registration.player_id
 WHERE DATEDIFF(Activity.event_date, Registration.signup) = 1;
