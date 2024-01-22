WITH RankedCandidates AS (
    SELECT candidateId,
           RANK() OVER(ORDER BY COUNT(id) DESC) AS rnk
      FROM Vote
     GROUP BY candidateId
)
SELECT name
  FROM RankedCandidates
  JOIN Candidate
    ON Candidate.id = RankedCandidates.candidateId
 WHERE rnk = 1;
