SELECT Customers.customer_id, Customers.name
  FROM Customers
  LEFT JOIN Orders
    ON Customers.customer_id = Orders.customer_id
  LEFT JOIN Product
    ON Product.product_id = Orders.product_id
 WHERE YEAR(Orders.order_date) = 2020
 GROUP BY Customers.customer_id
HAVING SUM(IF(MONTH(Orders.order_date) = 6, Product.price * Orders.quantity, 0)) >= 100
   AND SUM(IF(MONTH(Orders.order_date) = 7, Product.price * Orders.quantity, 0)) >= 100;
