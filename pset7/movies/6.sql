SELECT AVG(rating)
FROM ratings AS r
INNER JOIN movies AS m ON m.id = r.movie_id
WHERE m.year = 2012;