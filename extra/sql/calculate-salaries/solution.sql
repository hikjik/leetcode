WITH Taxes AS (
    SELECT company_id,
           CASE WHEN MAX(salary) < 1000 THEN 0.0
                WHEN MAX(salary) <= 10000 THEN 0.24
                ELSE 0.49
           END AS tax
      FROM Salaries
     GROUP BY company_id
)
SELECT company_id, employee_id, employee_name,
       ROUND(salary - tax * salary, 0) AS salary
  FROM Salaries
  JOIN Taxes USING(company_id);
