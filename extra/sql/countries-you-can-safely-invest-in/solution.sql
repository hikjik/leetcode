SELECT Country.name AS country
  FROM Person
  LEFT JOIN Country
    ON LEFT(phone_number, 3) = country_code
  LEFT JOIN Calls
    ON Person.id IN (Calls.caller_id, Calls.callee_id)
 GROUP BY Country.name
HAVING AVG(duration) > (SELECT AVG(duration) FROM calls);
