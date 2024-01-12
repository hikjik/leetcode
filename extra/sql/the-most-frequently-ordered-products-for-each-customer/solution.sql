WITH OrdersWithRank AS (
    SELECT customer_id, product_id,
           DENSE_RANK() OVER (
               PARTITION BY customer_id
                   ORDER BY COUNT(product_id) DESC
           ) AS product_rank
      FROM Orders
     GROUP BY customer_id, product_id
)
SELECT customer_id, product_id, product_name
  FROM OrdersWithRank
  JOIN Products USING(product_id)
 WHERE product_rank = 1;
