WITH RECURSIVE November AS (
    SELECT '2023-11-01' AS purchase_date
     UNION ALL
    SELECT DATE_ADD(purchase_date, INTERVAL 1 DAY)
      FROM November
     WHERE purchase_date < '2023-11-30'
)
SELECT ROW_NUMBER() OVER() AS week_of_month,
       purchase_date,
       IFNULL(SUM(amount_spend), 0) AS total_amount
  FROM November
  LEFT JOIN Purchases USING(purchase_date)
 WHERE WEEKDAY(purchase_date) = 4
 GROUP BY purchase_date;
