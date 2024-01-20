WITH TransactionsWithGroupId AS (
    SELECT T1.customer_id, T1.transaction_date,
           DATE_SUB(T1.transaction_date, INTERVAL ROW_NUMBER() OVER W DAY) AS group_id
      FROM Transactions T1
      JOIN Transactions T2 USING(customer_id)
     WHERE T1.amount < T2.amount
       AND DATEDIFF(T2.transaction_date, T1.transaction_date) = 1
    WINDOW W AS (PARTITION BY T1.customer_id ORDER BY T1.transaction_date)
)
SELECT customer_id,
       MIN(transaction_date) AS consecutive_start,
       DATE_ADD(MIN(transaction_date), INTERVAL COUNT(*) DAY) AS consecutive_end
  FROM TransactionsWithGroupId
 GROUP BY customer_id, group_id
HAVING COUNT(*) > 1;
