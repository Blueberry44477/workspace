package io.github.blueberry44477;

import java.util.HashMap;
import java.util.Map;

import redis.clients.jedis.RedisClient;

public class App {
    public static void main(String[] args) {
        RedisClient jedis = RedisClient.create("localhost", 6379);

        // Author
        // HSET author:1 name "blueberry" bio "a berry"
        Map<String, String> author1 = new HashMap<>();
        author1.put("name", "blueberry");
        author1.put("bio", "a berry");
        Long author_result = jedis.hset("author:1", author1);
        System.out.println(author_result);

        Map<String, String> created_author = jedis.hgetAll("author:1");
        System.out.println(created_author);

        // Category
        // HSET category:1 name "Economic" parent_id "null"
        Map<String, String> category1 = new HashMap<>();
        category1.put("title", "Economics");
        category1.put("parent_id", "");
        jedis.hset("category:1", category1);
        System.out.println(jedis.hgetAll("category:1"));

        // Article
        // HSET article:1 title "Market overview 2026" annotation "" author_id "1" category_id "1" created_at "1715530145"
        Map<String, String> article1 = new HashMap<>();
        article1.put("title", "Market overview 2026");
        article1.put("annotation", "");
        article1.put("author_id", "1");
        article1.put("category_id", "1");
        article1.put("created_at", "12/05/2026");
        jedis.hset("article:1", article1);
        System.out.println(jedis.hgetAll("article:1"));

        // Topic
        // HSET topic:1 name "Investions" description "" is_actual "true"
        Map<String, String> topic1 = new HashMap<>();
        topic1.put("title", "Investions");
        topic1.put("description", "");
        topic1.put("is_actual", "1");
        jedis.hset("topic:1", topic1);
        System.out.println(jedis.hgetAll("topic:1"));
        
        // Keyword
        Map<String, String> keyword1 = new HashMap<>();
        keyword1.put("word", "money");
        jedis.hset("keyword:1", keyword1);
        System.out.println(jedis.hgetAll("keyword:1"));

        // Update //
        jedis.hset("author:1", "name", "Taras");

        // Delete //
        // jedis.del("keyword:1");
        
        // Redis Use Cases for Internet Mailing db domain:
        // 1. Push notifications (Pub/Sub): PUBLISH topic:economics "New article: {title}, {link}"
        // 2. Most popular articles (sorted sets): 
        //    - ZINCRBY article_views 1 article:101
        //    - ZREVRANGE article_views 0 4 WITHSCORES

        jedis.close();
    }
}
