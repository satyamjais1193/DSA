# Write your MySQL query statement below
select sell_date,
    count(distinct product) as num_sold,
    group_concat(distinct product order by product separator ',') as products #groupconcat is used for convert column item into a string

from Activities
group by sell_date;