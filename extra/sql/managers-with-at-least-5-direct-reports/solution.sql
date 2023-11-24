SELECT Manager.name
  FROM Employee
 INNER JOIN Employee AS Manager
    ON Manager.id = Employee.managerId
 GROUP BY Employee.managerId
HAVING COUNT(Employee.id) >= 5;
