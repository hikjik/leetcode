WITH FirstLogins AS (
    SELECT user_id,
           MIN(activity_date) as login_date
      FROM Traffic
     WHERE activity = 'login'
     GROUP BY user_id
)
SELECT login_date,
       COUNT(DISTINCT user_id) AS user_count
  FROM FirstLogins
 WHERE DATEDIFF('2019-06-30', login_date) <= 90 
 GROUP BY login_date;
