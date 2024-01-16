SELECT id, year,
       IFNULL(npv, 0) AS npv
  FROM Queries
  LEFT JOIN NPV USING(id, year);
