SELECT ROUND(IFNULL(AVG(sessions), 0), 2) as average_sessions_per_user
  FROM (SELECT user_id,
               COUNT(DISTINCT session_id) AS sessions
          FROM Activity
         WHERE activity_date BETWEEN DATE_SUB('2019-07-27', INTERVAL 29 DAY) AND '2019-07-27'
         GROUP BY user_id) T;