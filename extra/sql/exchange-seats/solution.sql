SELECT row_number() over() AS id,
       student
  FROM Seat
 ORDER BY IF(MOD(id, 2) = 0, id - 1, id + 1);
