CREATE DATABASE internetMailing;
use internetMailing;

CREATE TABLE author(
	author_id INT PRIMARY KEY AUTO_INCREMENT,
	name CHAR(60),
    bio TEXT
);

CREATE TABLE category(
	category_id INT PRIMARY KEY AUTO_INCREMENT,
	name CHAR(60),
    parent_id INT
);

CREATE TABLE topic(
	topic_id INT PRIMARY KEY AUTO_INCREMENT,
    name CHAR(60),
	description TEXT,
    is_actual boolean
);

CREATE TABLE keyword(
	keyword_id INT PRIMARY KEY AUTO_INCREMENT,
    word CHAR(30)
);

CREATE TABLE subscription_plan(
	subscription_plan_id INT PRIMARY KEY AUTO_INCREMENT,
	name CHAR(60),
    daily_limit INT
);

CREATE TABLE subscriber(
	subscriber_id INT PRIMARY KEY AUTO_INCREMENT,
	name CHAR(60),
    plan_id INT, FOREIGN KEY(plan_id) REFERENCES subscription_plan(subscription_plan_id),
    format_pref CHAR(30)
);

CREATE TABLE article(
	article_id INT PRIMARY KEY AUTO_INCREMENT,
    title CHAR(100),
    annotation TEXT,
    author_id INT, FOREIGN KEY(author_id) REFERENCES author(author_id),
    category_id INT, FOREIGN KEY(category_id) REFERENCES category(category_id),
    created_at TIME
);

CREATE TABLE article_topic(
	article_topic_id INT PRIMARY KEY AUTO_INCREMENT,
    article_id INT, FOREIGN KEY(article_id) REFERENCES article(article_id),
    topic_id INT, FOREIGN KEY(topic_id) REFERENCES topic(topic_id)
);

CREATE TABLE article_keyword(
	article_keyword_id INT PRIMARY KEY AUTO_INCREMENT,
    article_id INT, FOREIGN KEY(article_id) REFERENCES article(article_id),
    keyword_id INT, FOREIGN KEY(keyword_id) REFERENCES keyword(keyword_id)
);

CREATE TABLE subscriber_topic(
	subscriber_topic_id INT PRIMARY KEY AUTO_INCREMENT,
    subscriber_id INT, FOREIGN KEY(subscriber_id) REFERENCES subscriber(subscriber_id),
    topic_id INT, FOREIGN KEY(topic_id) REFERENCES topic(topic_id)
);

CREATE TABLE subscriber_keyword(
	subscriber_keyword_id INT PRIMARY KEY AUTO_INCREMENT,
    subscriber_id INT, FOREIGN KEY(subscriber_id) REFERENCES subscriber(subscriber_id),
    keyword_id INT, FOREIGN KEY(keyword_id) REFERENCES keyword(keyword_id)
);

CREATE TABLE message(
	message_id INT PRIMARY KEY AUTO_INCREMENT,
	subscriber_id INT, FOREIGN KEY(subscriber_id) REFERENCES subscriber(subscriber_id),
    article_id INT, FOREIGN KEY(article_id) REFERENCES article(article_id),
    sent_at DATETIME,
    status INT
);

CREATE USER 'developer'@'localhost' IDENTIFIED BY 'password123';
GRANT ALL PRIVILEGES ON internetMailing.* TO 'developer'@'localhost';
FLUSH PRIVILEGES;
