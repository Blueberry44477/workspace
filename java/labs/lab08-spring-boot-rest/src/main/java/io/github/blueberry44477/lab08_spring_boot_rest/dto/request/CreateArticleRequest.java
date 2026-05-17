package io.github.blueberry44477.lab08_spring_boot_rest.dto.request;

import java.util.Set;

import com.fasterxml.jackson.annotation.JsonProperty;

import io.swagger.v3.oas.annotations.media.Schema;
import jakarta.validation.constraints.NotBlank;
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
@Schema(description = "Request object for creating a new Article")
public class CreateArticleRequest {
    @Schema(description = "Article's title", example = "The history of programming")
    @NotBlank
    private String title;

    @Schema(description = "Article's content")
    @NotBlank
    private String content;

    @Schema(description = "Article's category", example = "101")
    @JsonProperty(value = "category_id")
    private Long categoryId;

    @Schema(description = "Article's authors", example = "[1, 2, 3]")
    @JsonProperty(value = "author_ids")
    private Set<Long> authorIds;

    @Schema(description = "Article's topics", example = "[1, 2, 3]")
    @JsonProperty(value = "topic_ids")
    private Set<Long> topicIds;

    @Schema(description = "Article's keywords", example = "[1, 2, 3]")
    @JsonProperty(value = "keyword_ids")
    private Set<Long> keywordIds;
}
