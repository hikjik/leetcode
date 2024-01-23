WITH Drivers AS (
    SELECT DISTINCT driver_id
      FROM Rides
)
SELECT Drivers.driver_id,
       COUNT(ride_id) AS cnt
  FROM Drivers
  LEFT JOIN Rides
    ON Drivers.driver_id = Rides.passenger_id
 GROUP BY Drivers.driver_id;
