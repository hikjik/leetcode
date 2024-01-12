WITH cte AS (
    SELECT student_id, score,
           MAX(score) OVER (PARTITION BY exam_id) AS high,
           MIN(score) OVER (PARTITION BY exam_id) AS low
      FROM Exam
)
SELECT DISTINCT student_id, student_name
  FROM cte
  JOIN Student USING (student_id)
 GROUP BY student_id
HAVING SUM(score = low OR score = high) = 0
 ORDER BY student_id;
