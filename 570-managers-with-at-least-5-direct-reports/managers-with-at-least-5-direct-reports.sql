# Write your MySQL query statement below
select name 
from Employee
where id in (
    select managerId
    from Employee
    group by managerId
    having count(id)>=5);
    #usse in-- not == ... as inner query may return result more than one answer