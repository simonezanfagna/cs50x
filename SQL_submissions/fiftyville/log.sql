-- Keep a log of any SQL queries you execute as you solve the mystery.

-- I get the crime scene report
SELECT description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2023 AND street = 'Humphrey Street';
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

-- took place at 10:15am at the Humphrey Street bakery


-- I read the statements of the interviewees
SELECT name, transcript FROM interviews WHERE day = 28 AND month = 7 AND year = 2023;
-- Ruth    | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- Eugene  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- check bakery park log
-- check ATM withdrawing and purchase flight tickets
-- check phone calls
-- check the earliest flight out of Fiftyville on the 29th


-- I control the entrances and exits of the bakery
SELECT hour, minute, activity, license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2023;
-- hour | minute | activity | license_plate |
-- 10   | 16     | exit     | 5P2BI95       |
-- 10   | 18     | exit     | 94KL13X       |
-- 10   | 18     | exit     | 6P58WS2       |
-- 10   | 19     | exit     | 4328GD8       |
-- 10   | 20     | exit     | G412CB7       |
-- 10   | 21     | exit     | L93JTIZ       |
-- 10   | 23     | exit     | 322W7JE       |
-- 10   | 23     | exit     | 0NTHK55       |


-- I check the data of the people who left the bakery within 10 minutes of the theft
SELECT * FROM people
WHERE license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE day = 28 AND month = 7 AND year = 2023 AND hour = 10 AND minute >= 15 AND minute <= 25
);
--   id   |  name   |  phone_number  | passport_number | license_plate |
-- 221103 | Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       |
-- 243696 | Barry   | (301) 555-4174 | 7526138472      | 6P58WS2       |
-- 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
-- 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
-- 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
-- 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
-- 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
-- 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |


-- I check the withdrawals from the ATM in Leggett Street
SELECT * FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2023 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
-- id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- 246 | 28500762       | 2023 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- 264 | 28296815       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- 266 | 76054385       | 2023 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- 267 | 49610011       | 2023 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- 269 | 16153065       | 2023 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- 288 | 25506511       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- 313 | 81061156       | 2023 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- 336 | 26013199       | 2023 | 7     | 28  | Leggett Street | withdraw         | 35     |


-- I cross-reference the withdrawal data from the ATM with the data of the cars leaving the bakery, in order to know the data of the people suspected of the theft
SELECT * FROM people
WHERE people.id IN(
    SELECT bank_accounts.person_id FROM bank_accounts
    WHERE bank_accounts.account_number IN(
        SELECT atm_transactions.account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2023 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
    )
) AND license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE day = 28 AND month = 7 AND year = 2023 AND hour = 10 AND minute >= 15 AND minute <= 25
);

--   id   |  name   |  phone_number  | passport_number | license_plate |
-- 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
-- 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
-- 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
-- 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |


SELECT * FROM airports WHERE city = 'Fiftyville';
-- id | abbreviation |          full_name          |    city
-- 8  | CSF          | Fiftyville Regional Airport | Fiftyville


SELECT * FROM flights WHERE day = 29 AND month = 7 AND year = 2023 ORDER BY hour ASC, minute ASC;
-- id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- 36 | 8                 | 4                      | 2023 | 7     | 29  | 8    | 20     |
-- 43 | 8                 | 1                      | 2023 | 7     | 29  | 9    | 30     |
-- 23 | 8                 | 11                     | 2023 | 7     | 29  | 12   | 15     |
-- 53 | 8                 | 9                      | 2023 | 7     | 29  | 15   | 20     |
-- 18 | 8                 | 6                      | 2023 | 7     | 29  | 16   | 0      |

SELECT * FROM airports WHERE id = 4;
-- id | abbreviation |     full_name     |     city      |
-- 4  | LGA          | LaGuardia Airport | New York City |

-- I know that the first flight from Fiftyville has Airport id 4 as its destination and flight id 36
-- ESCAPED TO NEW YORK CITY !!!

SELECT * FROM people
WHERE people.id IN(
    SELECT bank_accounts.person_id FROM bank_accounts
    WHERE bank_accounts.account_number IN(
        SELECT atm_transactions.account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2023 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
    )
) AND license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE day = 28 AND month = 7 AND year = 2023 AND hour = 10 AND minute >= 15 AND minute <= 25
) AND passport_number IN (
    SELECT passport_number FROM passengers
    WHERE flight_id = 36
);
--   id   | name  |  phone_number  | passport_number | license_plate |
-- 467400 | Luca  | (389) 555-5198 | 8496433585      | 4328GD8       |
-- 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |

-- I also cross-reference the data with the people who called on the 28th
SELECT * FROM people
WHERE people.id IN(
    SELECT bank_accounts.person_id FROM bank_accounts
    WHERE bank_accounts.account_number IN(
        SELECT atm_transactions.account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2023 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
    )
) AND license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE day = 28 AND month = 7 AND year = 2023 AND hour = 10 AND minute >= 15 AND minute <= 25
) AND passport_number IN (
    SELECT passport_number FROM passengers
    WHERE flight_id = 36
) AND phone_number IN(
    SELECT caller FROM phone_calls
    WHERE day = 28 AND month = 7 AND year = 2023
);
--   id   | name  |  phone_number  | passport_number | license_plate |
-- 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |

-- THE THIEF IS BRUCE !!!

-- I'm looking for an accomplice
SELECT * FROM people
WHERE phone_number IN(
    SELECT receiver FROM phone_calls WHERE caller = '(367) 555-5533' AND day = 28 AND month = 7 AND year = 2023 AND duration <= 60
);
--   id   | name  |  phone_number  | passport_number | license_plate |
-- 864400 | Robin | (375) 555-8161 | NULL            | 4V16VO0       |

-- THE ACCOMPLICE IS ROBIN !!!
