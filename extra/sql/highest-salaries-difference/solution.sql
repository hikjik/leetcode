SELECT ABS(
    (SELECT MAX(salary) salary
       FROM Salaries
      WHERE department = 'Marketing') -
    (SELECT MAX(salary) salary
       FROM Salaries
      WHERE department = 'Engineering')
) AS salary_difference;
