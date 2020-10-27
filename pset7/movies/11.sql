SELECT m.title
FROM movies AS m
INNER JOIN stars AS s ON s.movie_id = m.id
INNER JOIN ratings AS r ON r.movie_id = m.id
INNER JOIN people AS p ON s.person_id = p.id
    AND p.name = "Chadwick Boseman"
ORDER BY rating DESC LIMIT 5;