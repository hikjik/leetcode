WITH MaxSalaryInDepartment AS (
    SELECT MAX(salary) maxSalary, departmentId
      FROM Employee E
     GROUP BY departmentId)
SELECT D.name Department, E.name Employee, E.salary Salary 
  FROM Employee E
 INNER JOIN MaxSalaryInDepartment S
    ON E.departmentId = S.departmentId
 INNER JOIN Department D
    ON E.departmentId = D.id
 WHERE E.salary = S.maxSalary;
