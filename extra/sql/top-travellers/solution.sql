SELECT U.name,
       SUM(IFNULL(r.distance, 0)) travelled_distance
  FROM Users U
  LEFT JOIN rides r
    ON U.id = r.user_id
 GROUP BY U.id
 ORDER BY travelled_distance DESC, U.name ASC;
