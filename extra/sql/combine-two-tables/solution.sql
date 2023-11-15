SELECT firstName, lastName, city, state
  FROM person AS p
  LEFT JOIN address AS a
    ON p.personId = a.personId;
