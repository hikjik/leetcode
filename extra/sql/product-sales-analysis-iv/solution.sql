WITH RankedProducts AS (
    SELECT user_id, product_id,
           RANK() OVER(PARTITION BY user_id ORDER BY SUM(quantity * price) DESC) AS rnk
      FROM Sales
      JOIN Product USING(product_id)
     GROUP BY user_id, product_id
)
SELECT user_id, product_id
  FROM RankedProducts
 WHERE rnk = 1;
