SELECT P1.id AS p1,
       P2.id AS p2,
       ABS(P1.x_value - P2.x_value) * ABS(P1.y_value - P2.y_value) AS area
  FROM Points P1, Points P2
 WHERE P1.x_value != P2.x_value
   AND P1.y_value != P2.y_value
   AND P1.id < P2.id
 ORDER BY area DESC, p1, p2;
