package io.github.blueberry44477.lab08_spring_boot_rest.service;

import java.util.List;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.lang.NonNull;
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

    public Page<CategoryDto> getCategories(@NonNull Pageable pageable) {
        return repository.findAll(pageable).map(categoryMapper::toDto);
    }

    @Transactional
    public CategoryDto addCategory(CategoryDto categoryDto) {
        Category category = categoryMapper.toEntity(categoryDto);
        Category savedCategory = repository.save(category);
        return categoryMapper.toDto(savedCategory);
    }

    @Transactional
    public List<CategoryDto> addCategories(List<CategoryDto> categoryDtoList) {
        List<Category> categoryList = categoryMapper.toEntityList(categoryDtoList);
        List<Category> savedCategories = repository.saveAll(categoryList);
        return categoryMapper.toDtoList(savedCategories);
    }
}
