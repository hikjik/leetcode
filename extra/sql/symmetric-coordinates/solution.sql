WITH IndexedCoordinates AS (
    SELECT X, Y,
           ROW_NUMBER() OVER() AS rn
      FROM Coordinates
)
SELECT DISTINCT C1.X AS x, C1.Y AS y
  FROM IndexedCoordinates C1, IndexedCoordinates C2
 WHERE C1.rn != C2.rn
   AND C1.X = C2.Y AND C1.Y = C2.X
   AND C1.X <= C1.Y
 ORDER BY x, y;
