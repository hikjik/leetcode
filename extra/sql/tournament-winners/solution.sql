WITH Scores AS (
    SELECT first_player AS player_id,
           first_score AS score
      FROM Matches
     UNION ALL
    SELECT second_player AS player_id,
           second_score AS score
      FROM Matches
)
SELECT DISTINCT group_id AS GROUP_ID,
       FIRST_VALUE(player_id) OVER(
           PARTITION BY group_id 
               ORDER BY SUM(Scores.score) DESC, Players.player_id) AS PLAYER_ID
  FROM Players
  LEFT JOIN Scores USING(player_id)
 GROUP BY Scores.player_id;
