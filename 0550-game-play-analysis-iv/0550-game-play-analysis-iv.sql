with cte1 as (
    select player_id, min(event_date) as first_login
    from Activity
    group by player_id
),
cte2 as (
    select player_id, date_add(first_login, interval 1 day) as next_login
    from cte1
)
select 
    round(
        (
            select count(distinct player_id) 
            from Activity 
            where (player_id, event_date) in (
                select player_id, next_login from cte2
            )
        ) 
        / 
        (
            select count(distinct player_id) 
            from Activity
        ), 
        2
    ) as fraction;
