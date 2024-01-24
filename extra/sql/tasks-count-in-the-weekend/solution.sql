SELECT SUM(WEEKDAY(submit_date) > 4) AS weekend_cnt,
       SUM(WEEKDAY(submit_date) < 5) AS working_cnt
  FROM Tasks;
