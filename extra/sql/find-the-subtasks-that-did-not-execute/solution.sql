WITH RECURSIVE SubTasks AS (
    SELECT task_id, subtasks_count
      FROM Tasks
     UNION ALL
    SELECT task_id, subtasks_count - 1
      FROM SubTasks
     WHERE subtasks_count > 1
)
SELECT SubTasks.task_id, SubTasks.subtasks_count AS subtask_id
  FROM SubTasks
  LEFT JOIN Executed
    ON SubTasks.task_id = Executed.task_id
   AND SubTasks.subtasks_count = Executed.subtask_id
 WHERE Executed.task_id IS NULL;
