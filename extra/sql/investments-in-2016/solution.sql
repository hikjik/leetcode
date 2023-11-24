SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
  FROM (SELECT tiv_2016,
               COUNT(*) OVER(PARTITION by tiv_2015) AS tiv_2015_count,
               COUNT(*) OVER(PARTITION by lat, lon) AS cords_count
          FROM Insurance) AS T
 WHERE tiv_2015_count > 1 AND cords_count = 1;
