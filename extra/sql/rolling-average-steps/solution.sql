WITH RollingAverages AS (
    SELECT user_id, steps_date,
           COUNT(*) OVER W AS consecutive_days_count,
           ROUND(AVG(steps_count) OVER W, 2) AS rolling_average
      FROM Steps
    WINDOW W AS (PARTITION BY user_id
                     ORDER BY steps_date
                     RANGE BETWEEN INTERVAL 2 DAY PRECEDING AND CURRENT ROW)
)
SELECT user_id, steps_date, rolling_average
  FROM RollingAverages
 WHERE consecutive_days_count = 3
 ORDER BY user_id, steps_date;
