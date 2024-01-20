WITH CumulativeSalaries AS (
    SELECT employee_id, experience,
           SUM(salary) OVER(
               PARTITION BY experience
                   ORDER BY salary, employee_id) AS cumsum_salary
      FROM Candidates
), SenoirsBudget AS (
    SELECT 70000 AS budget
), SeniorsCost AS (
    SELECT MAX(cumsum_salary) AS cost
      FROM CumulativeSalaries, SenoirsBudget
     WHERE experience = 'Senior' AND cumsum_salary <= budget
), JuniorsBudget AS (
    SELECT budget - IFNULL(cost, 0) AS budget
      FROM SeniorsCost, SenoirsBudget
), HiredSeniors AS (
    SELECT employee_id
      FROM CumulativeSalaries, SenoirsBudget
     WHERE experience = 'Senior' AND cumsum_salary <= budget
), HiredJuniors AS (
    SELECT employee_id
      FROM CumulativeSalaries, JuniorsBudget
     WHERE experience = 'Junior' AND cumsum_salary <= budget
)
SELECT 'Senior' AS experience,
       COUNT(*) AS accepted_candidates
  FROM HiredSeniors
 UNION
SELECT 'Junior' AS experience,
       COUNT(*) AS accepted_candidates
  FROM HiredJuniors;
