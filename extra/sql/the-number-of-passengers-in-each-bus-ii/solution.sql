WITH RECURSIVE PassengersCount AS (
    SELECT bus_id, capacity,
           COUNT(passenger_id) AS cumulative_cnt,
           RANK() OVER(ORDER BY Buses.arrival_time, bus_id) AS rnk
      FROM Buses
      LEFT JOIN Passengers
        ON Passengers.arrival_time <= Buses.arrival_time
     GROUP BY bus_id
), BusBoarding AS (
    SELECT bus_id, rnk,
           @passengers_cnt := LEAST(cumulative_cnt, capacity) AS passengers_cnt,
           @passengers_cnt AS cumulative_cnt
      FROM PassengersCount
     WHERE rnk = 1
     UNION ALL
    SELECT PassengersCount.bus_id, PassengersCount.rnk,
           @passengers_cnt := LEAST(PassengersCount.cumulative_cnt - BusBoarding.cumulative_cnt,
                                    PassengersCount.capacity) AS passengers_cnt,
           @passengers_cnt + BusBoarding.cumulative_cnt AS cumulative_cnt
      FROM PassengersCount, BusBoarding
     WHERE PassengersCount.rnk = BusBoarding.rnk + 1
)
SELECT bus_id, passengers_cnt
  FROM BusBoarding
 ORDER BY bus_id;
