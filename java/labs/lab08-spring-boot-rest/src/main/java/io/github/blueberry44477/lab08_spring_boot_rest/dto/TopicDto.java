package io.github.blueberry44477.lab08_spring_boot_rest.dto;

import java.util.Set;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

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
public class TopicDto {
    private Long id;
    private String title;
    private Boolean isActual;

    @JsonIgnoreProperties("topics")
    private Set<ArticleDto> articles;
}
