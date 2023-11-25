WITH DailySales AS (
    SELECT visited_on,
           SUM(amount) AS amount
      FROM Customer
     GROUP BY visited_on
), WeeklySales AS (
    SELECT visited_on,
           COUNT(visited_on) OVER WeekWindow as days_count,
           SUM(amount) OVER WeekWindow AS amount,
           ROUND(AVG(amount) OVER WeekWindow, 2) AS average_amount
      FROM DailySales
    WINDOW WeekWindow AS (ORDER BY visited_on
                          RANGE BETWEEN INTERVAL 6 DAY PRECEDING AND CURRENT ROW)
)
SELECT visited_on, amount, average_amount
  FROM WeeklySales
 WHERE days_count = 7;
