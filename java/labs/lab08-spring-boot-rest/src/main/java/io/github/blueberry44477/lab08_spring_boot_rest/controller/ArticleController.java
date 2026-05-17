package io.github.blueberry44477.lab08_spring_boot_rest.controller;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.request.CreateArticleRequest;
import io.github.blueberry44477.lab08_spring_boot_rest.dto.request.CreateAuthorRequest;
import io.github.blueberry44477.lab08_spring_boot_rest.dto.response.ArticleDto;
import io.github.blueberry44477.lab08_spring_boot_rest.dto.response.AuthorDto;
import io.github.blueberry44477.lab08_spring_boot_rest.service.ArticleService;
import io.swagger.v3.oas.annotations.Operation;
import io.swagger.v3.oas.annotations.media.ArraySchema;
import io.swagger.v3.oas.annotations.media.Content;
import io.swagger.v3.oas.annotations.media.Schema;
import io.swagger.v3.oas.annotations.responses.ApiResponse;
import io.swagger.v3.oas.annotations.tags.Tag;
import lombok.RequiredArgsConstructor;

import org.springdoc.core.annotations.ParameterObject;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.web.PageableDefault;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.lang.NonNull;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;

@Tag(name = "Article",
     description = "Controller to manipulate all entities related to articles")
@RestController
@RequestMapping("api/v1/article")
@RequiredArgsConstructor
public class ArticleController {
    private final ArticleService service;

    @Operation(
        summary = "Retrieve article page",
        description = "",
        responses = {
            @ApiResponse(
                responseCode = "200",
                description = "Successfully retrieved the list of authors",
                content = @Content(array = @ArraySchema(schema = @Schema(implementation = ArticleDto.class)))
            )
        }
    )
    @GetMapping
    public Page<ArticleDto> getArticles(
        @ParameterObject @PageableDefault(page = 0, size = 10, sort = "id")
        @NonNull Pageable pageable
    ) {
        return service.getArticles(pageable);
    }

    @Operation(
        summary = "Create a new article",
        responses = {
            @ApiResponse(
                responseCode = "201",
                description = "Article created successfully",
                content = @Content(schema = @Schema(implementation = ArticleDto.class))
            ),
            @ApiResponse(
                responseCode = "400", 
                description = "Invalid input data provided", 
                content = @Content
            )
        }
    )
    @PostMapping(consumes = MediaType.APPLICATION_JSON_VALUE)
    public ResponseEntity<ArticleDto> addArticle(
        @io.swagger.v3.oas.annotations.parameters.RequestBody(
            description = "Article's information",
            required = true,
            content = @Content(schema = @Schema(implementation = CreateArticleRequest.class))
        )
        @RequestBody CreateArticleRequest request
    ) {
        return ResponseEntity.status(HttpStatus.CREATED).body(service.addArticle(request));
    }
    
}
