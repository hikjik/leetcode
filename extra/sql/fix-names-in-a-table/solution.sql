SELECT user_id,
       CONCAT(UPPER(LEFT(name, 1)), LOWER(SUBSTR(name, 2))) name 
  FROM users
 ORDER BY user_id;
