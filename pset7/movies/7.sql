SELECT m.title, r.rating
FROM ratings AS r
INNER JOIN movies AS m ON m.id = r.movie_id
    AND m.year = 2010
ORDER BY rating DESC, title ASC;