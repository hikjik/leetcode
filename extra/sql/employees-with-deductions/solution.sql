SELECT employee_id
  FROM Employees
  LEFT JOIN Logs USING(employee_id)
 GROUP BY employee_id, needed_hours
HAVING SUM(IFNULL(CEIL(TIMESTAMPDIFF(SECOND, in_time, out_time) / 60.0), 0)) < needed_hours * 60;
