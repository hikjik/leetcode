SELECT session_id
  FROM Playback
  LEFT JOIN Ads
    ON Playback.customer_id = Ads.customer_id
   AND timestamp BETWEEN start_time AND end_time
 WHERE Ads.customer_id IS NULL;
