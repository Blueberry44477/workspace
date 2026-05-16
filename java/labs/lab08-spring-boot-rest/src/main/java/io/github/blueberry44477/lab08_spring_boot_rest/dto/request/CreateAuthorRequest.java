package io.github.blueberry44477.lab08_spring_boot_rest.dto.request;

import java.util.List;

import com.fasterxml.jackson.annotation.JsonProperty;

import io.swagger.v3.oas.annotations.media.Schema;
import jakarta.validation.constraints.NotBlank;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@NoArgsConstructor
@Schema(description = "Request object for creating a new author")
public class CreateAuthorRequest {
    @NotBlank(message = "Name must not be blank")
    @Schema(
        example = "Ivan Franko",
        description = "The full name of the author"
    )
    private String name;

    @Schema(
        description = "Biography details", 
        example = "Ukrainian writer, poet, and public figure."
    )
    private String bio;
    
    // @NotNull(message = "Article IDs must not be null")
    @JsonProperty(value = "article_ids")
    @Schema(
        example = "[1, 2, 3]",
        description = "List of associated articles ids"
    )
    private List<Long> articleIds;
}
