# Write your MySQL query statement below
SELECT id, COUNT(*) AS num
FROM(
    SELECT requester_id AS id
    FROM RequestAccepted

     UNION ALL
    SELECT accepter_id
    FROM RequestAccepted
) AS freind_request
GROUP BY id
ORDER BY num DESC
LIMIT 1