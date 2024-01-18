SELECT MAX(CASE WHEN continent = 'America' THEN name END) AS America,
       MAX(CASE WHEN continent = 'Asia' THEN name END) AS Asia,
       MAX(CASE WHEN continent = 'Europe' THEN name END) AS Europe
  FROM (SELECT name, continent,
               ROW_NUMBER() OVER(PARTITION BY continent ORDER BY name) AS num
          FROM Student) T
 GROUP BY num;
