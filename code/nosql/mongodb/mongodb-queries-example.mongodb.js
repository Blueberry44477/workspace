use("internetMailing");

db.authors.find();

db.articles.find({ "category.$id": 1 });

db.messages.find({ 
    "subscriber.$id": 1, 
    "status": "в черзі" 
});

db.topics.deleteMany({ "is_actual": false });

db.messages.deleteMany({ 
    "status": "відправлено", 
    "sent_at": { $lt: new Date("2026-04-01T00:00:00Z") } 
});

// Show author id and his articles count.
db.articles.aggregate([
  {
    $group: {
      _id: "$author",
      totalArticles: { $sum: 1 }
    }
  }
])

// Show author name and his articles count.
db.articles.aggregate([
  {
    // Join
    $lookup: {
      from: "authors",
      localField: "author",
      foreignField: "_id",
      as: "author_details" // array for result
    }
  },
  {
    $unwind: "$author_details"
  },
  {
    // Group by name
    $group: {
      _id: "$author_details.name",
      totalArticles: { $sum: 1 }
    }
  }
])

// Count how many users are assigned to each plan.
db.subscribers.aggregate([
  {
    $group: {
      _id: "$plan",
      count: { $sum: 1 }
    }
  }
])

// Count how many messages were sent today.
db.messages.aggregate([
  {
    $match: {
      sent_at: {
        $gte: ISODate("2026-04-22T00:00:00Z"),
        $lt: ISODate("2026-04-23T00:00:00Z")
      },
      status: "sent"
    }
  },
  {
    $count: "messages_sent_today"
  }
])

// Popularity of Interest Topics.
db.subscriber_topics.aggregate([
  {
    $group: {
      _id: "$topic",
      subscriberCount: { $sum: 1 }
    }
  },
  {
    $sort: { subscriberCount: -1 }
  }
])