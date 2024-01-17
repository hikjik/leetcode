SELECT id, company, salary
  FROM (SELECT id, company, salary,
               RANK() OVER (PARTITION BY company ORDER BY salary, id) AS rnk,
               COUNT(*) OVER (PARTITION BY company) AS cnt
          FROM Employee) T
 WHERE rnk >= cnt / 2 AND rnk <= cnt / 2 + 1;
