WITH EmployeeWithSalaryRank AS (
    SELECT name, salary, departmentId,
           DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS "rank"
      FROM Employee)
SELECT D.name Department, E.name Employee, E.salary Salary
  FROM EmployeeWithSalaryRank E
 INNER JOIN Department D
    ON E.departmentId = D.id
 WHERE E.rank <= 3;
