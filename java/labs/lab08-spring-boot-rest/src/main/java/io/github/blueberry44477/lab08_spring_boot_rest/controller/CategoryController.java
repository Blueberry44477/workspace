package io.github.blueberry44477.lab08_spring_boot_rest.controller;

import java.util.List;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.lang.NonNull;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.CategoryDto;
import io.github.blueberry44477.lab08_spring_boot_rest.service.CategoryService;
import lombok.RequiredArgsConstructor;

@RestController
@RequiredArgsConstructor
@RequestMapping("api/v1/category")
public class CategoryController {
    private final CategoryService service;

    @GetMapping
    public Page<CategoryDto> getCategories(@NonNull Pageable pageable) {
        return service.getCategories(pageable);
    }

    @PostMapping
    public ResponseEntity<CategoryDto> addCategory(@RequestBody CategoryDto categoryDto) {
        return new ResponseEntity<>(service.addCategory(categoryDto), HttpStatus.CREATED);
    }

    @PostMapping("/batch")
    public ResponseEntity<List<CategoryDto>> addCategories(
        @RequestBody List<CategoryDto> categoryDtoList
    ) {
        return new ResponseEntity<>(service.addCategories(categoryDtoList), HttpStatus.CREATED);
    }
}
