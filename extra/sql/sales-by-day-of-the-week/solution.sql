SELECT item_category AS CATEGORY,
       IFNULL(SUM(CASE WHEN DAYOFWEEK(order_date) = 2 THEN quantity END), 0) AS 'MONDAY',
       IFNULL(SUM(CASE WHEN DAYOFWEEK(order_date) = 3 THEN quantity END), 0) AS 'TUESDAY',
       IFNULL(SUM(CASE WHEN DAYOFWEEK(order_date) = 4 THEN quantity END), 0) AS 'WEDNESDAY',
       IFNULL(SUM(CASE WHEN DAYOFWEEK(order_date) = 5 THEN quantity END), 0) AS 'THURSDAY',
       IFNULL(SUM(CASE WHEN DAYOFWEEK(order_date) = 6 THEN quantity END), 0) AS 'FRIDAY',
       IFNULL(SUM(CASE WHEN DAYOFWEEK(order_date) = 7 THEN quantity END), 0) AS 'SATURDAY',
       IFNULL(SUM(CASE WHEN DAYOFWEEK(order_date) = 1 THEN quantity END), 0) AS 'SUNDAY'
  FROM Items
  LEFT JOIN Orders USING(item_id)
 GROUP BY item_category
 ORDER BY item_category;
