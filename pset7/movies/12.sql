SELECT DISTINCT m.title
FROM movies m
INNER JOIN stars AS s1 ON s1.movie_id = m.id
INNER JOIN stars AS s2 ON s2.movie_id = m.id
INNER JOIN people AS p1 ON p1.id = s1.person_id
    AND p1.name = 'Johnny Depp'
INNER JOIN people AS p2 ON p2.id = s2.person_id
    AND p2.name = 'Helena Bonham Carter';