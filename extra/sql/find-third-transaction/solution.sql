WITH RankedTransactions AS (
    SELECT user_id, spend, transaction_date,
           RANK() OVER W AS rank_by_date,
           LAG(spend, 1) OVER W AS first_spend,
           LAG(spend, 2) OVER W AS second_spend
      FROM Transactions
    WINDOW W AS (PARTITION BY user_id ORDER BY transaction_date)
)
SELECT user_id,
       spend AS third_transaction_spend,
       transaction_date AS third_transaction_date
  FROM RankedTransactions
 WHERE rank_by_date = 3
   AND spend > first_spend AND spend > second_spend
 ORDER BY user_id;
