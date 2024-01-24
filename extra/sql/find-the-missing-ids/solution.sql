WITH RECURSIVE Numbers AS (
    SELECT 1 AS num
     UNION ALL
    SELECT num + 1
      FROM Numbers
     WHERE num < (SELECT MAX(customer_id) FROM Customers)
)
SELECT num AS ids
  FROM Numbers
  LEFT JOIN Customers
    ON Numbers.num = Customers.customer_id
 WHERE customer_id IS NULL;
