CREATE DATABASE countries;
USE countries;
CREATE TABLE country (
	country_id INT PRIMARY KEY,
    name CHAR(60),
    capital CHAR(50),
    continent CHAR(60),
    region CHAR(50),
    surface_area DECIMAL(10,2),
    indept_year SMALLINT,
    population INT,
    life_expectancy DECIMAL(3,1),
	gdp DECIMAL(10,2),
    local_name CHAR(50),
    government_form CHAR(60),
    political_system CHAR(60),
    gold_currency_reserve DECIMAL(10,2),
    code_iso CHAR(2)
);

SELECT * FROM country;

INSERT INTO country
VALUES 
-- Європа
(1, 'Ukraine', 'Kyiv', 'Europe', 'Eastern Europe', 603628.00, 1991, 38000000, 71.3, 4835.00, 'Україна', 'Republic', 'Unitary State', 28500.00, 'UA'),
(2, 'France', 'Paris', 'Europe', 'Western Europe', 551695.00, 843, 67500000, 82.5, 43500.00, 'France', 'Republic', 'Unitary State', 240000.00, 'FR'),

-- Азія
(3, 'Japan', 'Tokyo', 'Asia', 'Eastern Asia', 377975.00, -660, 125800000, 84.6, 39000.00, 'Nippon', 'Constitutional Monarchy', 'Unitary State', 1300000.00, 'JP'),
(4, 'India', 'New Delhi', 'Asia', 'Southern Asia', 3287263.00, 1947, 1400000000, 69.7, 2200.00, 'Bharat', 'Federal Republic', 'Federation', 600000.00, 'IN'),

-- Африка
(5, 'Egypt', 'Cairo', 'Africa', 'Northern Africa', 1001450.00, 1922, 104000000, 72.0, 3600.00, 'Misr', 'Republic', 'Unitary State', 40000.00, 'EG'),
(6, 'South Africa', 'Pretoria', 'Africa', 'Southern Africa', 1221037.00, 1910, 60000000, 64.1, 6700.00, 'South Africa', 'Republic', 'Federation', 55000.00, 'ZA'),

-- Північна Америка
(7, 'Canada', 'Ottawa', 'North America', 'North America', 9984670.00, 1867, 38000000, 82.3, 52000.00, 'Canada', 'Constitutional Monarchy', 'Federation', 100000.00, 'CA'),
(8, 'Mexico', 'Mexico City', 'North America', 'Central America', 1964375.00, 1821, 128000000, 75.0, 10000.00, 'México', 'Federal Republic', 'Federation', 200000.00, 'MX'),

-- Південна Америка
(9, 'Brazil', 'Brasília', 'South America', 'South America', 8515767.00, 1822, 214000000, 75.9, 7500.00, 'Brasil', 'Federal Republic', 'Federation', 350000.00, 'BR'),
(10, 'Argentina', 'Buenos Aires', 'South America', 'South America', 2780400.00, 1816, 45000000, 76.7, 10000.00, 'Argentina', 'Federal Republic', 'Federation', 40000.00, 'AR'),

-- Океанія
(11, 'Australia', 'Canberra', 'Oceania', 'Australia and New Zealand', 7692024.00, 1901, 25700000, 82.9, 55000.00, 'Australia', 'Constitutional Monarchy', 'Federation', 60000.00, 'AU'),
(12, 'New Zealand', 'Wellington', 'Oceania', 'Australia and New Zealand', 268021.00, 1907, 5100000, 82.1, 48000.00, 'Aotearoa', 'Constitutional Monarchy', 'Unitary State', 18000.00, 'NZ');

INSERT INTO country VALUES 
-- Європа (3 країни)
(13, 'Germany', 'Berlin', 'Europe', 'Western Europe', 357022.00, 1955, 83200000, 81.3, 46000.00, 'Deutschland', 'Federal Republic', 'Federation', 290000.00, 'DE'),
(14, 'Italy', 'Rome', 'Europe', 'Southern Europe', 301340.00, 1861, 59000000, 83.5, 35000.00, 'Italia', 'Republic', 'Unitary State', 210000.00, 'IT'),
(15, 'Poland', 'Warsaw', 'Europe', 'Eastern Europe', 312685.00, 1918, 37800000, 78.7, 17000.00, 'Polska', 'Republic', 'Unitary State', 160000.00, 'PL'),

-- Азія (3 країни)
(16, 'South Korea', 'Seoul', 'Asia', 'Eastern Asia', 100210.00, 1948, 51700000, 83.3, 32000.00, 'Daehan Minguk', 'Republic', 'Unitary State', 460000.00, 'KR'),
(17, 'Turkey', 'Ankara', 'Asia', 'Middle East', 783562.00, 1923, 85000000, 77.7, 9500.00, 'Türkiye', 'Republic', 'Unitary State', 110000.00, 'TR'),
(18, 'Vietnam', 'Hanoi', 'Asia', 'Southeast Asia', 331212.00, 1945, 98000000, 75.4, 3700.00, 'Việt Nam', 'Socialist Republic', 'Unitary State', 105000.00, 'VN'),

-- Африка (3 країни)
(19, 'Nigeria', 'Abuja', 'Africa', 'Western Africa', 923768.00, 1960, 211000000, 54.7, 2100.00, 'Nigeria', 'Federal Republic', 'Federation', 35000.00, 'NG'),
(20, 'Morocco', 'Rabat', 'Africa', 'Northern Africa', 446550.00, 1956, 37000000, 76.7, 3400.00, 'Al-Maghrib', 'Constitutional Monarchy', 'Unitary State', 32000.00, 'MA'),
(21, 'Kenya', 'Nairobi', 'Africa', 'Eastern Africa', 580367.00, 1963, 55000000, 66.7, 2100.00, 'Kenya', 'Republic', 'Unitary State', 8000.00, 'KE'),

-- Америка (Північна та Південна - 4 країни)
(22, 'USA', 'Washington D.C.', 'North America', 'North America', 9833517.00, 1776, 331000000, 78.8, 69000.00, 'United States', 'Federal Republic', 'Federation', 500000.00, 'US'),
(23, 'Chile', 'Santiago', 'South America', 'South America', 756102.00, 1810, 19200000, 80.2, 16000.00, 'Chile', 'Republic', 'Unitary State', 50000.00, 'CL'),
(24, 'Colombia', 'Bogotá', 'South America', 'South America', 1141748.00, 1810, 51000000, 77.3, 6100.00, 'Colombia', 'Republic', 'Unitary State', 58000.00, 'CO'),
(25, 'Cuba', 'Havana', 'North America', 'Caribbean', 109884.00, 1902, 11300000, 78.8, 9500.00, 'Cuba', 'Socialist Republic', 'Unitary State', 12000.00, 'CU'),

-- Океанія (2 країни)
(26, 'Fiji', 'Suva', 'Oceania', 'Melanesia', 18274.00, 1970, 900000, 67.4, 5000.00, 'Viti', 'Republic', 'Unitary State', 1000.00, 'FJ'),
(27, 'Papua New Guinea', 'Port Moresby', 'Oceania', 'Melanesia', 462840.00, 1975, 9000000, 64.5, 2700.00, 'Papua Niugini', 'Constitutional Monarchy', 'Unitary State', 2500.00, 'PG');

-- 1.
SELECT * FROM country WHERE continent in ('Europe', 'Africa');
-- OR
SELECT * FROM country WHERE continent = 'Europe' OR continent = 'Africa';

-- 2.
SELECT 
	name AS 'country_name',
    continent AS 'country_continent',
    life_expectancy AS 'country_life_expectancy'
FROM country
WHERE life_expectancy BETWEEN 80 AND 89;

-- 3.
SELECT * FROM country
WHERE government_form LIKE '%Parliamentary%' OR
	  government_form LIKE '%Presidental%';

-- 4.
SELECT 
	continent,
    COUNT(*) as 'count'
FROM country WHERE continent IN ('Europe', 'Africa') GROUP BY continent;

-- 5.
SELECT
	continent,
    AVG(population / surface_area) AS 'average_population_per_km_2'
FROM country WHERE continent in ('Europe', 'Africa') GROUP BY continent;

-- 6.
SELECT
	region,
    AVG(life_expectancy) AS 'average_life_expectancy'
FROM country 
GROUP BY region 
ORDER BY AVG(life_expectancy) DESC;

-- 7.
SELECT
	name, continent, gold_currency_reserve
FROM country
WHERE gold_currency_reserve < (
	SELECT AVG(gold_currency_reserve)
    FROM country
    where continent LIKE '%America%'
);

-- 8.
SELECT
	name, continent, life_expectancy
FROM country
WHERE continent IN ('Europe', 'Africa') AND
	life_expectancy < (
		SELECT AVG(life_expectancy)
        FROM country
        WHERE continent = 'Asia'
	)
ORDER BY life_expectancy ASC;
	