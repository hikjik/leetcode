SELECT 'bull' AS word, 
       SUM(content LIKE '% bull %') AS count 
  FROM Files

 UNION

SELECT 'bear' AS word, 
       SUM(content LIKE '% bear %') AS count 
  FROM Files;
