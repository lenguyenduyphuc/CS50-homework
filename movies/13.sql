SELECT
    DISTINCT co_stars.name
FROM
    people AS kb
JOIN
    stars AS kb_stars ON kb.id = kb_stars.person_id
JOIN
    stars AS cs_stars ON kb_stars.movie_id = cs_stars.movie_id
JOIN
    people AS co_stars ON cs_stars.person_id = co_stars.id
WHERE
    kb.name = 'Kevin Bacon'
    AND co_stars.name <> 'Kevin Bacon';

