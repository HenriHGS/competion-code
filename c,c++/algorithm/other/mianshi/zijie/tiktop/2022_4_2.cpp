//字段为id,uid,create_time的表activity_record
// 输出参加次数最多的前五名和相应次数
/*
select id, t1.time
from  (
    select 
    from activity_record 
    activity_record
    order  by create_time dec
) as t1
limit 5 offset 5
*/
