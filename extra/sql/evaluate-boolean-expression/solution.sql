SELECT E.left_operand, E.operator, E.right_operand,
       CASE
       WHEN E.operator = ">" AND L.value > R.value THEN 'true'
       WHEN E.operator = "<" AND L.value < R.value THEN 'true'
       WHEN E.operator = "=" AND L.value = R.value THEN 'true'
       ELSE 'false'
       END AS value
  FROM Expressions E
  JOIN Variables L
    ON E.left_operand = L.name
  JOIN Variables R
    ON E.right_operand = R.name;
