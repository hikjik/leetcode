WITH MembersWithRate AS (
    SELECT member_id, name,
           COUNT(charged_amount) * 100 / COUNT(visit_date) AS conversion_rate
      FROM Members
      LEFT JOIN Visits USING(member_id)
      LEFT JOIN Purchases USING(visit_id)
     GROUP BY member_id, name
)
SELECT member_id, name,
       CASE
           WHEN conversion_rate IS NULL THEN 'Bronze'
           WHEN conversion_rate < 50 THEN 'Silver'
           WHEN conversion_rate < 80 THEN 'Gold'
           ELSE 'Diamond'
       END AS category
  FROM MembersWithRate;
