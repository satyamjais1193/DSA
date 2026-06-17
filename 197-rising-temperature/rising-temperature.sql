# Write your MySQL query statement below

--  $0

-- hello kya hal chal dosto aur bataooo kaise ho

select a.id
    from Weather AS a
    inner join Weather AS b
    -- on a.id = b.id
        on DATEDIFF(a.recordDate , b.recordDate) = '1'
        where a.temperature  > b.temperature  ;