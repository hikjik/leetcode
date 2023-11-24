SELECT id, visit_date, people
  FROM (SELECT id, visit_date, people,
               LEAD(people, 1) OVER(ORDER BY id) AS next,
               LEAD(people, 2) OVER(ORDER BY id) AS next_next,
               LAG(people, 1) OVER(ORDER BY id) AS prev,
               LAG(people, 2) OVER(ORDER BY id) AS prev_prev
          FROM Stadium) T
 WHERE (prev_prev >= 100 AND prev >= 100 AND people >= 100)
    OR (prev >= 100 AND people >= 100 AND next >= 100)
    OR (people >= 100 AND next >= 100 AND next_next >= 100);
