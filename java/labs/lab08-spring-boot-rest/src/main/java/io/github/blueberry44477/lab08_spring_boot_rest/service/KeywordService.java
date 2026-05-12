package io.github.blueberry44477.lab08_spring_boot_rest.service;

import java.util.List;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.KeywordDto;
import io.github.blueberry44477.lab08_spring_boot_rest.mapper.KeywordMapStruct;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Keyword;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.KeywordRepository;
import jakarta.transaction.Transactional;
import lombok.RequiredArgsConstructor;

@Service
@RequiredArgsConstructor
public class KeywordService {
    private final KeywordRepository repository;
    private final KeywordMapStruct keywordMapper;

    public Page<KeywordDto> getKeywords(@NonNull Pageable pageable) {
        return repository.findAll(pageable).map(keywordMapper::toDto);
    }

    @Transactional
    public KeywordDto addKeyword(KeywordDto keywordDto) {
        Keyword keyword = keywordMapper.toEntity(keywordDto);
        Keyword savedKeyword = repository.save(keyword);
        return keywordMapper.toDto(savedKeyword);
    }

    @Transactional
    public List<KeywordDto> addKeywords(List<KeywordDto> keywordDtoList) {
        List<Keyword> keywordList = keywordMapper.toEntityList(keywordDtoList);
        List<Keyword> savedKeywords = repository.saveAll(keywordList);
        return keywordMapper.toDtoList(savedKeywords);
    }
}
