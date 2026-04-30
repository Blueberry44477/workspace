USE countries;

CREATE TABLE city(
	city_id INT PRIMARY KEY AUTO_INCREMENT,
    city_name CHAR(40),
    
    country_id INT,
    FOREIGN KEY(country_id) REFERENCES country(country_id),
    
    district CHAR(30),
    population INT
);

CREATE TABLE country_language(
	language_id INT PRIMARY KEY AUTO_INCREMENT,
    language CHAR(50),
    is_official ENUM('T', 'F'),
    percentage DECIMAL(4, 1),
    
	country_id INT,
    FOREIGN KEY(country_id) REFERENCES country(country_id)
);

SELECT * FROM city;

-- 3.
ALTER TABLE country DROP capital;

-- 4.
INSERT INTO city (city_name, country_id, district, population) VALUES
('Kyiv', 1, 'Eastern Europe', 1900000),
('Paris', 2, 'Western Europe', 3375000),
('Tokyo', 3, 'Eastern Asia', 6290000),
('New Delhi', 4, 'Southern Asia', 70000000),
('Cairo', 5, 'Northern Africa', 5200000),
('Pretoria', 6, 'Southern Africa', 3000000),
('Ottawa', 7, 'North America', 1900000),
('Mexico City', 8, 'Central America', 6400000),
('Brasília', 9, 'South America', 10700000),
('Buenos Aires', 10, 'South America', 2250000),
('Canberra', 11, 'Australia and New Zealand', 1285000),
('Wellington', 12, 'Australia and New Zealand', 255000),
('Berlin', 13, 'Western Europe', 4160000),
('Rome', 14, 'Southern Europe', 2950000),
('Warsaw', 15, 'Eastern Europe', 1890000),
('Seoul', 16, 'Eastern Asia', 2585000),
('Ankara', 17, 'Middle East', 4250000),
('Hanoi', 18, 'Southeast Asia', 4900000),
('Abuja', 19, 'Western Africa', 10550000),
('Rabat', 20, 'Northern Africa', 1850000),
('Nairobi', 21, 'Eastern Africa', 2750000),
('Washington D.C.', 22, 'North America', 16550000),
('Santiago', 23, 'South America', 960000),
('Bogotá', 24, 'South America', 2550000),
('Havana', 25, 'Caribbean', 565000),
('Suva', 26, 'Melanesia', 45000),
('Port Moresby', 27, 'Melanesia', 450000);


INSERT INTO country_language (language_id, language, is_official, percentage, country_id) VALUES
-- Україна
(101, 'Ukrainian', 'T', 100.0, 1),

-- Франція
(103, 'French', 'T', 100.0, 2),

-- Японія
(104, 'Japanese', 'T', 100.0, 3),

-- Індія (багатомовна)
(105, 'Hindi', 'T', 40.0, 4),
(106, 'English', 'T', 20.0, 4),
(107, 'Bengali', 'F', 10.0, 4),
(108, 'Telugu', 'F', 8.0, 4),

-- Єгипет
(109, 'Arabic', 'T', 100.0, 5),

-- ПАР (11 офіційних, але скорочено)
(110, 'English', 'T', 20.0, 6),
(111, 'Zulu', 'T', 25.0, 6),
(112, 'Afrikaans', 'T', 15.0, 6),

-- Канада (двомовна)
(113, 'English', 'T', 75.0, 7),
(114, 'French', 'T', 22.0, 7),

-- Мексика
(115, 'Spanish', 'T', 95.0, 8),
(116, 'Nahuatl', 'F', 2.0, 8),

-- Бразилія
(117, 'Portuguese', 'T', 98.0, 9),

-- Аргентина
(118, 'Spanish', 'T', 98.0, 10),

-- Австралія
(119, 'English', 'T', 95.0, 11),

-- Нова Зеландія
(120, 'English', 'T', 90.0, 12),
(121, 'Maori', 'T', 5.0, 12),

-- Німеччина
(122, 'German', 'T', 100.0, 13),

-- Італія
(123, 'Italian', 'T', 98.0, 14),

-- Польща
(124, 'Polish', 'T', 98.0, 15),

-- Південна Корея
(125, 'Korean', 'T', 100.0, 16),

-- Туреччина
(126, 'Turkish', 'T', 90.0, 17),
(127, 'Kurdish', 'F', 10.0, 17),

-- Вʼєтнам
(128, 'Vietnamese', 'T', 100.0, 18),

-- Нігерія (багатомовна)
(129, 'English', 'T', 50.0, 19),
(130, 'Hausa', 'F', 20.0, 19),
(131, 'Yoruba', 'F', 15.0, 19),
(132, 'Igbo', 'F', 15.0, 19),

-- Марокко
(133, 'Arabic', 'T', 60.0, 20),
(134, 'Berber', 'T', 30.0, 20),

-- Кенія
(135, 'Swahili', 'T', 60.0, 21),
(136, 'English', 'T', 30.0, 21),

-- США
(137, 'English', 'F', 80.0, 22),

-- Чилі
(138, 'Spanish', 'T', 99.0, 23),

-- Колумбія
(139, 'Spanish', 'T', 99.0, 24),

-- Куба
(140, 'Spanish', 'T', 100.0, 25),

-- Фіджі
(141, 'English', 'T', 50.0, 26),
(142, 'Fijian', 'T', 45.0, 26),

-- Папуа Нова Гвінея (дуже багатомовна)
(143, 'English', 'T', 10.0, 27),
(144, 'Tok Pisin', 'T', 50.0, 27),
(145, 'Hiri Motu', 'T', 10.0, 27);

SELECT * FROM country_language;

-- 1. Країни, які знаходяться в регіоні Північна Європа та перелік офіційних мов цих країн.
SELECT name, language FROM country
JOIN country_language as country_lan
-- ON country.country_id = country_language.country_id
USING (country_id)
WHERE country.region = 'Eastern Europe' and country_lan.is_official = 'T';

-- 2. Країни, в яких однією з офіційних мов є чеська, та країни, в яких однією з офіційних мов є словацька.
SELECT name, language FROM country
JOIN country_language as country_lan
USING (country_id)
WHERE country_lan.is_official = 'T' AND (country_lan.language = 'Czech' OR country_lan.language = 'Slovak');

-- 3. знайти країни, для яких немає жодного запису у таблиці мов.
SELECT name FROM country
LEFT JOIN country_language
USING (country_id)
WHERE country_id IS NULL;

-- 4. Визначити регіони, на яких є люди, що розмовляють португальською мовою.
SELECT region FROM country
JOIN country_language as country_lan
USING (country_id)
WHERE country_lan.language = 'Portuguese';

-- 5. Кількість адміністративних одиниць (district) для кожної країни.
SELECT name, COUNT(DISTINCT city.district) FROM country
JOIN city USING (country_id)

-- 6. 
SELECT SUM((population * country_language.percentage) / 100) AS total_korean_speakers
FROM country
JOIN country_language
USING (country_id)
WHERE language = 'Korean';

-- 7. Отримати з бази даних назву столиці Еквадору, перелік мов цієї країни, та чисельність населення, яка розмовляє на кожній з цих мов.
SELECT 
	city.name, 
    country_lan.language, 
	(country.population * country_lan.language / 100) AS lan_speakers_count FROM country
JOIN city USING (country_id)
JOIN country_language as country_lan USING (country_id)
WHERE country.name = 'Ecuador';

-- 8. Для країн з пункту 1 визначити країни, в яких кількість адміністративних одиниць більше або дорівнює 15.
SELECT name FROM country
JOIN city USING (country_id)
WHERE country.region = 'North Europe'
HAVING COUNT(DISTINCT city.district) >= 15;

-- 9. Визначити країни, в яких дві офіційних мови, та країни, в яких лише дві адміністративні
-- одиниці. Запит виконати за допомогою оператора UNION.
SELECT name FROM country
JOIN country_language USING (country_id) 
WHERE country_language.is_official = true
HAVING COUNT(country_language.language) = 2

UNION

SELECT name FROM country
JOIN city USING (country_id)
HAVING COUNT(DISTINCT city.district) = 2;

-- 10. Мови, популярніші за суму (Данська + Англійська + Німецька).
SELECT 
	language,
    SUM(country.population * country_lan.percentage / 100) AS total_speakers
FROM country_language as country_lan
JOIN country USING (country_id)
HAVING SUM(country.population * country_lan.percentage / 100) > (
    SELECT SUM(c2.population * cl2.percentage / 100)
    FROM country_language cl2
    JOIN country c2 USING (country_id)
    WHERE cl2.language IN ('Danish', 'English', 'German')
);

-- 11. Вивести всі країни світу з ненульовим населенням, для кожної з них зазначити кількість
-- населення, столицю та кількість адміністративних одиниць.
SELECT 
	country.name, 
    country.population,
    city.city_name,
    COUNT(DISTINCT city_all.district) AS district_count
FROM country
LEFT JOIN city ON country.capital_id = city.city_id
LEFT JOIN city city_all ON country.country_id = city_all.country_id
WHERE country.population > 0;

-- 12. Країни, що НЕ мають усіх офіційних мов Швейцарії.
SELECT 
	DISTINCT country.name
FROM country
WHERE NOT EXISTS (
	-- Switzerland official languages.
	SELECT cl_switz.language
    FROM country_language AS cl_switz
    JOIN country AS country_switz 
    USING (country_id)
    WHERE country_switz.name = 'Switzerland' AND cl_switz.is_official = 'T'
    EXCEPT
    SELECT language FROM country_language
    WHERE country_id = country.country_id AND country_language.is_official = 'T'
);