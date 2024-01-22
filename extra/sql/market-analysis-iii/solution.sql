WITH RankedSellers AS (
    SELECT seller_id,
           COUNT(DISTINCT item_id) AS num_items,
           RANK() OVER(ORDER BY COUNT(DISTINCT item_id) DESC) rnk
      FROM Users
      LEFT JOIN Orders USING(seller_id)
      JOIN Items USING(item_id)
     WHERE favorite_brand != item_brand
     GROUP BY seller_id
)
SELECT seller_id, num_items
  FROM RankedSellers
 WHERE rnk = 1
 ORDER BY seller_id;
