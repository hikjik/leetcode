WITH RECURSIVE Months AS (
    SELECT 1 AS month
     UNION ALL
    SELECT month + 1
      FROM Months
     WHERE month < 12
), Ride AS (
    SELECT SUM(ride_distance) AS distance,
           SUM(ride_duration) AS duration,
           MONTH(requested_at) AS month
      FROM Rides
     INNER JOIN AcceptedRides USING(ride_id)
     WHERE YEAR(requested_at) = 2020
     GROUP BY month
)
SELECT month,
       IFNULL(ROUND(SUM(distance) OVER W / 3, 2), 0) AS average_ride_distance,
       IFNULL(ROUND(SUM(duration) OVER W / 3, 2), 0) AS average_ride_duration
  FROM Months
  LEFT JOIN Ride USING(month)
WINDOW W AS (ORDER BY month RANGE BETWEEN CURRENT ROW AND 2 FOLLOWING)
 LIMIT 10;
