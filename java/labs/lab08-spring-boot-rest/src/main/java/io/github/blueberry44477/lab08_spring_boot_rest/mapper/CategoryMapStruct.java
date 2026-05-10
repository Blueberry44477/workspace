package io.github.blueberry44477.lab08_spring_boot_rest.mapper;

import java.util.List;

import org.mapstruct.Mapper;
import org.mapstruct.NullValuePropertyMappingStrategy;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.CategoryDto;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Category;

@Mapper(componentModel = "spring", nullValuePropertyMappingStrategy = NullValuePropertyMappingStrategy.IGNORE)
public interface CategoryMapStruct {
    CategoryDto toDto(Category entity);
    List<CategoryDto> toDtoList(List<Category> categories);

    Category toEntity(CategoryDto categoryDto);
    List<Category> toEntityList(List<CategoryDto> categoryDtoList);
}
