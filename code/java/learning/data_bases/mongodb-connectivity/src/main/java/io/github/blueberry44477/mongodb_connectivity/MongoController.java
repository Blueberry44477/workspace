package io.github.blueberry44477.mongodb_connectivity;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class MongoController {
    private final MongoService mongoService;

    public MongoController(MongoService mongoService) {
        this.mongoService = mongoService;
    }

    @GetMapping("/")
    public String index(Model model) {
        model.addAttribute("authors", mongoService.findAllAuthors());
        model.addAttribute("articleTitle", mongoService.getArticleTitle("69df5264fb7ad7aa369eb9cc"));
        model.addAttribute("articlesByCat", mongoService.findArticlesByCategory("69df508cfb7ad7aa369eb9c4"));
        model.addAttribute("authorsArticleCount", mongoService.getAuthorsArticleCount());
        model.addAttribute("authorStats", mongoService.getArticleCountByAuthorName());
        model.addAttribute("planStats", mongoService.getSubscribersPerPlan());
        model.addAttribute("todaySent", mongoService.getMessagesSentToday());
        model.addAttribute("popularity", mongoService.getTopicPopularity());
        return "index";
    }
}