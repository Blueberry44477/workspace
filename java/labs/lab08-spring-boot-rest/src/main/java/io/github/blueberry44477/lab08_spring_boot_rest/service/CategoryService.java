package io.github.blueberry44477.lab08_spring_boot_rest.service;

import java.util.List;

import org.springframework.stereotype.Service;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.CategoryDto;
import io.github.blueberry44477.lab08_spring_boot_rest.dto.CategoryDto;
import io.github.blueberry44477.lab08_spring_boot_rest.mapper.CategoryMapStruct;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Category;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Category;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.CategoryRepository;
import jakarta.transaction.Transactional;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;

@Slf4j
@Service
@RequiredArgsConstructor
public class CategoryService {
    private final CategoryRepository repository;
    private final CategoryMapStruct categoryMapper;

    public List<CategoryDto> getCategories() {
        return categoryMapper.toDtoList(repository.findAll());
    }

    @Transactional
    public CategoryDto addCategory(CategoryDto categoryDto) {
        Category Category = categoryMapper.toEntity(categoryDto);
        Category savedCategory = repository.save(Category);
        return categoryMapper.toDto(savedCategory);
    }

    @Transactional
    public List<CategoryDto> addCategories(List<CategoryDto> categoryDtoList) {
        List<Category> categoryList = categoryMapper.toEntityList(categoryDtoList);
        List<Category> savedCategories = repository.saveAll(categoryList);
        return categoryMapper.toDtoList(savedCategories);
    }
}
