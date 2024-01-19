WITH WineriesWithRank AS (
    SELECT country,
           CONCAT(winery, ' (', SUM(points), ')') AS winery,
           RANK() OVER(PARTITION BY country
                           ORDER BY SUM(points) DESC, winery) AS rnk
      FROM Wineries
     GROUP BY country, winery
)
SELECT country,
       MAX(IF(rnk = 1, winery, NULL)) AS top_winery,
       IFNULL(MAX(IF(rnk = 2, winery, NULL)), "No second winery") AS second_winery,
       IFNULL(MAX(IF(rnk = 3, winery, NULL)), "No third winery") AS third_winery
  FROM WineriesWithRank
 GROUP BY country
 ORDER BY country;
