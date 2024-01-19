SELECT DISTINCT
       L1.user_id AS user1_id,
       L2.user_id AS user2_id
  FROM Listens AS L1
  JOIN Listens AS L2 USING(day, song_id)
  JOIN Friendship AS F
    ON L1.user_id = F.user1_id
   AND L2.user_id = F.user2_id
 WHERE L1.user_id < L2.user_id
 GROUP BY L1.user_id, L2.user_id, day
HAVING COUNT(DISTINCT song_id) > 2;
