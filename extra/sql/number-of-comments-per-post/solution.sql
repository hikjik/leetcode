SELECT Post.sub_id AS post_id,
       COUNT(DISTINCT Comments.sub_id) AS number_of_comments
  FROM Submissions AS Post
  LEFT JOIN Submissions AS Comments
    ON Post.sub_id = Comments.parent_id
 WHERE Post.parent_id IS NULL
 GROUP BY Post.sub_id
 ORDER BY Post.sub_id;
