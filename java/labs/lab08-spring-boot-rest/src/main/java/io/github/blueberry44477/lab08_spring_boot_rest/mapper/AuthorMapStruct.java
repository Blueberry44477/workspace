package io.github.blueberry44477.lab08_spring_boot_rest.mapper;

import java.util.List;

import org.mapstruct.BeanMapping;
import org.mapstruct.Mapper;
import org.mapstruct.MappingTarget;
import org.mapstruct.NullValuePropertyMappingStrategy;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.AuthorDto;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Author;

@Mapper(componentModel = "spring", nullValuePropertyMappingStrategy = NullValuePropertyMappingStrategy.IGNORE)
public interface AuthorMapStruct {
    AuthorDto toDto(Author entity);
    Author toEntity(AuthorDto authorDto);
    List<AuthorDto> toDtoList(List<Author> authors);

    @BeanMapping(nullValuePropertyMappingStrategy = NullValuePropertyMappingStrategy.IGNORE)
    void updateEntityFromDto(AuthorDto dto, @MappingTarget Author entity);
}
