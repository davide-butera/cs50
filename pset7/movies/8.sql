SELECT p.name
FROM people AS p
INNER JOIN stars AS s ON s.person_id = p.id
INNER JOIN movies AS m ON s.movie_id = m.id
    AND m.title = "Toy Story"