SELECT DISTINCT F.account_id
  FROM LogInfo F, LogInfo S
 WHERE F.account_id = S.account_id
   AND F.ip_address != S.ip_address
   AND F.login <= S.logout AND S.login <= F.logout;