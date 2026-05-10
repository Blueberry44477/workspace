package io.github.blueberry44477.lab08_spring_boot_rest.repository;

import java.util.List;

import org.springframework.data.jpa.repository.EntityGraph;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.lang.NonNull;

import io.github.blueberry44477.lab08_spring_boot_rest.model.Article;

public interface ArticleRepository extends JpaRepository<Article, Long> {
    @NonNull
    @EntityGraph(attributePaths = {
        "authors",
        "category",
        "topics",
        "keywords"
    })
    List<Article> findAll();
}
