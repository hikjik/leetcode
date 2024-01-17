SELECT id, month,
       SUM(salary) OVER(PARTITION BY id ORDER BY month
                        RANGE BETWEEN 2 PRECEDING AND CURRENT ROW) AS Salary
  FROM (SELECT id, month, salary,
               ROW_NUMBER() OVER(PARTITION BY id ORDER BY month DESC) AS num
          FROM Employee) T
 WHERE num != 1
 ORDER BY id, month DESC;
