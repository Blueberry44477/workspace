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
@Schema(description = "Data Transfer Object for keyword information")
public class KeywordDto {
    @Schema(example = "101", accessMode = Schema.AccessMode.READ_ONLY)
    private Long id;

    @Schema(description = "The keyword", example = "programming")
    private String word;

    @Schema(description = "The articles, which have this keyword")
    @JsonIgnoreProperties("keywords")
    private Set<ArticleDto> articles;
}
