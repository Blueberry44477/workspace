USE internetMailing;

INSERT INTO author (name)
VALUES
  ("Hu Herrera"),
  ("Cheryl Cash"),
  ("Zane Paul"),
  ("Georgia O'brien"),
  ("Helen Riggs"),
  ("Laurel Gutierrez"),
  ("Sopoline Maynard"),
  ("Abraham Doyle"),
  ("Carson Kirkland"),
  ("Sybil Robles"),
  ("Burke Patrick"),
  ("Walter Ratliff"),
  ("Clarke Berry"),
  ("Erich Roach"),
  ("Malachi Rich");
  
-- SELECT * FROM author;

INSERT INTO category (name, parent_id) VALUES 
-- Level 1: Root Categories (parent_id = NULL)
('Marketing & Sales', NULL),        -- id: 1
('Technical Infrastructure', NULL),  -- id: 2
('Design & Content', NULL),         -- id: 3
('Analytics & Reporting', NULL);    -- id: 4

-- Level 2: Subcategories for "Marketing & Sales" (parent_id = 1)
INSERT INTO category (name, parent_id) VALUES 
('Email Marketing', 1),             -- id: 5
('Social Media Mailing', 1),        -- id: 6
('Funnel Automation', 1);           -- id: 7

-- Level 2: Subcategories for "Technical Infrastructure" (parent_id = 2)
INSERT INTO category (name, parent_id) VALUES 
('SMTP Settings', 2),               -- id: 8
('API Integrations', 2),            -- id: 9
('List Cleaning & Validation', 2);  -- id: 10

-- Level 2: Subcategories for "Design & Content" (parent_id = 3)
INSERT INTO category (name, parent_id) VALUES 
('HTML Templates', 3),              -- id: 11
('Copywriting', 3),                 -- id: 12
('Responsive Layouts', 3);          -- id: 13

-- Level 3: Deep Nesting for "Email Marketing" (parent_id = 5)
INSERT INTO category (name, parent_id) VALUES 
('Cold Outreach', 5),               -- id: 14
('Trigger-based Emails', 5);        -- id: 15

SELECT * FROM category;

INSERT INTO article (title, annotation, author_id, category_id, created_at) VALUES 
-- Marketing & Sales Articles
('10 Secrets of High-Converting Cold Emails', 'Learn how to write cold outreach letters that actually get replies from busy CEOs.', 1, 14, '09:15:00'),
('Automating Your First Sales Funnel', 'A step-by-step guide to setting up automated sequences for new subscribers.', 2, 7, '10:30:45'),
('The Future of Social Media Newsletters', 'How to combine email marketing with social media strategy for better reach.', 3, 6, '14:20:00'),

-- Technical Infrastructure Articles
('Why Your Emails Go to Spam (and How to Fix It)', 'A deep dive into SMTP settings, SPF, and DKIM records for better deliverability.', 5, 8, '08:00:12'),
('Building a Custom Integration with our API', 'Technical documentation and best practices for connecting your CRM via REST API.', 14, 9, '11:45:30'),
('The Importance of Regular List Cleaning', 'How to remove inactive subscribers and bounce-backs to protect your sender reputation.', 10, 10, '16:10:00'),

-- Design & Content Articles
('Writing Subject Lines That Get Opened', 'Psychological triggers and copywriting formulas for effective email headers.', 12, 12, '13:05:00'),
('Dark Mode in Email: A Design Guide', 'Best practices for creating HTML templates that look great in both light and dark modes.', 7, 11, '15:50:22'),
('Mastering Responsive Layouts for Mobile', 'Why 60% of users read emails on mobile and how to ensure your design is ready.', 6, 13, '17:30:00'),

-- Analytics & Deep Nesting Articles
('Interpreting Your Campaign Analytics', 'Moving beyond Open Rates to understand the true ROI of your mailing efforts.', 15, 4, '09:45:10'),
('Triggered vs. Broadcast: When to use which?', 'Analyzing the performance difference between scheduled newsletters and user-action triggers.', 8, 15, '12:00:00'),
('Scaling Your Outreach without Burning Your Domain', 'Strategies for managing high-volume cold outreach safely.', 4, 14, '11:20:00');

SELECT * FROM article;

INSERT INTO topic (name, description, is_actual) VALUES
('Artificial Intelligence', 'Developments in machine learning and neural networks.', TRUE),
('Blockchain', 'Distributed ledger technology and cryptocurrency.', TRUE),
('Climate Change', 'Environmental shifts and sustainability efforts.', TRUE),
('Cybersecurity', 'Protecting systems and networks from digital attacks.', TRUE),
('Space Exploration', 'Humanity’s journey to Mars and beyond.', TRUE),
('Quantum Computing', 'Next-generation processing using quantum bits.', TRUE),
('Renewable Energy', 'Solar, wind, and hydro-electric power news.', TRUE),
('Global Economics', 'Trends in international markets and trade.', TRUE),
('Healthcare Tech', 'Innovation in medical devices and software.', TRUE),
('Autonomous Vehicles', 'Self-driving cars and transit systems.', TRUE),
('Virtual Reality', 'Immersive digital environments.', FALSE),
('E-commerce', 'Online retail and consumer behavior.', TRUE),
('Genetics', 'Advances in DNA sequencing and CRISPR.', TRUE),
('Robotics', 'Industrial and personal robot automation.', TRUE),
('Edge Computing', 'Data processing at the edge of the network.', TRUE);

INSERT INTO keyword (word) VALUES
('Technology'), ('Innovation'), ('Future'), ('Data'), ('Privacy'),
('Security'), ('Efficiency'), ('Growth'), ('Medicine'), ('Mars'),
('Ethereum'), ('Green'), ('Automation'), ('Cloud'), ('Digital');

INSERT INTO subscription_plan (name, daily_limit) VALUES
('Free Tier', 3),
('Basic Monthly', 10),
('Basic Yearly', 10),
('Standard', 25),
('Pro Monthly', 50),
('Pro Yearly', 50),
('Premium', 100),
('Enterprise Lite', 250),
('Enterprise Pro', 500),
('Academic', 15),
('Non-Profit', 20),
('Developer', 75),
('VIP', 1000),
('Trial', 5),
('Unlimited', 9999);

INSERT INTO subscriber (name, plan_id, format_pref) VALUES
('Alice Smith', 1, 'HTML'),
('Bob Johnson', 5, 'Plain Text'),
('Charlie Brown', 7, 'PDF'),
('David Wilson', 2, 'HTML'),
('Eve Adams', 9, 'HTML'),
('Frank Miller', 4, 'Plain Text'),
('Grace Lee', 13, 'Markdown'),
('Heidi Klum', 1, 'HTML'),
('Ivan Drago', 6, 'PDF'),
('Judy Hopps', 10, 'HTML'),
('Kevin Hart', 15, 'HTML'),
('Laura Palmer', 3, 'Markdown'),
('Mallory Knox', 8, 'Plain Text'),
('Niaj Singh', 12, 'HTML'),
('Oscar Isaac', 14, 'HTML');

INSERT INTO article_topic (article_id, topic_id) VALUES
(1, 1), (2, 2), (3, 5), (4, 4), (5, 7),
(6, 6), (7, 8), (8, 9), (9, 11), (10, 13),
(11, 10), (12, 12);

INSERT INTO article_keyword (article_id, keyword_id) VALUES
(1, 1), (1, 2), (2, 11), (3, 10), (4, 6),
(5, 12), (6, 2), (7, 8), (8, 9), (9, 15),
(10, 9), (11, 13), (12, 15);

INSERT INTO subscriber_topic (subscriber_id, topic_id) VALUES
(1, 1), (1, 4), (2, 2), (3, 5), (4, 7),
(5, 8), (6, 9), (7, 1), (8, 3), (9, 6),
(10, 13), (11, 15), (12, 10), (13, 12), (14, 14);

INSERT INTO subscriber_keyword (subscriber_id, keyword_id) VALUES
(1, 1), (2, 11), (3, 10), (4, 12), (5, 8),
(6, 9), (7, 2), (8, 3), (9, 6), (10, 9),
(11, 4), (12, 13), (13, 15), (14, 7), (15, 5);

INSERT INTO message (subscriber_id, article_id, sent_at, status) VALUES
(1, 1, '2026-03-31 08:05:00', 1),
(2, 2, '2026-03-31 09:20:00', 1),
(3, 3, '2026-03-31 10:35:00', 1),
(4, 5, '2026-03-31 12:50:00', 1),
(5, 7, '2026-03-31 14:15:00', 0),
(6, 8, '2026-03-31 16:00:00', 1),
(7, 1, '2026-03-31 08:10:00', 1),
(8, 3, '2026-03-31 10:40:00', 1),
(9, 6, '2026-03-31 13:30:00', 0),
(10, 10, '2026-03-31 17:40:00', 1),
(11, 11, '2026-03-31 22:45:00', 1),
(12, 11, '2026-03-31 18:50:00', 1);


DELETE FROM message;
DELETE FROM subscriber_keyword;
DELETE FROM subscriber_topic;
DELETE FROM article_keyword;
DELETE FROM article_topic;
DELETE FROM article;
DELETE FROM subscriber;
DELETE FROM author;
DELETE FROM category;
DELETE FROM topic;
DELETE FROM keyword;
DELETE FROM subscription_plan;

-- 2.2
DELETE FROM author 
WHERE bio IS NULL OR bio = '';

DELETE FROM category 
WHERE parent_id = 5;

DELETE FROM keyword 
WHERE LENGTH(word) < 3;

DELETE FROM subscription_plan 
WHERE daily_limit < (SELECT AVG(daily_limit) FROM (SELECT daily_limit FROM subscription_plan) AS temp);

DELETE FROM subscriber 
WHERE format_pref = 'Plain Text';

DELETE FROM article 
WHERE created_at < '09:00:00';

DELETE FROM message 
WHERE sent_at < '2026-01-01 00:00:00' AND status = 1;

-- 3

-- Client info
SELECT s.subscriber_id, s.name, s.format_pref, sp.name AS plan_name, sp.daily_limit
FROM subscriber s
JOIN subscription_plan sp ON s.plan_id = sp.subscription_plan_id;

-- 2. Знайти клієнта з найбільшою кількістю підключень до розсилки.
SELECT name 
FROM subscriber 
WHERE subscriber_id = (
    SELECT subscriber_id 
    FROM subscriber_topic 
    GROUP BY subscriber_id 
    ORDER BY COUNT(*) DESC 
    LIMIT 1
);

-- 3. Знайти найпопулярнішу рубрику.
SELECT t.name, COUNT(st.subscriber_id) AS subscriber_count
FROM topic t
JOIN subscriber_topic st ON t.topic_id = st.topic_id
GROUP BY t.topic_id, t.name
ORDER BY subscriber_count DESC
LIMIT 1;

-- 4.
-- topics that have subscriber less than average.
SELECT t.name, COUNT(st.subscriber_id) AS sub_count
FROM topic t
LEFT JOIN subscriber_topic st ON t.topic_id = st.topic_id
GROUP BY t.topic_id, t.name
HAVING COUNT(st.subscriber_id) < (
    SELECT AVG(counts.cnt) 
    FROM (SELECT COUNT(*) AS cnt FROM subscriber_topic GROUP BY topic_id) AS counts
);

-- 3.1
-- actual topics
SELECT topic_id, name, description 
FROM topic 
WHERE is_actual = TRUE;

SELECT title, created_at 
FROM article 
WHERE created_at BETWEEN '09:00:00' AND '18:00:00';

-- 3.2
SELECT name 
FROM subscriber 
WHERE subscriber_id = (
    SELECT subscriber_id 
    FROM subscriber_topic 
    GROUP BY subscriber_id 
    ORDER BY COUNT(*) DESC 
    LIMIT 1
);

-- titles written by author with name on 'A'
SELECT title 
FROM article 
WHERE author_id IN (
    SELECT author_id 
    FROM author 
    WHERE name LIKE 'A%'
);

-- 3.3
-- Authors names that have more than 2 topics written.
SELECT a.name, COUNT(art.article_id) AS article_count
FROM author a
JOIN article art ON a.author_id = art.author_id
GROUP BY a.author_id, a.name
HAVING COUNT(art.article_id) > 2;