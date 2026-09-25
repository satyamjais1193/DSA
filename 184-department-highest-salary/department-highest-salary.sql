-- SELECT 
--     d.name AS Department,
--     e.name AS Employee,
--     e.salary AS Salary
-- FROM Employee e
-- JOIN Department d
--     on e.departmentId = d.id
-- where e.salary = (
--     select max(e2.salary)
--     from employee e2
--     where e2.departmentId  = e.departmentId 
-- )

-- METHOD 2
SELECT Department, Employee, Salary
FROM (
    SELECT 
        d.name AS Department,
        e.name AS Employee,
        e.salary AS Salary,
        max(salary) over( partition by departmentId) as maxsalary
    FROM Employee e
    JOIN Department d
        on e.departmentId = d.id
) t
where salary = maxsalary
