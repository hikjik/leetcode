WITH SplitVotes AS (
    SELECT voter, candidate,
           1 / COUNT(*) OVER(PARTITION BY voter) AS vote
      FROM Votes
     WHERE candidate IS NOT NULL
), RankedCandidates AS (
    SELECT candidate,
           RANK() OVER(ORDER BY SUM(vote) DESC) as rnk
      FROM SplitVotes
     GROUP BY candidate
)
SELECT candidate
  FROM RankedCandidates
 WHERE rnk = 1
 ORDER BY candidate;
