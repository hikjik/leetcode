SELECT Employees.employee_id
  FROM Employees
  LEFT JOIN Employees AS Managers
    ON Employees.manager_id = Managers.employee_id
 WHERE Employees.manager_id is NOT NULL
   AND Managers.employee_id is NULL
   AND Employees.salary < 30000
 ORDER BY Employees.employee_id;
