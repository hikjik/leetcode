WITH PurchasesWithRank AS (
    SELECT invoice_id,
           RANK() OVER(ORDER BY SUM(price * quantity) DESC, invoice_id) AS rnk
      FROM Purchases
      LEFT JOIN Products USING(product_id)
     GROUP BY invoice_id
)
SELECT product_id, quantity, price * quantity AS price
  FROM PurchasesWithRank
  JOIN Purchases USING(invoice_id)
  JOIN Products USING(product_id)
 WHERE rnk = 1;