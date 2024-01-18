WITH OrdersWithRank AS (
    SELECT seller_id, item_id,
           RANK() OVER (PARTITION BY seller_id
                            ORDER BY order_date) AS rnk
      FROM Orders
), SecondSales AS (
    SELECT seller_id, item_id, item_brand
      FROM OrdersWithRank
      JOIN Items USING(item_id)
     WHERE rnk = 2
)
SELECT user_id AS seller_id,
       IF(favorite_brand = item_brand, 'yes', 'no') AS 2nd_item_fav_brand
  FROM SecondSales
 RIGHT JOIN Users
    ON Users.user_id = SecondSales.seller_id;
