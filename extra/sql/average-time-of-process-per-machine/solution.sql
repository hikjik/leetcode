SELECT Start.machine_id,
       ROUND(AVG(End.timestamp - Start.timestamp), 3) AS processing_time
  FROM Activity AS Start
 INNER JOIN Activity AS End
    ON Start.machine_id = End.machine_id
   AND Start.process_id = End.process_id
 WHERE Start.activity_type = 'start' AND End.activity_type = 'end'
 GROUP BY Start.machine_id;
