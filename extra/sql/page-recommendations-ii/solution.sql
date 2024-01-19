WITH Friends AS (
    SELECT user1_id AS user_id, user2_id AS friend_id
      FROM Friendship
     UNION ALL
    SELECT user2_id AS user_id, user1_id AS friend_id
      FROM Friendship
), FriendsLikes AS (
    SELECT Friends.user_id, Likes.page_id,
           COUNT(Friends.friend_id) AS friends_likes
      FROM Friends
      JOIN Likes
        ON Friends.friend_id = Likes.user_id 
     GROUP BY Friends.user_id, Likes.page_id
)
SELECT user_id, page_id, friends_likes
  FROM FriendsLikes
  LEFT JOIN Likes USING(user_id, page_id)
 WHERE Likes.user_id IS NULL
 ORDER BY user_id;
