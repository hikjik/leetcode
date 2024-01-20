WITH PurchasesPerYear AS (
    SELECT customer_id,
           YEAR(order_date) AS year, 
           SUM(price) AS total_price
      FROM Orders
     GROUP BY customer_id, YEAR(order_date)
), PurchasesWithRank AS (
    SELECT customer_id, year,
           RANK() OVER(PARTITION BY customer_id ORDER BY year) AS rank_by_year,
           RANK() OVER(PARTITION BY customer_id ORDER BY total_price) AS rank_by_price
      FROM PurchasesPerYear
)
SELECT customer_id
  FROM PurchasesWithRank
 GROUP BY customer_id
HAVING SUM(rank_by_year = rank_by_price) = MAX(year) - MIN(year) + 1;
