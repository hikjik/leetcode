SELECT DISTINCT seat_id
  FROM (SELECT seat_id,
               LAG(seat_id) OVER (ORDER BY seat_id) AS prev_seat_id, 
               LEAD(seat_id) OVER (ORDER BY seat_id) AS next_seat_id
          FROM Cinema
         WHERE free = 1) T
 WHERE seat_id = prev_seat_id + 1
    OR seat_id = next_seat_id - 1
 ORDER BY seat_id ASC;
