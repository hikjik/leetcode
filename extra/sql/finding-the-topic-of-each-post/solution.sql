SELECT post_id,
       IFNULL(GROUP_CONCAT(DISTINCT topic_id ORDER BY topic_id), "Ambiguous!") AS topic
  FROM Posts
  LEFT JOIN Keywords
    ON CONCAT(' ', content, ' ') LIKE CONCAT('% ', word, ' %')
 GROUP BY post_id;
