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
    SELECT ride_id, driver_id,
           MONTH(requested_at) AS month
      FROM Rides
     INNER JOIN AcceptedRides USING(ride_id)
     WHERE YEAR(requested_at) = 2020
)
SELECT Months.month,
       IFNULL(
           ROUND(
               COUNT(DISTINCT Ride.driver_id) /
               COUNT(DISTINCT Driver.driver_id) * 100
            , 2)
        , 0) AS working_percentage
  FROM Months
  LEFT JOIN Driver
    ON Driver.month <= Months.month
  LEFT JOIN Ride
    ON Ride.month = Months.month
 GROUP BY Months.month;
