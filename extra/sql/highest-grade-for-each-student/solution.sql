SELECT student_id, course_id, grade
  FROM (SELECT student_id, course_id, grade,
               RANK() OVER (
                   PARTITION BY student_id
                       ORDER BY grade DESC, course_id ASC
               ) AS grade_rank
          FROM Enrollments) T
 WHERE grade_rank = 1
 ORDER BY student_id ASC;
