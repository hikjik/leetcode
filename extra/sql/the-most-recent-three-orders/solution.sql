WITH OrdersWithRank AS (
    SELECT order_id, order_date, customer_id,
           DENSE_RANK() OVER (
               PARTITION BY customer_id
                   ORDER BY order_date DESC
           ) AS order_rank
      FROM Orders
)
SELECT Customers.name AS customer_name,
       Customers.customer_id,
       OrdersWithRank.order_id,
       OrdersWithRank.order_date
  FROM Customers
 INNER JOIN OrdersWithRank
    ON Customers.customer_id = OrdersWithRank.customer_id
 WHERE order_rank <= 3
 ORDER BY customer_name ASC, customer_id ASC, order_date DESC;
