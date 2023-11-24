SELECT Managers.employee_id, Managers.name,
       COUNT(Employees.employee_id) AS reports_count,
       ROUND(AVG(Employees.age)) AS average_age
  FROM Employees
 INNER JOIN Employees AS Managers
    ON Employees.reports_to = Managers.employee_id
 GROUP BY Managers.employee_id
 ORDER BY Managers.employee_id;
