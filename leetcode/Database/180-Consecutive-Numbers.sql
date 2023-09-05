# Write your MySQL query statement below

-- Solution 1
-- select distinct l1.num as ConsecutiveNums from Logs as l1
-- join Logs as l2 on l1.id = l2.id-1 and l1.num=l2.num
-- join Logs as l3 on l1.id = l3.id-2 and l1.num=l3.num;


-- Solution 2: lead()
with threeConsecurives as (
    select num,
    lead(num,1) over() num1,
    lead(num,2) over() num2
    from logs
)

select distinct num as ConsecutiveNums from threeConsecurives where num=num1 and num=num2;


/*
# 180. Consecutive Numbers

Table: Logs

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| num         | varchar |
+-------------+---------+
In SQL, id is the primary key for this table.
id is an autoincrement column.
 

Find all numbers that appear at least three times consecutively.

Return the result table in any order.

The result format is in the following example.

 

Example 1:

Input: 
Logs table:
+----+-----+
| id | num |
+----+-----+
| 1  | 1   |
| 2  | 1   |
| 3  | 1   |
| 4  | 2   |
| 5  | 1   |
| 6  | 2   |
| 7  | 2   |
+----+-----+
Output: 
+-----------------+
| ConsecutiveNums |
+-----------------+
| 1               |
+-----------------+
Explanation: 1 is the only number that appears consecutively for at least three times.
*/
