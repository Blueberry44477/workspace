package io.github.blueberry44477.lab08_spring_boot_rest.dto.response;

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
@Schema(description = "Data Transfer Object for article's category information")
public class CategoryDto {
    @Schema(example = "101", accessMode = Schema.AccessMode.READ_ONLY)
    private Long id;

    @Schema(description = "The category's name")
    private String name;

    @Schema(description = "The parent category of the current category")
    private CategoryDto parent;
}
