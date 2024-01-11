SELECT person1, person2,
       COUNT(*) AS call_count,
       SUM(duration) AS total_duration
  FROM (SELECT IF(from_id < to_id, from_id, to_id) AS person1,
               IF(from_id > to_id, from_id, to_id) AS person2,
               duration
          FROM Calls
       ) T
 GROUP BY person1, person2;
