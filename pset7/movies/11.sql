SELECT title FROM movies
INNER JOIN ratings ON ratings.movie_id = movies.id
WHERE id IN (
    SELECT movie_id FROM stars
    WHERE person_id =  (
        SELECT id FROM people
        WHERE name = "Chadwick Boseman"
        )
)
ORDER BY rating DESC LIMIT 5;