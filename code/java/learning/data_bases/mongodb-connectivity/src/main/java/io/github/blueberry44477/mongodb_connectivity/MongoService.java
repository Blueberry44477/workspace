package io.github.blueberry44477.mongodb_connectivity;

import com.mongodb.client.*;
import com.mongodb.client.model.*;
import org.bson.Document;
import org.bson.conversions.Bson;
import org.bson.types.ObjectId;
import org.springframework.stereotype.Service;

import java.io.InputStream;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.util.*;

import static com.mongodb.client.model.Filters.*;
import static com.mongodb.client.model.Accumulators.*;
import static com.mongodb.client.model.Aggregates.*;
import static com.mongodb.client.model.Sorts.*;

@Service
public class MongoService {
    private static final String propertiesFilename = "db.properties";
    private static final Properties properties = new Properties();
    private final MongoDatabase database;

    static {
        loadProperties();
    }

    private static void loadProperties() {
        // Search from the project root (instead of relative search like "new FileInputStream(filename)")
        try (InputStream input = MongoService.class.getClassLoader().getResourceAsStream(propertiesFilename)) {
            properties.load(input);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public MongoService() {
        MongoClient mongoClient = MongoClients.create(properties.getProperty("db.url"));
        this.database = mongoClient.getDatabase("internetMailing");
    }

    public List<Document> findAllAuthors() {
        return database.getCollection("authors").find().into(new ArrayList<>());
    }

    public String getArticleTitle(String id) {
        Document article = database.getCollection("articles")
            .find(eq("_id", new ObjectId(id)))
            .first();

        if (article != null) {
            return article.getString("title");
        }
        
        return "Title not found";
    }

    public List<Document> findArticlesByCategory(String id) {
        return database.getCollection("articles")
            .find(eq("category.$id", new ObjectId(id)))
            .into(new ArrayList<>());
    }

    public List<Document> findQueuedMessages(int subscriberId) {
        return database.getCollection("messages")
                .find(and(eq("subscriber.$id", subscriberId), eq("status", "в черзі")))
                .into(new ArrayList<>());
    }

    public List<Document> getAuthorsArticleCount() {
    return database.getCollection("articles").aggregate(Arrays.asList(
        group("$author.$id", Accumulators.sum("articleCount", 1)),
        lookup("authors", "_id", "_id", "authorDetails"),
        unwind("$authorDetails"),
        project(Projections.fields(
            Projections.excludeId(),
            Projections.computed("authorId", "$_id"),
            Projections.computed("name", "$authorDetails.name"), 
            Projections.include("articleCount")
        ))
    )).into(new ArrayList<>());
}

    public long deleteInactiveTopics() {
        return database.getCollection("topics").deleteMany(eq("is_actual", false)).getDeletedCount();
    }

    public long deleteOldSentMessages() {
        Date cutoff = Date.from(LocalDateTime.parse("2026-04-01T00:00:00")
                .atZone(ZoneId.of("UTC")).toInstant());
        return database.getCollection("messages")
                .deleteMany(and(eq("status", "відправлено"), lt("sent_at", cutoff)))
                .getDeletedCount();
    }

    public List<Document> getSubscribersPerPlan() {
        return database.getCollection("subscribers")
            .aggregate(Arrays.asList(
                group("$plan", sum("count", 1))
        )).into(new ArrayList<>());
    }

    public Document getMessagesSentToday() {
        Date start = Date.from(LocalDateTime.parse("2026-04-22T00:00:00").atZone(ZoneId.of("UTC")).toInstant());
        Date end = Date.from(LocalDateTime.parse("2026-04-23T00:00:00").atZone(ZoneId.of("UTC")).toInstant());
        
        return database.getCollection("messages").aggregate(Arrays.asList(
                match(and(gte("sent_at", start), lt("sent_at", end), eq("status", "sent"))),
                count("messages_sent_today")
        )).first();
    }

    public List<Document> getTopicPopularity() {
        return database.getCollection("subscriber_topics").aggregate(Arrays.asList(
                group("$topic", sum("subscriberCount", 1)),
                sort(descending("subscriberCount"))
        )).into(new ArrayList<>());
    }
}