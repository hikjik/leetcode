WITH TasksStates AS (
    SELECT fail_date AS task_date,
           "failed" AS task_state,
           ROW_NUMBER() OVER (ORDER BY fail_date) AS num
      FROM Failed
     WHERE fail_date BETWEEN '2019-01-01' AND '2019-12-31'
     UNION ALL
    SELECT success_date AS task_date,
           "succeeded" AS task_state,
           ROW_NUMBER() OVER (ORDER BY success_date) AS num
      FROM Succeeded
     WHERE success_date BETWEEN '2019-01-01' AND '2019-12-31'
), Tasks AS (
    SELECT task_state, task_date,
           ROW_NUMBER() OVER (ORDER BY task_date) - num AS num
      FROM TasksStates
)
SELECT task_state AS period_state,
       MIN(task_date) AS start_date,
       MAX(task_date) AS end_date
  FROM Tasks
 GROUP BY num, task_state
 ORDER BY start_date;
