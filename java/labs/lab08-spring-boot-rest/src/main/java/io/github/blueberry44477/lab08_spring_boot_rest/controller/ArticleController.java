package io.github.blueberry44477.lab08_spring_boot_rest.controller;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.ArticleDto;
import io.github.blueberry44477.lab08_spring_boot_rest.service.ArticleService;

import lombok.RequiredArgsConstructor;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.lang.NonNull;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;

@RestController
@RequestMapping("api/v1/article")
@RequiredArgsConstructor
public class ArticleController {
    private final ArticleService service;

    @GetMapping
    public Page<ArticleDto> getArticles(@NonNull Pageable pageable) {
        return service.getArticles(pageable);
    }

    @PostMapping
    public ResponseEntity<ArticleDto> addArticle(@RequestBody ArticleDto articleDto) {
        ArticleDto createdArticle = service.addArticle(articleDto);
        return new ResponseEntity<>(createdArticle, HttpStatus.CREATED);
    }
    
}
