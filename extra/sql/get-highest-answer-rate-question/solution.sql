WITH RankedQuestions AS (
    SELECT question_id,
           RANK() OVER (ORDER BY AVG(action = 'answer') DESC, question_id) AS rnk
      FROM SurveyLog
     WHERE action != 'skip'
     GROUP BY question_id
)
SELECT question_id AS survey_log
  FROM RankedQuestions
 WHERE rnk = 1;
