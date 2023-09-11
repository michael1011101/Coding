# Write your MySQL query statement below

select * from Users where mail REGEXP '^[a-zA-Z][a-zA-Z0-9._-]*@leetcode[.]com'


/*
# 1517. Find Users With Valid E-Mails
Easy

Table: Users

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| name          | varchar |
| mail          | varchar |
+---------------+---------+
user_id is the primary key (column with unique values) for this table.
This table contains information of the users signed up in a website. Some e-mails are invalid.
 

Write a solution to find the users who have valid emails.

A valid e-mail has a prefix name and a domain where:

The prefix name is a string that may contain letters (upper or lower case), digits, underscore '_', period '.', and/or dash '-'. The prefix name must start with a letter.
The domain is '@leetcode.com'.
Return the result table in any order.

The result format is in the following example.

 

Example 1:

Input: 
Users table:
+---------+-----------+-------------------------+
| user_id | name      | mail                    |
+---------+-----------+-------------------------+
| 1       | Winston   | winston@leetcode.com    |
| 2       | Jonathan  | jonathanisgreat         |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
| 5       | Marwan    | quarz#2020@leetcode.com |
| 6       | David     | david69@gmail.com       |
| 7       | Shapiro   | .shapo@leetcode.com     |
+---------+-----------+-------------------------+
Output: 
+---------+-----------+-------------------------+
| user_id | name      | mail                    |
+---------+-----------+-------------------------+
| 1       | Winston   | winston@leetcode.com    |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
+---------+-----------+-------------------------+
Explanation: 
The mail of user 2 does not have a domain.
The mail of user 5 has the # sign which is not allowed.
The mail of user 6 does not have the leetcode domain.
The mail of user 7 starts with a period.
*/

/*
Additional Tests
Sample Test 1
| user_id | name     | mail                             |
| ------- | -------- | -------------------------------- |
| 862     | Refael   | Refaelm5m                        |
| 34      | Aharon   | 9.Aharon@leetcode.com            |
| 891     | Sarah    | Sarah@L.com                      |
| 745     | Shimon   | 2019_Shim0n@leetcode.com         |
| 46      | Freida   | Freida(A1oA2N7tK@leetcode.com    |
| 156     | Yosef    | Yosef@h.com                      |
| 528     | Refael   | Refael@N6J.com                   |
| 63      | Azriel   | Azriel@jaB.com                   |
| 379     | Daniel   | DanielT7ugi@leetcode.com         |
| 348     | Menachem | Menachem$R6CLTItUEi@leetcode.com |
| 393     | Yehudit  | Yehudit3y22YK                    |
| 660     | Yaakov   | -Yaakov@leetcode.com             |
| 99      | Yaffah   | YaffahsXa@leetcode.com           |
| 822     | Refael   | _Refael@leetcode.com             |
| 732     | Yehudit  | Yehudit..lk@leetcode.com         |
| 689     | Michael  | Michael--4@leetcode.com          |
| 182     | Adam     | AdamPs@leetcode.com              |
| 192     | Miriam   | Miriam^GCPhliEUL@leetcode.com    |

Output
| user_id | name    | mail                     |
| ------- | ------- | ------------------------ |
| 379     | Daniel  | DanielT7ugi@leetcode.com |
| 99      | Yaffah  | YaffahsXa@leetcode.com   |
| 732     | Yehudit | Yehudit..lk@leetcode.com |
| 689     | Michael | Michael--4@leetcode.com  |
| 182     | Adam    | AdamPs@leetcode.com      |

Sample Test 2
| user_id | name    | mail                 |
| ------- | ------- | -------------------- |
| 1       | Winston | winston@leetcode?com |

Output
| user_id | name | mail |
| ------- | ---- | ---- |
*/
