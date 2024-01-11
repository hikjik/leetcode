WITH Winners AS (
    SELECT player_id,
           COUNT(*) AS grand_slams_count
      FROM (SELECT Wimbledon AS player_id
              FROM Championships
             UNION ALL
            SELECT Fr_open AS player_id
              FROM Championships
             UNION ALL
            SELECT US_open AS player_id
              FROM Championships
             UNION ALL
            SELECT Au_open AS player_id
              FROM Championships) T
     GROUP BY player_id
)
SELECT *
  FROM Players
 INNER JOIN Winners USING(player_id);
