SELECT project_id
  FROM (SELECT project_id,
               RANK() OVER(ORDER BY COUNT(employee_id) DESC) AS project_rank
          FROM Project
         GROUP BY project_id) T
 WHERE project_rank = 1;