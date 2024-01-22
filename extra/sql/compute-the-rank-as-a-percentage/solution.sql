WITH RankedStudents AS (
    SELECT department_id, student_id, mark,
           COUNT(student_id) OVER(PARTITION BY department_id) AS student_count,
           RANK() OVER(PARTITION BY department_id ORDER BY mark DESC) AS student_rank
      FROM Students
)
SELECT student_id, department_id,
       IFNULL(ROUND((student_rank - 1) * 100 / (student_count - 1), 2), 0) AS percentage
  FROM RankedStudents;