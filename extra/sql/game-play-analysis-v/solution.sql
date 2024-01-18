SELECT install_dt,
       COUNT(DISTINCT player_id) AS installs,
       ROUND(SUM(event_date = install_dt + INTERVAL 1 DAY) / 
             COUNT(DISTINCT player_id), 2) AS Day1_retention
  FROM (SELECT player_id, event_date,
               FIRST_VALUE(event_date) OVER(
                   PARTITION BY player_id ORDER BY event_date) AS install_dt
          FROM Activity) T
 GROUP BY install_dt;
