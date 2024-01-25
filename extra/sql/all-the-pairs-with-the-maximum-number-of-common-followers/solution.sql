WITH RankedRelations AS (
    SELECT R1.user_id AS user1_id, R2.user_id AS user2_id,
           RANK() OVER(ORDER BY COUNT(R1.follower_id) DESC) AS rnk
      FROM Relations R1
      JOIN Relations R2 USING(follower_id)
     WHERE R1.user_id < R2.user_id
     GROUP BY R1.user_id, R2.user_id
)
SELECT user1_id, user2_id
  FROM RankedRelations
 WHERE rnk = 1;
