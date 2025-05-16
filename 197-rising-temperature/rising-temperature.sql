select A.id from weather A, weather B
where datediff(A.recorddate,B.recorddate) = 1 and
A.temperature > B.temperature
