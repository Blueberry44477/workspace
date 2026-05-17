package io.github.blueberry44477.lab08_spring_boot_rest.service;

import java.util.List;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.ArticleDto;
import io.github.blueberry44477.lab08_spring_boot_rest.dto.request.CreateArticleRequest;
import io.github.blueberry44477.lab08_spring_boot_rest.exception.EntityNotFoundException;
import io.github.blueberry44477.lab08_spring_boot_rest.mapper.ArticleMapStruct;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Article;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Author;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Keyword;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Topic;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.ArticleRepository;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.AuthorRepository;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.CategoryRepository;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.KeywordRepository;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.TopicRepository;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;

@Slf4j
@Service
@RequiredArgsConstructor
public class ArticleService {
    private final ArticleRepository repository;

    private final CategoryRepository categoryRepository;
    private final TopicRepository topicRepository;
    private final AuthorRepository authorRepository;
    private final KeywordRepository keywordRepository;

    private final ArticleMapStruct articleMapper;

    public Page<ArticleDto> getArticles(@NonNull Pageable pageable) {
        return repository.findAll(pageable).map(articleMapper::toDto);
    }

    @Transactional 
    public ArticleDto addArticle(@NonNull CreateArticleRequest request) {
        Article article = new Article();

        article.setTitle(request.getTitle());
        article.setContent(request.getContent());

        // Set Category
        if (request.getCategoryId() != null) {
            article.setCategory(categoryRepository.getReferenceById(
                request.getCategoryId())
            );
        }

        Article savedArticle = repository.save(article);

        // Set Authors
        if (request.getAuthorIds() != null && !request.getAuthorIds().isEmpty()) {
            List<Author> associatedAuthors = authorRepository.findAllById(request.getAuthorIds());

            if (associatedAuthors.size() != request.getAuthorIds().size())
                throw new EntityNotFoundException(
                    "One or more author IDs provided do not exist.");

            for (Author author : associatedAuthors) {
                author.getArticles().add(article);
                article.getAuthors().add(author);
            }
        }

        // Set Topics
        if (request.getTopicIds() != null && !request.getTopicIds().isEmpty()) {
            List<Topic> associatedTopics = topicRepository.findAllById(request.getTopicIds());

            if (associatedTopics.size() != request.getTopicIds().size())
                throw new EntityNotFoundException(
                    "One or more topic IDs provided do not exist.");

            for (Topic topic : associatedTopics) {
                topic.getArticles().add(article);
                article.getTopics().add(topic);
            }
        }

        // Set Keywords
        if (request.getKeywordIds() != null && !request.getKeywordIds().isEmpty()) {
            List<Keyword> associatedKeywords = keywordRepository.findAllById(request.getKeywordIds());

            if (associatedKeywords.size() != request.getKeywordIds().size())
                throw new EntityNotFoundException(
                    "One or more keyword IDs provided do not exist.");

            for (Keyword keyword : associatedKeywords) {
                keyword.getArticles().add(article);
                article.getKeywords().add(keyword);
            }
        }

        return articleMapper.toDto(savedArticle);
    }
}
