SELECT Products.product_name,
       SUM(Orders.unit) AS unit
  FROM Products
 INNER JOIN Orders
    ON Products.product_id = Orders.product_id
 WHERE YEAR(Orders.order_date) = 2020 AND MONTH(Orders.order_date) = 2
 GROUP BY Products.product_id
HAVING SUM(Orders.unit) >= 100;
