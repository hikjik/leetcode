WITH DailyRemovals AS (
    SELECT action_date,
           COUNT(DISTINCT Removals.post_id) / COUNT(DISTINCT Actions.post_id) AS daily_rate
      FROM Actions
      LEFT JOIN Removals USING(post_id)
     WHERE action = 'report' AND extra = 'spam'
     GROUP BY action_date
)
SELECT ROUND(100 * AVG(daily_rate), 2) AS average_daily_percent
  FROM DailyRemovals;
