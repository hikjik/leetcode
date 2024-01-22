WITH cte AS (
    SELECT user_id,
           COUNT(*) OVER(PARTITION BY user_id
                             ORDER BY created_at
                             RANGE BETWEEN INTERVAL 7 DAY PRECEDING AND CURRENT ROW) AS cnt
      FROM Users
)
SELECT DISTINCT user_id
  FROM cte
 WHERE cnt > 1;
