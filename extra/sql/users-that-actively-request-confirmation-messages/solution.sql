SELECT DISTINCT c1.user_id
  FROM Confirmations C1, Confirmations C2
WHERE C1.user_id = C2.user_id
  AND C1.time_stamp < C2.time_stamp
  AND TIMESTAMPDIFF(SECOND, C1.time_stamp, C2.time_stamp) <= 24 * 60 * 60;
