package io.github.blueberry44477.lab08_spring_boot_rest.mapper;

import java.util.List;

import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.NullValuePropertyMappingStrategy;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.KeywordDto;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Keyword;

@Mapper(
    componentModel = "spring", 
    nullValuePropertyMappingStrategy = NullValuePropertyMappingStrategy.IGNORE
    // uses = {ArticleMapStruct.class}
)
public interface KeywordMapStruct {
    @Mapping(target = "articles", ignore = true)
    KeywordDto toDto(Keyword entity);
    
    List<KeywordDto> toDtoList(List<Keyword> keywords);

    Keyword toEntity(KeywordDto keywordDto);
    List<Keyword> toEntityList(List<KeywordDto> keywordDtoList);
}
