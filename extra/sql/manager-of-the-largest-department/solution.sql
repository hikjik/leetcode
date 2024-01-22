WITH RankedDepartments AS (
    SELECT dep_id,
           RANK() OVER(ORDER BY COUNT(emp_id) DESC) AS dep_rank
      FROM Employees
     GROUP BY dep_id
)
SELECT emp_name AS manager_name,
       dep_id
  FROM RankedDepartments
  JOIN Employees USING(dep_id)
 WHERE dep_rank = 1 AND position = 'Manager'
 ORDER BY dep_id;
