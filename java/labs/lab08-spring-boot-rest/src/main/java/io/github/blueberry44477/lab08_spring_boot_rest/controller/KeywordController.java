package io.github.blueberry44477.lab08_spring_boot_rest.controller;

import java.util.List;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.KeywordDto;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Keyword;
import io.github.blueberry44477.lab08_spring_boot_rest.service.KeywordService;
import lombok.RequiredArgsConstructor;

@RestController
@RequestMapping("api/v1/keyword")
@RequiredArgsConstructor
public class KeywordController {
    private final KeywordService service;

    @GetMapping
    public List<KeywordDto> getKeywords() {
        return service.getKeywords();
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
