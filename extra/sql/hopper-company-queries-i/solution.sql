WITH RECURSIVE Months AS (
    SELECT 1 AS month
     UNION ALL
    SELECT month + 1
      FROM Months
     WHERE month < 12
), Driver AS (
    SELECT driver_id,
           IF(YEAR(join_date) < 2020, 1, MONTH(join_date)) AS month
      FROM Drivers
     WHERE YEAR(join_date) <= 2020
), Ride AS (
    SELECT ride_id,
           MONTH(requested_at) AS month
      FROM Rides
     INNER JOIN AcceptedRides USING(ride_id)
     WHERE YEAR(requested_at) = 2020
)
SELECT Months.month,
       COUNT(DISTINCT driver_id) AS active_drivers,
       COUNT(DISTINCT ride_id) AS accepted_rides
  FROM Months
  LEFT JOIN Driver
    ON Driver.month <= Months.month
  LEFT JOIN Ride
    ON Ride.month = Months.month
 GROUP BY Months.month;
