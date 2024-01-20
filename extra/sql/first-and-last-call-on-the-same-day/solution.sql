WITH UnifiedCalls AS (
    SELECT caller_id AS user1, recipient_id AS user2, call_time
      FROM Calls
     UNION ALL
    SELECT recipient_id AS user1, caller_id AS user2, call_time
      FROM Calls
), RankedCalls AS (
    SELECT user1, user2, call_time,
           DENSE_RANK() OVER (
               PARTITION BY user1, DATE(call_time)
                   ORDER BY call_time ASC) AS rank_earliest_calls,
           DENSE_RANK() OVER (
               PARTITION BY user1, DATE(call_time)
                   ORDER BY call_time DESC) AS rank_latest_calls
      FROM UnifiedCalls
)
SELECT DISTINCT user1 AS user_id
  FROM RankedCalls
 WHERE rank_earliest_calls = 1 OR rank_latest_calls = 1
 GROUP BY user1, DATE(call_time)
HAVING COUNT(DISTINCT user2) = 1;
