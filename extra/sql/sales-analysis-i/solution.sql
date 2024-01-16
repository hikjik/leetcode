SELECT seller_id
  FROM (
      SELECT seller_id,
             RANK() OVER (ORDER BY SUM(price) DESC) AS seller_rank
        FROM Sales
       GROUP BY seller_id
  ) T
 WHERE seller_rank = 1;
