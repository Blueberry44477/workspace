package io.github.blueberry44477.lab08_spring_boot_rest.mapper;

import java.util.List;

import org.mapstruct.Mapper;
import org.mapstruct.Mapping;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.ArticleDto;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Article;

@Mapper(
    componentModel = "spring",
    uses = {
        // AuthorMapStruct.class,
        CategoryMapStruct.class,
        TopicMapStruct.class,
        KeywordMapStruct.class
    }
)
public interface ArticleMapStruct {
    ArticleDto toDto(Article entity);
    
    @Mapping(target = "category", ignore = true)
    @Mapping(target = "authors", ignore = true)
    @Mapping(target = "keywords", ignore = true)
    @Mapping(target = "topics", ignore = true)
    Article toEntity(ArticleDto articleDto);
    List<ArticleDto> toDtoList(List<Article> articles);
}
