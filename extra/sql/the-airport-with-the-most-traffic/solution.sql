WITH Airports AS (
    SELECT departure_airport AS airport_id,
           flights_count
      FROM Flights
     UNION ALL
    SELECT arrival_airport AS airport_id,
           flights_count
      FROM Flights
), RankedAirports AS (
    SELECT airport_id,
           RANK() OVER(ORDER BY SUM(flights_count) DESC) AS rnk
      FROM Airports
     GROUP BY airport_id
)
SELECT airport_id
  FROM RankedAirports
 WHERE rnk = 1;
