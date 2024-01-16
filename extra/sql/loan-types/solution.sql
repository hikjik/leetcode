SELECT DISTINCT L1.user_id
  FROM Loans L1
  JOIN Loans L2
    ON L1.user_id = L2.user_id
 WHERE L1.loan_type = 'Mortgage' AND L2.loan_type = 'Refinance'
 ORDER BY L1.user_id;
