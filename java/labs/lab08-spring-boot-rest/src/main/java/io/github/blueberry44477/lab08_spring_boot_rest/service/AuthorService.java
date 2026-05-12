package io.github.blueberry44477.lab08_spring_boot_rest.service;

import java.util.List;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.AuthorDto;
import io.github.blueberry44477.lab08_spring_boot_rest.dto.CategoryDto;
import io.github.blueberry44477.lab08_spring_boot_rest.exception.EntityNotFoundException;
import io.github.blueberry44477.lab08_spring_boot_rest.mapper.AuthorMapStruct;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Author;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.AuthorRepository;
import jakarta.transaction.Transactional;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;

@Slf4j
@Service
@RequiredArgsConstructor
public class AuthorService {
    private final AuthorRepository repository;
    private final AuthorMapStruct authorMapper;

    public Page<AuthorDto> getAuthors(@NonNull Pageable pageable) {
        return repository.findAll(pageable).map(authorMapper::toDto);
    }

    public AuthorDto getAuthorById(Long id) {
        return repository.findById(id)
                         .map(authorMapper::toDto)
                         .orElseThrow(() -> new EntityNotFoundException("Author not found with id: " + id));
    }

    @Transactional
    public AuthorDto addAuthor(AuthorDto authorDto) {
        Author author = authorMapper.toEntity(authorDto);
        Author savedAuthor = repository.save(author);
        return authorMapper.toDto(savedAuthor);
    }

    @Transactional
    public List<AuthorDto> addAuthors(List<AuthorDto> authorDtoList) {
        List<Author> authorList = authorMapper.toEntityList(authorDtoList);
        List<Author> savedAuthors = repository.saveAll(authorList);
        return authorMapper.toDtoList(savedAuthors);
    }

    @Transactional
    public void deleteAuthorById(Long id) {
        if (!repository.existsById(id)) {
            throw new EntityNotFoundException("Author not found");
        }
        repository.deleteById(id);
    }

    @Transactional
    public void updateAuthor(Long id, AuthorDto authorDto) {
        if (!repository.existsById(id)) {
            throw new EntityNotFoundException("Author not found");
        }
        Author author = authorMapper.toEntity(authorDto);
        author.setId(id); // Гарантуємо, що оновлюємо саме потрібний запис
        repository.save(author);
    }

    @Transactional
    public void patchAuthor(Long id, AuthorDto authorDto) {
        Author existing = repository.findById(id)
            .orElseThrow(() -> new EntityNotFoundException("Author not found"));

        authorMapper.updateEntityFromDto(authorDto, existing);
        
        repository.save(existing);
    }
}
