SELECT Customers.customer_id,
       Customers.customer_name
  FROM Customers
 INNER JOIN Orders
    ON Customers.customer_id = Orders.customer_id
 GROUP BY customer_id
HAVING SUM(product_name = 'A') > 0
   AND SUM(product_name = 'B') > 0
   AND SUM(product_name = 'C')  = 0
 ORDER BY Customers.customer_id;
