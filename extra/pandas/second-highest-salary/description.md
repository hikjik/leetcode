# [176. Second Highest Salary](https://leetcode.com/problems/second-highest-salary/)

<p style="color:orange;">Medium</p>

Table: Employee


+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id is the primary key (column with unique values) for this table.
Each row of this table contains information about the salary of an employee.


&nbsp;

Write a solution to find&nbsp;the second highest salary from the Employee table. If there is no second highest salary,&nbsp;return&nbsp;null (return&nbsp;None in Pandas).

The result format is in the following example.

&nbsp;
Example 1:


Input: 
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
Output: 
+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+


Example 2:


Input: 
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
+----+--------+
Output: 
+---------------------+
| SecondHighestSalary |
+---------------------+
| null                |
+---------------------+


