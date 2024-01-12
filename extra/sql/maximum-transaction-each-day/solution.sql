WITH TransactionsWithRank AS (
    SELECT transaction_id,
           DENSE_RANK() OVER (
               PARTITION BY DATE_FORMAT(day, '%Y-%m-%d')
                   ORDER BY amount DESC
           ) AS transaction_rank
      FROM Transactions
)
SELECT transaction_id
  FROM TransactionsWithRank
 WHERE transaction_rank = 1
 ORDER BY transaction_id;