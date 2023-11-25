SELECT person_name
  FROM (SELECT person_name,
               SUM(weight) OVER(ORDER BY turn) AS partial_sum
          FROM Queue) T
 WHERE partial_sum <= 1000
 ORDER BY partial_sum DESC
 LIMIT 1;
