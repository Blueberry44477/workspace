-- procedures
use internetMailing;

DELIMITER $$
CREATE PROCEDURE get_authors()
BEGIN
	SELECT * FROM author;
END $$
DELIMITER ;

DELIMITER $$
CREATE PROCEDURE get_author(IN id INT)
BEGIN
	SELECT * FROM author WHERE author_id = id;
END $$
DELIMITER ;

CALL get_author(1);

DELIMITER $$
CREATE PROCEDURE get_author_articles_by_name(IN name VARCHAR(50))
BEGIN
	SELECT 
		author.name, 
        article.title
    FROM author
    JOIN article ON author.author_id = article.author_id
    WHERE author.name = name;
END $$
DELIMITER ;

CALL get_author_articles_by_name("Zane Paul");

-- Functions
DELIMITER $$

CREATE FUNCTION get_author_article_count(p_author_id INT)
RETURNS INT
DETERMINISTIC
READS SQL DATA
BEGIN
	DECLARE total INT;
    SELECT COUNT(*) INTO total
    FROM article
    WHERE author_id = p_author_id;
    RETURN TOTAL;
END $$

DELIMITER ;

SELECT name, get_author_article_count(author_id) AS articles_total FROM author;

-- 2. Check if the user has exceeded the daily messages limit.
DELIMITER $$

CREATE FUNCTION can_send_message(p_subscriber_id INT) 
RETURNS BOOLEAN
DETERMINISTIC
READS SQL DATA
BEGIN
    DECLARE current_count INT;
    DECLARE daily_max INT;
    
    -- Retrieving user's count for the current day.
    SELECT COUNT(*) INTO current_count 
    FROM message 
    WHERE subscriber_id = p_subscriber_id 
    AND DATE(sent_at) = CURDATE();
    
    -- Retrieving daily limit.
    SELECT sp.daily_limit INTO daily_max
    FROM subscriber s
    JOIN subscription_plan sp ON s.plan_id = sp.subscription_plan_id
    WHERE s.subscriber_id = p_subscriber_id;
    
    RETURN current_count < daily_max;
END $$

DELIMITER ;

SELECT can_send_message(5);
    
-- Find out the theme's popularity.
DELIMITER $$

CREATE FUNCTION get_topic_popularity(p_topic_id INT) 
RETURNS VARCHAR(20)
DETERMINISTIC
READS SQL DATA
BEGIN
    DECLARE sub_count INT;
    SELECT COUNT(*) INTO sub_count 
    FROM subscriber_topic 
    WHERE topic_id = p_topic_id;
    
    IF sub_count > 100 THEN
        RETURN 'Trending';
    ELSEIF sub_count > 10 THEN
        RETURN 'Popular';
    ELSE
        RETURN 'Niche';
    END IF;
END $$

DELIMITER ;

SELECT name, get_topic_popularity(topic_id) FROM topic;

CREATE TABLE  log (
    log_id INT AUTO_INCREMENT PRIMARY KEY,
    `table` VARCHAR(50),
    operation VARCHAR(50),
    time DATETIME,
    details TEXT
);

DELIMITER $$

-- 1. BEFORE INSERT: Set time if NULL.
CREATE TRIGGER before_article_insert
BEFORE INSERT ON article
FOR EACH ROW
BEGIN
    IF NEW.created_at IS NULL THEN
        SET NEW.created_at = CURTIME();
    END IF;
END $$

-- 2. AFTER INSERT: Logging.
CREATE TRIGGER after_article_insert
AFTER INSERT ON article
FOR EACH ROW
BEGIN
    INSERT INTO log (`table`, operation, time, details)
    VALUES ('article', 'INSERT', NOW(), CONCAT('New article ID: ', NEW.article_id));
END $$

-- 3. BEFORE UPDATE: Restrict updating the creation date of article.
CREATE TRIGGER before_article_update
BEFORE UPDATE ON article
FOR EACH ROW
BEGIN
    IF OLD.created_at <> NEW.created_at THEN
        SIGNAL SQLSTATE '45000' 
        SET MESSAGE_TEXT = 'Cannot modify creation time of an article';
    END IF;
END $$

-- 4. AFTER UPDATE: Logging
CREATE TRIGGER after_article_update
AFTER UPDATE ON article
FOR EACH ROW
BEGIN
    INSERT INTO log (`table`, operation, time, details)
    VALUES ('article', 'UPDATE', NOW(), CONCAT('Updated article ID: ', NEW.article_id));
END $$

-- 5. BEFORE DELETE: Restrict article deletion if it was created today.
CREATE TRIGGER before_article_delete
BEFORE DELETE ON article
FOR EACH ROW
BEGIN
    IF DATE(OLD.created_at) = CURDATE() THEN
		SIGNAL SQLSTATE '45000' 
        SET MESSAGE_TEXT = 'Cannot delete todays article.';
    END IF;
END $$

-- 6. AFTER DELETE: Deletion logging.
CREATE TRIGGER after_article_delete
AFTER DELETE ON article
FOR EACH ROW
BEGIN
    INSERT INTO log (`table`, operation, time, details)
    VALUES ('article', 'DELETE', NOW(), CONCAT('Deleted article title: ', OLD.title));
END $$

DELIMITER ;

-- Logging
DELIMITER $$

CREATE TRIGGER after_author_update
AFTER UPDATE ON author
FOR EACH ROW
BEGIN
    INSERT INTO log (`table`, operation, time)
    VALUES ('author', 'UPDATE', NOW());
END $$

CREATE TRIGGER after_author_delete
AFTER DELETE ON author
FOR EACH ROW
BEGIN
    INSERT INTO log (`table`, operation, time)
    VALUES ('author', 'DELETE', NOW());
END $$

CREATE TRIGGER after_article_update
AFTER UPDATE ON article
FOR EACH ROW
BEGIN
    INSERT INTO log (`table`, operation, time)
    VALUES ('article', 'UPDATE', NOW());
END $$

CREATE TRIGGER after_article_delete
AFTER DELETE ON article
FOR EACH ROW
BEGIN
    INSERT INTO log (`table`, operation, time)
    VALUES ('article', 'DELETE', NOW());
END $$

CREATE TRIGGER after_subscriber_update
AFTER UPDATE ON subscriber
FOR EACH ROW
BEGIN
    INSERT INTO log (`table`, operation, time)
    VALUES ('subscriber', 'UPDATE', NOW());
END $$

CREATE TRIGGER after_subscriber_delete
AFTER DELETE ON subscriber
FOR EACH ROW
BEGIN
    INSERT INTO log (`table`, operation, time)
    VALUES ('subscriber', 'DELETE', NOW());
END $$

CREATE TRIGGER after_article_topic_update
AFTER UPDATE ON article_topic
FOR EACH ROW
BEGIN
    INSERT INTO log (`table`, operation, time)
    VALUES ('article_topic', 'UPDATE', NOW());
END $$

CREATE TRIGGER after_article_topic_delete
AFTER DELETE ON article_topic
FOR EACH ROW
BEGIN
    INSERT INTO log (`table`, operation, time)
    VALUES ('article_topic', 'DELETE', NOW());
END $$

DELIMITER ;