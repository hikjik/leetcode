SELECT E1.employee_id
  FROM Employees E1
  LEFT JOIN Employees E2
    ON E1.manager_id = E2.employee_id
  LEFT JOIN Employees E3
    ON E2.manager_id = E3.employee_id
 WHERE E1.employee_id != E1.manager_id
   AND E3.manager_id = 1;