WITH UniqueIds AS (
    SELECT MIN(id) id
      FROM Person
     GROUP BY email)
DELETE FROM Person
 WHERE id NOT IN (SELECT id FROM UniqueIds);
