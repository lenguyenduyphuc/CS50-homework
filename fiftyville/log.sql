--The Thief' name:
SELECT people.name
FROM people
WHERE people.id IN (
    SELECT people.id
    FROM people
    WHERE people.license_plate IN (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10
        AND minute >= 15 AND minute <=25
        AND activity = "exit"
    )
)
AND people.id IN (
    SELECT people.id
    FROM people
    WHERE people.phone_number IN (
        SELECT caller
        FROM phone_calls
        WHERE year = 2021 AND month = 7 AND day = 28
        AND duration < 60
    )
)
AND people.id IN (
    SELECT people.id
    FROM people
    WHERE people.id IN (
        SELECT person_id
        FROM bank_accounts
        WHERE account_number IN (
            SELECT account_number
            FROM atm_transactions
            WHERE year = 2021 AND month = 7 AND day = 28
            AND atm_location = "Leggett Street"
            AND transaction_type = "withdraw"
            ORDER BY amount
        )
    )
)
AND people.id IN (
    SELECT people.id
    FROM people
    WHERE people.passport_number IN (
        SELECT passengers.passport_number
        FROM people
        JOIN passengers
        ON people.passport_number = passengers.passport_number
        JOIN flights
        ON passengers.flight_id = flights.id
        WHERE flights.year = 2021
        AND flights.month = 7 AND flights.day = 29
        AND flights.hour = 8  AND flights.minute = 20
        ORDER BY passengers.passport_number
    )
);


--The city
SELECT DISTINCT airports.city
FROM flights
JOIN airports
ON airports.id = (
	SELECT flights.destination_airport_id
    FROM people
    JOIN passengers
    ON people.passport_number = passengers.passport_number
    JOIN flights
    ON passengers.flight_id = flights.id
    WHERE flights.year = 2021
    AND flights.month = 7 AND flights.day = 29
    AND people.name = "Bruce"
);


-- The accomplace:
SELECT people.name
FROM people
WHERE people.phone_number IN (
	SELECT receiver
	FROM phone_calls
	WHERE year = 2021 AND month = 7 AND day = 28
	AND duration < 60
	AND caller = (
	SELECT people.phone_number
        FROM people
        WHERE people.name = "Bruce"
    )
);
