SELECT DISTINCT
       L1.user_id AS user_id,
       L2.user_id AS recommended_id
  FROM Listens AS L1
  JOIN Listens AS L2 USING(day, song_id)
  LEFT JOIN Friendship AS F1
    ON L1.user_id = F1.user1_id
   AND L2.user_id = F1.user2_id
  LEFT JOIN Friendship AS F2
    ON L1.user_id = F2.user2_id
   AND L2.user_id = F2.user1_id
 WHERE L1.user_id != L2.user_id
   AND F1.user1_id IS NULL
   AND F2.user1_id IS NULL
 GROUP BY L1.user_id, L2.user_id, day
HAVING COUNT(DISTINCT song_id) > 2;
