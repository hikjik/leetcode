SELECT country_name,
       CASE
           WHEN AVG(weather_state) <= 15 THEN 'Cold'
           WHEN AVG(weather_state) >= 25 THEN 'Hot'
           ELSE 'Warm'
       END AS weather_type
  FROM Countries
  LEFT JOIN Weather USING(country_id)
 WHERE YEAR(day) = 2019 AND MONTH(day) = 11
 GROUP BY country_id;
