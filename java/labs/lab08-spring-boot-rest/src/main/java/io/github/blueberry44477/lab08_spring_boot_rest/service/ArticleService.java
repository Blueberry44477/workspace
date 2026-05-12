package io.github.blueberry44477.lab08_spring_boot_rest.service;

import java.util.Set;
import java.util.stream.Collectors;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.ArticleDto;
import io.github.blueberry44477.lab08_spring_boot_rest.mapper.ArticleMapStruct;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Article;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Author;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Category;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Keyword;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Topic;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.ArticleRepository;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.AuthorRepository;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.CategoryRepository;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.KeywordRepository;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.TopicRepository;
import jakarta.transaction.Transactional;
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
    public ArticleDto addArticle(ArticleDto articleDto) {
        Article article = articleMapper.toEntity(articleDto);
        if (articleDto.getCategory() != null && articleDto.getCategory().getId() != null) {
            Category categoryRef = categoryRepository.getReferenceById(articleDto.getCategory().getId());
            article.setCategory(categoryRef);
        }

        if (articleDto.getAuthors() != null) {
            Set<Author> authors = articleDto.getAuthors().stream()
                .map(a -> authorRepository.getReferenceById(a.getId()))
                .collect(Collectors.toSet());
            article.setAuthors(authors);
        }

        if (articleDto.getKeywords() != null) {
            Set<Keyword> keywords = articleDto.getKeywords().stream()
                .map(k -> keywordRepository.getReferenceById(k.getId()))
                .collect(Collectors.toSet());
            article.setKeywords(keywords);
        }

        if (articleDto.getTopics() != null) {
            Set<Topic> topics = articleDto.getTopics().stream()
                .map(t -> topicRepository.getReferenceById(t.getId()))
                .collect(Collectors.toSet());
            article.setTopics(topics);
        }
        Article savedArticle = repository.save(article);
        return articleMapper.toDto(savedArticle);
    }
}
