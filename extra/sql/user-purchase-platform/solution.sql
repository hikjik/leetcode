WITH SpendingWithBoth AS (
    SELECT user_id, spend_date,
           "both" AS platform,
           SUM(amount) AS amount
      FROM Spending
     GROUP BY spend_date, user_id
    HAVING COUNT(DISTINCT platform) = 2
     UNION ALL
    SELECT user_id, spend_date, platform, amount
      FROM Spending
     GROUP BY spend_date, user_id
    HAVING COUNT(DISTINCT platform) = 1
), DateWithPlatforms AS (
    SELECT DISTINCT spend_date,
                    'desktop' AS platform 
      FROM Spending
     UNION ALL
    SELECT DISTINCT spend_date,
                    'mobile' AS platform 
      FROM Spending
     UNION ALL
    SELECT DISTINCT spend_date,
                    'both' AS platform 
      FROM Spending
)
SELECT spend_date, platform,
       IFNULL(SUM(amount), 0) AS total_amount,
       COUNT(DISTINCT user_id) AS total_users
  FROM DateWithPlatforms
  LEFT JOIN SpendingWithBoth USING(spend_date, platform)
 GROUP BY spend_date, platform;
