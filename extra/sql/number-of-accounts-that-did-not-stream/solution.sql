SELECT COUNT(DISTINCT account_id) AS accounts_count
  FROM Subscriptions
 WHERE YEAR(start_date) <= 2021 AND 2021 <= YEAR(end_date)
   AND account_id NOT IN (SELECT account_id
                            FROM Streams
                           WHERE YEAR(stream_date) = 2021);
