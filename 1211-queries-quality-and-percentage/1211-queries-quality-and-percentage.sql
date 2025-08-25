# Write your MySQL query statement below

select q.query_name, 
round(sum(q.rating / q.position) / count(q.query_name), 2) as quality, 
round(((
    select count(*) from Queries 
    where rating < 3 and query_name  = q.query_name
) / count(q.query_name)) * 100, 2) as poor_query_percentage 
from Queries as q
group by query_name 
