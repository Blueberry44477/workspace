package io.github.blueberry44477.lab08_spring_boot_rest.dto;

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
public class AuthorDto {
    private Long id;

    @NotBlank
    @Size(min = 2, max = 100)
    private String name;
    
    @Size(max = 10000)
    private String bio;
    // private Set<ArticleDto> articles;
}
