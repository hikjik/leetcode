SELECT candidate_id
  FROM Candidates
  LEFT JOIN Rounds
    ON Candidates.interview_id = Rounds.interview_id
 WHERE Candidates.years_of_exp >= 2
 GROUP BY candidate_id
HAVING SUM(score) > 15;
