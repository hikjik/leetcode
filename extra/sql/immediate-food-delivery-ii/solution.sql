SELECT ROUND(AVG(immediate) * 100, 2) AS immediate_percentage
  FROM (SELECT DISTINCT customer_id, 
               FIRST_VALUE(
                   order_date = customer_pref_delivery_date
               ) OVER(
                   PARTITION BY customer_id 
                       ORDER BY order_date
               ) AS immediate 
          FROM Delivery) AS T;
