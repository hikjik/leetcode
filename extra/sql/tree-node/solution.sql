SELECT DISTINCT t1.id,
       IF (t1.p_id IS NULL, 'Root', IF (t2.id IS NULL, 'Leaf', 'Inner')) type
  FROM Tree t1
  LEFT JOIN Tree t2
    ON t1.id = t2.p_id;
