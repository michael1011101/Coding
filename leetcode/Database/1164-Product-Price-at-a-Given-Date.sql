# Write your MySQL query statement below

with pid as (
  select distinct product_id as 'product_id' from Products
)

select
  pid.product_id,
  IFNULL(new_price, 10) as price
from pid
left join(
select
  p.product_id,
  p.new_price
from
  Products as p
  join (
    select
      product_id,
      max(change_date) as max_change_date
    from Products
    where change_date <= '2019-08-16'
    group by product_id
  ) c
  on p.product_id=c.product_id and p.change_date=c.max_change_date
) newp
on pid.product_id = newp.product_id


/*
# 1164. Product Price at a Given Date

Medium

Table: Products

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| new_price     | int     |
| change_date   | date    |
+---------------+---------+
(product_id, change_date) is the primary key of this table.
Each row of this table indicates that the price of some product was changed to a new price at some date.
 

Write an SQL query to find the prices of all products on 2019-08-16. Assume the price of all products before any change is 10.

Return the result table in any order.

The query result format is in the following example.

 

Example 1:

Input: 
Products table:
+------------+-----------+-------------+
| product_id | new_price | change_date |
+------------+-----------+-------------+
| 1          | 20        | 2019-08-14  |
| 2          | 50        | 2019-08-14  |
| 1          | 30        | 2019-08-15  |
| 1          | 35        | 2019-08-16  |
| 2          | 65        | 2019-08-17  |
| 3          | 20        | 2019-08-18  |
+------------+-----------+-------------+
Output: 
+------------+-------+
| product_id | price |
+------------+-------+
| 2          | 50    |
| 1          | 35    |
| 3          | 10    |
+------------+-------+
*/
