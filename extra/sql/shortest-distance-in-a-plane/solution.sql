SELECT ROUND(MIN(SQRT(POW(P1.x - P2.x, 2) + POW(P1.y - P2.y, 2))), 2) AS shortest
  FROM Point2D P1, Point2D P2
 WHERE P1.x != P2.x OR P1.y != P2.y;
