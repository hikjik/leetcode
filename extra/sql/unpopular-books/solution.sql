SELECT book_id, name
  FROM Books
  LEFT JOIN Orders USING(book_id)
 WHERE available_from <= DATE_SUB('2019-06-23', INTERVAL 1 MONTH)
 GROUP BY book_id
HAVING SUM(IF(dispatch_date >= DATE_SUB('2019-06-23', INTERVAL 1 YEAR), quantity, 0)) < 10;
