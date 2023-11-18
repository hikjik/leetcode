SELECT Employees.employee_id
  FROM Employees
  LEFT JOIN Salaries
    ON Employees.employee_id = Salaries.employee_id
 WHERE Salaries.salary IS NULL

 UNION

SELECT Salaries.employee_id
  FROM Employees
 RIGHT JOIN Salaries
    ON Employees.employee_id = Salaries.employee_id
 WHERE Employees.name IS NULL

 ORDER BY employee_id;
