SELECT DISTINCT num AS ConsecutiveNums
  FROM (SELECT LAG(num) OVER(ORDER BY id) AS prev,
               num,
               LEAD(num) OVER(ORDER BY id) AS next
               FROM Logs) T
 WHERE prev = num AND num = next;
