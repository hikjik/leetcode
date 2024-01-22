SELECT F1.followee AS follower,
       COUNT(DISTINCT F1.follower) AS num
  FROM Follow F1
 INNER JOIN Follow F2
    ON F1.followee = F2.follower
 GROUP BY F1.followee