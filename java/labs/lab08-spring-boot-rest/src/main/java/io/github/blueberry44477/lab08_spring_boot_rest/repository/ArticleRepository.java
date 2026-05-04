package io.github.blueberry44477.lab08_spring_boot_rest.repository;

import org.springframework.data.jpa.repository.JpaRepository;

import io.github.blueberry44477.lab08_spring_boot_rest.model.Article;

public interface ArticleRepository extends JpaRepository<Article, Long> {
    
}
