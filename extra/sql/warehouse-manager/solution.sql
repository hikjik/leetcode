SELECT Warehouse.name AS  warehouse_name,
       SUM(Width * Length * Height * units) AS volume
  FROM Warehouse
  LEFT JOIN Products
    ON Warehouse.product_id = Products.product_id
 GROUP BY Warehouse.name;
