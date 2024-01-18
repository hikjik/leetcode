SELECT DISTINCT pay_month,
       department_id,
       CASE WHEN dep_avg = comp_avg THEN 'same'
            WHEN dep_avg < comp_avg THEN 'lower'
            WHEN dep_avg > comp_avg THEN 'higher'
       END AS comparison
  FROM (SELECT DATE_FORMAT(pay_date, "%Y-%m") AS pay_month,
               department_id, 
               AVG(amount) OVER(PARTITION BY department_id, MONTH(pay_date)) AS dep_avg,
               AVG(amount) OVER(PARTITION BY MONTH(pay_date)) AS comp_avg
          FROM Salary
          JOIN Employee USING(employee_id)) T
 ORDER BY department_id;
