SELECT ROUND(AVG(num), 1) AS median
  FROM (SELECT num, frequency,
               SUM(frequency) OVER(ORDER BY num) AS partial_sum,
               SUM(frequency) OVER() AS total
          FROM Numbers) T
 WHERE partial_sum - frequency <= total / 2
   AND partial_sum >= total / 2;
