WITH Priority AS (
    SELECT passenger_id, flight_id,
           RANK() OVER(PARTITION BY flight_id ORDER BY booking_time) AS rnk
      FROM Passengers
)
SELECT passenger_id,
       IF(rnk <= capacity, "Confirmed", "Waitlist") AS Status
  FROM Priority
  JOIN Flights USING(flight_id)
 ORDER BY passenger_id;
