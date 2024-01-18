WITH RECURSIVE UsersTransactions AS (
    SELECT Visits.user_id,
           COUNT(Transactions.user_id) AS transactions_count
      FROM Visits
      LEFT JOIN Transactions
        ON Visits.user_id = Transactions.user_id
       AND Visits.visit_date = Transactions.transaction_date
     GROUP BY Visits.user_id, Visits.visit_date
), Numbers AS (
    SELECT 0 AS transactions_count
     UNION ALL
    SELECT transactions_count + 1
      FROM Numbers
     WHERE transactions_count < (SELECT MAX(transactions_count)
                                  FROM UsersTransactions)
)
SELECT transactions_count,
       COUNT(user_id) AS visits_count
  FROM UsersTransactions
 RIGHT JOIN Numbers USING(transactions_count)
 GROUP BY transactions_count;
