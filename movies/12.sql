SELECT title
FROM movies AS m
JOIN stars AS s1 ON s1.movie_id = m.id
JOIN people AS p1 ON p1.id = s1.person_id
JOIN stars as s2 ON s2.movie_id = m.id
JOIN people as p2 ON p2.id = s2.person_id
WHERE p1.name='Bradley Cooper' AND p2.name='Jennifer Lawrence'
ORDER BY title ASC;
