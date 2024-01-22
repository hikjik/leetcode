WITH RankedWeather AS (
    SELECT city_id, day, degree,
           RANK() OVER(PARTITION BY city_id ORDER BY degree DESC, day) AS rnk
      FROM Weather 
)
SELECT city_id, day, degree
  FROM RankedWeather
 WHERE rnk = 1
 ORDER BY city_id;
