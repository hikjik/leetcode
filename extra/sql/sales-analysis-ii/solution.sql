SELECT buyer_id
  FROM Sales
 INNER JOIN Product USING(product_id)
 GROUP BY buyer_id
HAVING SUM(product_name = 'iPhone') = 0
   AND SUM(product_name = 'S8') > 0;
