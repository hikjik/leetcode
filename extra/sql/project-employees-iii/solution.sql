WITH cte AS (
    SELECT Project.project_id, Project.employee_id,
           RANK() OVER (
               PARTITION BY project_id
                   ORDER BY experience_years DESC
           ) AS employee_rank
      FROM Project
      JOIN Employee
        ON Project.employee_id = Employee.employee_id
)
SELECT project_id, employee_id
  FROM cte
 WHERE employee_rank = 1;
