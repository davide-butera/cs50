SELECT DISTINCT (p.name)
FROM people AS p
INNER JOIN directors AS d ON d.person_id = p.id
INNER JOIN movies AS m ON d.movie_id = m.id
INNER JOIN ratings AS r ON r.movie_id = m.id
    AND r.rating >= "9.0";