package io.github.blueberry44477.lab08_spring_boot_rest.dto.response;

import java.util.Set;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

import io.swagger.v3.oas.annotations.media.Schema;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.experimental.Accessors;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Accessors(chain = true)
@Schema(description = "Data Transfer Object for Article information")
public class ArticleDto {
    @Schema(example = "101", accessMode = Schema.AccessMode.READ_ONLY)
    private Long id;
    
    @Schema(description = "Article's title", example = "The history of programming")
    private String title;

    @Schema(description = "Article's content")
    private String content;

    @Schema(description = "Article's category")
    private CategoryDto category;

    @Schema(description = "The authors of current article")
    @JsonIgnoreProperties("articles")
    private Set<AuthorDto> authors;

    @Schema(description = "The topics that correspond to current article")
    @JsonIgnoreProperties("articles")
    private Set<TopicDto> topics;

    @Schema(description = "The keywords that article has", 
            example = "programming, JPA")
    @JsonIgnoreProperties("articles")
    private Set<KeywordDto> keywords;
}
