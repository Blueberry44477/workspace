package io.github.blueberry44477.lab08_spring_boot_rest.dto;

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
public class CategoryDto {
    private Long id;
    private String name;
    private CategoryDto parent;
}
