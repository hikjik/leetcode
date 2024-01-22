SELECT flight_id,
       LEAST(COUNT(passenger_id), capacity) AS booked_cnt,
       GREATEST(0, COUNT(passenger_id) - capacity) AS waitlist_cnt
  FROM Flights
  LEFT JOIN Passengers USING(flight_id)
 GROUP BY flight_id
 ORDER BY flight_id;
