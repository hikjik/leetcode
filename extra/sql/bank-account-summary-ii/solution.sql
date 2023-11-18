SELECT Users.name,
       SUM(amount) balance
  FROM Users
  JOIN Transactions
    ON Users.account = Transactions.account
 GROUP BY Users.account
HAVING balance > 10000;
