SELECT MIN(p1.x - p2.x) shortest
  FROM Point P1
 INNER JOIN Point P2
    ON p1.x > p2.x;
