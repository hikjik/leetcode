WITH OrdersWithRank AS (
    SELECT product_id, order_id, order_date,
           DENSE_RANK() OVER(
               PARTITION BY product_id
                   ORDER BY order_date DESC
           ) AS product_rank
      FROM Orders
)
SELECT Products.product_name, Products.product_id,
       OrdersWithRank.order_id, OrdersWithRank.order_date
  FROM Products
  JOIN OrdersWithRank
    ON Products.product_id = OrdersWithRank.product_id
 WHERE product_rank = 1
 ORDER BY product_name ASC, product_id ASC, order_id ASC;