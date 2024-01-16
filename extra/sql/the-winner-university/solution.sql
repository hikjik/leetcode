SELECT CASE 
           WHEN NY.score > CA.score THEN 'New York University'
           WHEN NY.score < CA.score THEN 'California University'
           ELSE 'No Winner'
       END AS winner
  FROM (SELECT COUNT(*) as score 
          FROM NewYork 
         WHERE score >= 90) NY, 
       (SELECT COUNT(*) as score 
          FROM California 
         WHERE score >= 90) CA;
