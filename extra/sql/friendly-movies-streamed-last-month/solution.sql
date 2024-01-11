SELECT DISTINCT title
  FROM TVProgram
  LEFT JOIN Content
    ON TVProgram.content_id = Content.content_id
 WHERE YEAR(program_date) = 2020
   AND MONTH(program_date) = 6
   AND Kids_content = 'Y'
   AND content_type = 'Movies';
