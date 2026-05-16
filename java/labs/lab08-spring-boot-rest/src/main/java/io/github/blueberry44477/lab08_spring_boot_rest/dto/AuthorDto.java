package io.github.blueberry44477.lab08_spring_boot_rest.dto;

import java.util.Set;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

import io.swagger.v3.oas.annotations.media.Schema;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.Size;
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
@Schema(description = "DTO for Author information")
public class AuthorDto {
    @Schema(
        example = "101",
        accessMode = Schema.AccessMode.READ_ONLY
    )
    private Long id;


    @Schema(description = "Author's name", example = "Taras Shevchenko")
    @NotBlank
    @Size(min = 2, max = 100)
    private String name;
    
    @Schema(description = "Author's biography")
    @Size(max = 10000)
    private String bio;
    
    @Schema(description = "Articles written by author")
    @JsonIgnoreProperties("authors")
    private Set<ArticleDto> articles;
}
