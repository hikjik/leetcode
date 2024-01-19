WITH UserSessions AS (
    SELECT user_id, session_type,
           SUM(session_type = 'Streamer') OVER(PARTITION BY user_id) AS sessions_count,
           RANK() OVER(PARTITION BY user_id ORDER BY session_start) AS rnk
      FROM Sessions
)
SELECT user_id, sessions_count
  FROM UserSessions
 WHERE rnk = 1 AND session_type = "Viewer" AND sessions_count > 0
 ORDER BY sessions_count DESC, user_id DESC;