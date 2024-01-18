WITH UsersWithRank AS (
    SELECT username, activity, startDate, endDate,
           RANK() OVER(PARTITION BY username
                           ORDER BY endDate DESC) AS rnk,
           COUNT(*) OVER(PARTITION BY username) AS cnt
      FROM UserActivity
)
SELECT username, activity, startDate, endDate
  FROM UsersWithRank
 WHERE rnk = 2 OR rnk = 1 AND cnt = 1;
