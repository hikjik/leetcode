WITH Activity AS (
    SELECT event_type,
           AVG(occurrences) AS avg_occurrences
      FROM Events
     GROUP BY event_type
)
SELECT business_id
  FROM Events
  JOIN Activity USING(event_type)
 WHERE occurrences > avg_occurrences
 GROUP BY business_id
HAVING COUNT(event_type) > 1;
