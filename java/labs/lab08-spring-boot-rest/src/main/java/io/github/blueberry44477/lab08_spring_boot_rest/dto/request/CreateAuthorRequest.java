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
@Schema(description = "Request object for creating a new author")
public class CreateAuthorRequest {
    @Schema(
        description = "Author's full name",
        example = "Ivan Franko"
    )
    @NotBlank(message = "Name must not be blank")
    private String name;

    @Schema(
        description = "Biography details", 
        example = "Ukrainian writer, poet, and public figure."
    )
    private String bio;
    
    // @NotNull(message = "Article IDs must not be null")
    @JsonProperty(value = "article_ids")
    @Schema(
        description = "List of associated articles IDs",
        example = "[1, 2, 3]"
    )
    private Set<Long> articleIds;
}
