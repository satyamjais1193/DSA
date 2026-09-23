# Write your MySQL query statement below
select name, ifnull(sum(distance),0) as travelled_distance 
from Users as u
left join Rides as r 
on r.user_id = u.id
group by u.id
order by travelled_distance desc , name;