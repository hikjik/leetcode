SELECT Metal.symbol AS metal,
       Nonmetal.symbol AS nonmetal
  FROM Elements AS Metal, Elements AS NonMetal
 WHERE Metal.type = 'Metal' AND NonMetal.type = 'Nonmetal';
