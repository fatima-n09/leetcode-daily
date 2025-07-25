# Write your MySQL query statement below
SELECT 'Low Salary' AS category, COUNT(account_id) AS accounts_count
FROM Accounts
WHERE income<20000
UNION
SELECT 'Average Salary' as category, COUNT(*)
FROM Accounts
WHERE income>=20000 AND income<=50000
UNION
SELECT 'High Salary' as category, COUNT(*)
FROM Accounts
WHERE income>50000