SELECT CEIL(minute / 6) AS interval_no,
       SUM(order_count) AS total_orders
  FROM Orders
 GROUP BY CEIL(minute / 6)
 ORDER BY interval_no;
