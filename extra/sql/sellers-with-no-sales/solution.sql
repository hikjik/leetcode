SELECT Seller.seller_name
  FROM Seller
  LEFT JOIN Orders
    ON Seller.seller_id = Orders.seller_id
 GROUP BY Seller.seller_id
HAVING SUM(IFNULL(YEAR(Orders.sale_date) = 2020, 0)) = 0
 ORDER BY Seller.seller_name ASC;
