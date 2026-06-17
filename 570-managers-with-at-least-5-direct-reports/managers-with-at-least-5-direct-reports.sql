# Write your MySQL query statement below
-- create VIEW  info as 
-- select *

-- from Employee
-- -- where count(managerId) >= 5
-- group by managerId
-- having count(managerId) >= 5

select e2.name
from Employee as e1
join Employee as e2
on e1.managerId = e2.id
group by e1.managerId  
having count(e1.managerId) >= 5;






