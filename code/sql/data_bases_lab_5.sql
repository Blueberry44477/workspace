USE countries;

-- 1.
CREATE TABLE religion(
	religion_id INT PRIMARY KEY AUTO_INCREMENT,
    name CHAR(50),
    description TEXT
);

-- ALTER TABLE country
-- ADD UNIQUE(code_iso);

-- 2.
CREATE TABLE country_religion(
    country_code CHAR(2), 
    FOREIGN KEY(country_code) REFERENCES country(code_iso),-- ON DELETE RESTRICT ON UPDATE CASCADE,
    
    religion_id INT, 
    FOREIGN KEY(religion_id) REFERENCES religion(religion_id),--  ON DELETE RESTRICT ON UPDATE CASCADE,
    
    PRIMARY KEY(country_code, religion_id),
    percentage DECIMAL(4, 1) CHECK (percentage BETWEEN 0 AND 100)
);

-- SELECT * FROM religion;

-- 3.
INSERT INTO religion(name, description) VALUES
('Christianity', 'Bible'),
('Islam', 'Quran'),
('Hinduism', 'Vedas'),
('Buddhism', 'Tripitaka'),
('Judaism', 'Torah');

-- ALTER TABLE country
-- MODIFY country_id INT NOT NULL AUTO_INCREMENT;
-- ALTER TABLE country ADD capital VARCHAR(20);
-- ALTER TABLE country MODIFY capital VARCHAR(20) AFTER name;

-- ALTER TABLE country_language DROP FOREIGN KEY `1`;
-- ALTER TABLE country_language
-- ADD CONSTRAINT country_id_fk FOREIGN KEY(country_id) REFERENCES country(country_id)
-- ON DELETE SET NULL;

INSERT INTO country (name, capital, continent, region, surface_area, population, code_iso) 
VALUES 
('Turkey', 'Ankara', 'Asia', 'West Asia', 783562.00, 85000000, 'TR'),
('Saudi Arabia', 'Riyadh', 'Asia', 'West Asia', 2149690.00, 36000000, 'SA'),
('United Arab Emirates', 'Abu Dhabi', 'Asia', 'West Asia', 83600.00, 9500000, 'AE'),
('Georgia', 'Tbilisi', 'Asia', 'West Asia', 69700.00, 3700000, 'GE');

-- 4. West Asia
INSERT INTO country_religion (country_code, religion_id, percentage) 
VALUES 
('TR', 2, 99.0), -- Туреччина (Іслам)
('SA', 2, 100.0), -- Саудівська Аравія (Іслам)
('AE', 2, 76.0), -- ОАЕ (Іслам)
('AE', 1, 13.0), -- ОАЕ (Християнство)
('GE', 1, 83.4), -- Грузія (Християнство)
('GE', 2, 10.7); -- Грузія (Іслам)

-- 5.
UPDATE religion 
SET description = 'Vedas and Bhagavad Gita' 
WHERE name = 'Hinduism';

UPDATE country 
SET capital = 'Tbilisi (Republic of Georgia)' 
WHERE code_iso = 'GE';

UPDATE religion 
SET description = 'Abrahamic religion' 
WHERE name IN ('Christianity', 'Islam', 'Judaism');

-- 6.
CREATE INDEX idx_religion_name ON religion(name);
SHOW INDEXES FROM religion;

-- 7.
-- Країни з панівною часткою Ісламу.
SELECT 
    c.name, 
    c.capital, 
    cr.percentage
FROM country c
JOIN country_religion cr ON c.code_iso = cr.country_code
JOIN religion r ON cr.religion_id = r.religion_id
WHERE r.name = 'Islam' AND cr.percentage > 50.0;

-- Домінантна релігія для кожної країни.
SELECT 
    c.name, 
    r.name AS dominant_religion, 
    cr.percentage
FROM country c
JOIN country_religion cr ON c.code_iso = cr.country_code
JOIN religion r ON cr.religion_id = r.religion_id
WHERE cr.percentage = (
    SELECT MAX(percentage) 
    FROM country_religion 
    WHERE country_code = c.code_iso
);

-- країни з "Авраамічними" релігіями
SELECT 
    c.name AS country, 
    c.capital, 
    r.name AS religion, 
    r.description
FROM country c
JOIN country_religion cr ON c.code_iso = cr.country_code
JOIN religion r ON cr.religion_id = r.religion_id
WHERE r.description LIKE '%Bible%' OR r.description LIKE '%Quran%' OR r.description LIKE '%Torah%';

-- 8. Запити на видалення даних.

-- 8-1.
DELETE FROM country_religion
WHERE religion_id = 1;

-- 8-2.
DELETE FROM religion
WHERE religion_id = 1;

-- 8-3
SHOW CREATE TABLE country_religion;

ALTER TABLE country_religion
DROP FOREIGN KEY `2`;

ALTER TABLE country_religion
ADD CONSTRAINT religion_id_fk FOREIGN KEY(religion_id) REFERENCES religion(religion_id)
ON DELETE SET NULL;

-- 9.
TRUNCATE TABLE country_religion;

-- 10. 
DROP TABLE religion;