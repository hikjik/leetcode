SELECT extra AS report_reason,
       COUNT(DISTINCT post_id) AS report_count
  FROM Actions
 WHERE action_date = '2019-07-04'
   AND action = 'report'
   AND extra IS NOT NULL
 GROUP BY extra;
