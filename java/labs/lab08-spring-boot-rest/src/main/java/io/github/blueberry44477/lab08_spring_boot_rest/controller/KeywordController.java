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

import io.github.blueberry44477.lab08_spring_boot_rest.dto.KeywordDto;
import io.github.blueberry44477.lab08_spring_boot_rest.service.KeywordService;
import lombok.RequiredArgsConstructor;

@RestController
@RequiredArgsConstructor
@RequestMapping("api/v1/keyword")
public class KeywordController {
    private final KeywordService service;

    @GetMapping
    public Page<KeywordDto> getKeywords(@NonNull Pageable pageable) {
        return service.getKeywords(pageable);
    }

    @PostMapping
    public ResponseEntity<KeywordDto> addKeyword(@RequestBody KeywordDto keywordDto) {
        return new ResponseEntity<>(service.addKeyword(keywordDto), HttpStatus.CREATED);
    }

    @PostMapping("/batch")
    public ResponseEntity<List<KeywordDto>> addKeywords(
        @RequestBody List<KeywordDto> keywordDtoList
    ) {
        return new ResponseEntity<>(service.addKeywords(keywordDtoList), HttpStatus.CREATED);
    }
}
