SELECT (SELECT DISTINCT salary
          FROM employee
         ORDER BY salary DESC
         LIMIT 1
        OFFSET 1) AS SecondHighestSalary;
