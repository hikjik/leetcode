SELECT ad_id,
       ROUND(
           IFNULL(
               SUM(action = 'Clicked') * 100 / 
               SUM(action = 'Clicked' OR action = 'Viewed')
           , 0)
       , 2) AS ctr
  FROM Ads
 GROUP BY ad_id
 ORDER BY ctr DESC, ad_id ASC;
