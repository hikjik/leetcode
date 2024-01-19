WITH TransactionsWithRank AS (
    SELECT customer_id, transaction_date,
           RANK() OVER(PARTITION BY customer_id ORDER BY transaction_date) AS transaction_rank
      FROM Transactions
), CustomersWithRank AS (
    SELECT customer_id,
           RANK() OVER(ORDER BY COUNT(*) DESC) as customer_rank
      FROM TransactionsWithRank
     GROUP BY customer_id, DATE_SUB(transaction_date, INTERVAL transaction_rank DAY)
)
SELECT customer_id
  FROM CustomersWithRank
 WHERE customer_rank = 1
 ORDER BY customer_id;
